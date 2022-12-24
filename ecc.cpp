#include "ecc.h"

#include <cmath>

#include "exceptions.h"

#if DEBUG
#include <iostream>
#endif

EllipticCurveCryptography::FieldElement::FieldElement(const int& number, const int& prime) {
  try {
    if (number >= prime) throw OverrideExceptions::NumberNotInField();

    this->number = number;
    this->prime = prime;
  } catch (OverrideExceptions::NumberNotInField& exception) {
#if DEBUG
    std::cerr << exception.what() << std::endl;
#endif
    std::exit(EXCEPTION_NUMBER_NOT_IN_FIELD_CODE);
  }
}

EllipticCurveCryptography::FieldElement::~FieldElement() {}

bool EllipticCurveCryptography::FieldElement::operator==(const std::shared_ptr<FieldElement> other) {
  if (other == nullptr) return false;

  return other->number == this->number && other->prime == this->prime;
}

bool EllipticCurveCryptography::FieldElement::operator!=(const std::shared_ptr<FieldElement> other) { return !(other.get() == this); }

std::shared_ptr<EllipticCurveCryptography::FieldElement> EllipticCurveCryptography::FieldElement::operator+(
    std::shared_ptr<EllipticCurveCryptography::FieldElement> other) {
  try {
    if (this->prime != other->prime) throw OverrideExceptions::AdditionInDifferentFields();
  } catch (OverrideExceptions::AdditionInDifferentFields& exception) {
#if DEBUG
    std::cerr << exception.what() << std::endl;
#endif
    std::exit(EXCEPTION_ADD_IN_DIFF_FIELDS_CODE);
  }

  return std::make_shared<FieldElement>((this->number + other->number) % this->prime, this->prime);
}

std::shared_ptr<EllipticCurveCryptography::FieldElement> EllipticCurveCryptography::FieldElement::operator-(
    const std::shared_ptr<FieldElement> other) {
  try {
    if (this->prime != other->prime) throw OverrideExceptions::SubInDifferentFields();
  } catch (OverrideExceptions::SubInDifferentFields& exception) {
#if DEBUG
    std::cerr << exception.what() << std::endl;
#endif
    std::exit(EXCEPTION_SUB_IN_DIFF_FIELDS_CODE);
  }

  if ((this->number - other->number) % this->prime >= 0) {
    return std::make_shared<FieldElement>((this->number - other->number) % this->prime, this->prime);
  } else {
    return std::make_shared<FieldElement>(this->prime - std::abs(this->number - other->number), this->prime);
  }
}

std::shared_ptr<EllipticCurveCryptography::FieldElement> EllipticCurveCryptography::FieldElement::operator*(
    const std::shared_ptr<FieldElement> other) {
  try {
    if (this->prime != other->prime) throw OverrideExceptions::MulInDifferentFields();
  } catch (OverrideExceptions::MulInDifferentFields& exception) {
#if DEBUG
    std::cerr << exception.what() << std::endl;
#endif
    std::exit(EXCEPTION_MUL_IN_DIFF_FIELDS_CODE);
  }

  return std::make_shared<FieldElement>((this->number * other->number) % this->prime, this->prime);
}

std::shared_ptr<EllipticCurveCryptography::FieldElement> EllipticCurveCryptography::FieldElement::operator/(
    const std::shared_ptr<FieldElement> other) {
  try {
    if (this->prime != other->prime) throw OverrideExceptions::TrueDivInDifferentFields();
  } catch (OverrideExceptions::TrueDivInDifferentFields& exception) {
#if DEBUG
    std::cerr << exception.what() << std::endl;
#endif
    std::exit(EXCEPTION_TRUEDIV_IN_DIFF_FIELDS_CODE);
  }

  return std::make_shared<FieldElement>(
      this->number * static_cast<int>(trueDivModuleExp(other->number, this->prime - 2, this->prime)) % this->prime, this->prime);
}

