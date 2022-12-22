#include <memory>

namespace EllipticCurveCryptography {

class FieldElement {
 public:
  explicit FieldElement(const int& number, const int& prime);

  ~FieldElement();

  bool operator==(const std::shared_ptr<FieldElement> other);  // is equal two field elements

  bool operator!=(const std::shared_ptr<FieldElement> other);  // is not equal two field elements

  std::shared_ptr<FieldElement> operator+(const std::shared_ptr<FieldElement> other);  // addition of two field elements

  std::shared_ptr<FieldElement> operator-(const std::shared_ptr<FieldElement> other);  // sub of two field elements

  std::shared_ptr<FieldElement> operator*(const std::shared_ptr<FieldElement> other);  // multiply of two field elements

  std::shared_ptr<FieldElement> operator/(const std::shared_ptr<FieldElement> other);  // truediv of two field elements

  std::shared_ptr<FieldElement> Pow(const int& exponent);  // pow the field element

  void PrintFieldElement();  // print object

 private:
  int number = 0;
  int prime = 0;

 protected:
  static int trueDivModuleExp(const int& x, const int& y, const int& N);  // modeExp true div with %
};

class Point : public std::enable_shared_from_this<Point> {
 public:
  explicit Point(const int& x, const int& y, const int& a, const int& b);

  inline ~Point(){};

  bool operator==(const std::shared_ptr<Point> other);

  bool operator!=(const std::shared_ptr<Point> other);

  std::shared_ptr<Point> operator+(const std::shared_ptr<Point> other);  // addition of two points

  void PrintPoint();  // print object

 private:
  int x = 0;  // X coordinate
  int y = 0;  // Y coordinate
  int a = 0;  // a coefficient
  int b = 0;  // b coefficient

  bool isInfinity = false;  // infinity point setter
};

}  // namespace EllipticCurveCryptography