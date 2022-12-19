#include "ecc.h"

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

bool EllipticCurveCryptography::FieldElement::operator==(std::shared_ptr<FieldElement> other) {
  if (other == nullptr) return false;

  return other->number == this->number && other->prime == this->prime;
}

bool EllipticCurveCryptography::FieldElement::operator!=(std::shared_ptr<FieldElement> other) { return !(other.get() == this); }

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

void EllipticCurveCryptography::FieldElement::PrintFieldElement() {
  std::cout << "FieldElement: Number: " << this->number << " Prime: " << this->prime << std::endl;
}