std::shared_ptr<EllipticCurveCryptography::FieldElement> EllipticCurveCryptography::FieldElement::Pow(const int& exponent) {
  int N = exponent % (this->prime - 1);

  return std::make_shared<FieldElement>(trueDivModuleExp(this->number, N, this->prime), this->prime);
}

void EllipticCurveCryptography::FieldElement::PrintFieldElement() {
  std::cout << "FieldElement: Number: " << this->number << " Prime: " << this->prime << std::endl;
}

int EllipticCurveCryptography::FieldElement::trueDivModuleExp(const int& x, const int& y, const int& N) {
  if (y == 0) return 1;

  int z = trueDivModuleExp(x, y / 2, N);

  if (y % 2 == 0)
    return (z * z) % N;
  else
    return (x * z * z) % N;
}

EllipticCurveCryptography::Point::Point(const double& x, const double& y, const double& a, const double& b) {
  this->x = x;
  this->y = y;
  this->a = a;
  this->b = b;

  if (this->x == NULL && this->y == NULL) {
    this->isInfinity = true;
  } else {
    try {
      if (std::pow(y, 2) != std::pow(this->x, 3) + a * x + b) throw OverrideExceptions::PointNotOntheCurve();
    } catch (OverrideExceptions::PointNotOntheCurve& exception) {
#if DEBUG
      std::cerr << exception.what() << std::endl;
#endif
      std::exit(EXCEPTION_POINT_NOT_IN_THE_CURVE_CODE);
    }
  }
}

EllipticCurveCryptography::Point::Point(const std::shared_ptr<FieldElement> x, const std::shared_ptr<FieldElement> y,
                                        const std::shared_ptr<FieldElement> a, const std::shared_ptr<FieldElement> b) {
  this->xFieldElement = x;
  this->yFieldElement = y;
  this->aFieldElement = a;
  this->bFieldElement = b;
  this->isFieldElementUsage = true;

  if (this->xFieldElement == nullptr && this->yFieldElement == nullptr) {
    isInfinity = true;
  } else {
    try {
      auto leftPart = this->yFieldElement->Pow(2);

      auto rightPartBuffer = this->xFieldElement->Pow(3);
      auto rightDiffPart = *this->xFieldElement * a;
      rightPartBuffer = *rightPartBuffer + rightDiffPart;
      rightPartBuffer = *rightPartBuffer + b;

#if DEBUG
      std::cout << "Left part: " << leftPart->getNumber() << " Right part: " << rightPartBuffer->getNumber() << std::endl;
#endif

      // compare numbers of FieldElement, not objects!
      if (leftPart->getNumber() != rightPartBuffer->getNumber()) throw OverrideExceptions::PointNotOntheCurve();
    } catch (OverrideExceptions::PointNotOntheCurve& exception) {
#if DEBUG
      std::cerr << exception.what() << std::endl;
#endif
      std::exit(EXCEPTION_POINT_NOT_IN_THE_CURVE_CODE);
    }
  }
}

bool EllipticCurveCryptography::Point::operator==(const std::shared_ptr<Point> other) {
  return this->x == other->x && this->y == other->y && this->a == other->a && this->b == other->b;
}

bool EllipticCurveCryptography::Point::operator!=(const std::shared_ptr<Point> other) { return !(this == other.get()); }

