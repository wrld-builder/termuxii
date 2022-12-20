#include <memory>

namespace EllipticCurveCryptography {

class FieldElement {
 public:
  explicit FieldElement(const int& number, const int& prime);

  ~FieldElement();

  bool operator==(std::shared_ptr<FieldElement> other);  // is equal two field elements

  bool operator!=(std::shared_ptr<FieldElement> other);  // is not equal two field elements

  std::shared_ptr<FieldElement> operator+(std::shared_ptr<FieldElement> other);  // addition of two field elements

  std::shared_ptr<FieldElement> operator-(std::shared_ptr<FieldElement> other);  // sub of two field elements

  std::shared_ptr<FieldElement> operator*(std::shared_ptr<FieldElement> other);  // multiply of two field elements

  std::shared_ptr<FieldElement> operator/(std::shared_ptr<FieldElement> other);  // truediv of two field elements

  std::shared_ptr<FieldElement> Pow(const int& exponent);  // pow the field element

  void PrintFieldElement();  // print object

 private:
  int number = 0;
  int prime = 0;

 protected:
  int trueDivModuleExp(const int& x, const int& y, const int& N);  // modeExp true div with %
};

}  // namespace EllipticCurveCryptography