std::shared_ptr<EllipticCurveCryptography::Point> EllipticCurveCryptography::Point::operator+(const std::shared_ptr<Point> other) {
  try {
    if (this->a != other->a || this->b != other->b) throw OverrideExceptions::PointNotOntheCurve();
  } catch (OverrideExceptions::PointNotOntheCurve& exception) {
#if DEBUG
    std::cerr << exception.what() << std::endl;
#endif
    std::exit(EXCEPTION_POINT_NOT_IN_THE_CURVE_CODE);
  }

  if (!this->isFieldElementUsage) {
    if (this->x == NULL && other->isInfinity) {  // other because we need to compare __smb__ + __inf__ (rule)
      return other;
    } else if (other->x == NULL && other->isInfinity) {
      return shared_from_this();
    } else if (this->x == other->x && this->y != other->y) {
      return std::make_shared<Point>(NULL, NULL, this->a, this->b);  // additional inverse
    } else if (this->x != other->x) {
      auto s = (other->y - this->y) / (other->x - this->x);
      auto xLocal = std::pow(s, 2) - this->x - other->x;
      auto yLocal = s * (this->x - xLocal) - this->y;

      return std::make_shared<Point>(xLocal, yLocal, this->a, this->b);
    } else if (*this == other && this->y == 0 * this->x) {
      return std::make_shared<Point>(NULL, NULL, this->a, this->b);
    } else if (*this == other) {
      int s = (int)(3 * std::pow(this->x, 2) + this->a) / (int)(2 * this->y);
      int xLocal = (int)std::pow(s, 2) - (int)2 * this->x;
      int yLocal = s * (this->x - xLocal) - this->y;

      return std::make_shared<Point>(xLocal, yLocal, this->a, this->b);
    }
  } else {
    if (this->xFieldElement == nullptr && other->isInfinity) {  // other because we need to compare __smb__ + __inf__ (rule)
      return other;
    } else if (other->xFieldElement == nullptr && other->isInfinity) {
      return shared_from_this();
    } else if (*this->xFieldElement == other->xFieldElement && *this->yFieldElement != other->yFieldElement) {
      return std::make_shared<Point>(NULL, NULL, this->a, this->b);  // additional inverse
    } else if (this->xFieldElement->getNumber() != other->xFieldElement->getNumber()) {
      auto s = *(*other->yFieldElement - this->yFieldElement) / (*other->xFieldElement - this->xFieldElement);
      auto xLocal = *(*s->Pow(2) - this->xFieldElement) - other->xFieldElement;
      auto yLocal = *(*s * (*this->xFieldElement - xLocal)) - this->yFieldElement;

      return std::make_shared<Point>(xLocal, yLocal, this->aFieldElement, this->bFieldElement);
    } else if (*this == other && *this->yFieldElement == std::make_shared<FieldElement>(0, this->xFieldElement->getPrime())) {
      return std::make_shared<Point>(nullptr, nullptr, this->aFieldElement, this->bFieldElement);
    } else if (*this == other) {
      auto s =
          *(*(*std::make_shared<FieldElement>(3, this->xFieldElement->getPrime()) * this->xFieldElement->Pow(2)) + this->aFieldElement) /
          (*std::make_shared<FieldElement>(2, this->xFieldElement->getPrime()) * this->yFieldElement);
      auto xLocal = *(*s->Pow(2) - std::make_shared<FieldElement>(2, this->xFieldElement->getPrime())) * this->xFieldElement;
      auto yLocal = *(*s * (*this->xFieldElement - xLocal)) - this->yFieldElement;

      return std::make_shared<Point>(xLocal, yLocal, this->aFieldElement, this->bFieldElement);
    }
  }
}

void EllipticCurveCryptography::Point::PrintPoint() {
  if (this->xFieldElement != nullptr || this->yFieldElement != nullptr) {
#if DEBUG
    std::cout << "Point: x: FieldElement(" << this->xFieldElement->getNumber() << ", " << this->xFieldElement->getPrime()
              << ") y: FieldElement(" << this->yFieldElement->getNumber() << ", " << this->yFieldElement->getPrime() << ") a: FieldElement("
              << this->aFieldElement->getNumber() << ", " << this->aFieldElement->getPrime() << ") b: FieldElement("
              << this->bFieldElement->getNumber() << ", " << this->bFieldElement->getPrime() << ")" << std::endl
              << std::endl;
#endif
  } else {
    if (this->x == NULL && this->y == NULL) {
#if DEBUG
      std::cout << "Point: infinity" << std::endl;
#endif
    } else {
#if DEBUG
      std::cout << "Point: x: " << this->x << " y: " << this->y << " a: " << this->a << " b: " << this->b << std::endl;
#endif
    }
  }
}
