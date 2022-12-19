#include <memory>

namespace EllipticCurveCryptography {

class FieldElement {
 public:
  explicit FieldElement(const int& number, const int& prime);

  ~FieldElement();

  bool operator==(std::shared_ptr<FieldElement> other);  // is equal two field elements

  bool operator!=(std::shared_ptr<FieldElement> other);  // is not equal two field elements

  std::shared_ptr<FieldElement> operator+(std::shared_ptr<FieldElement> other);  // addition of two field elements

  void PrintFieldElement();  // print object

 private:
  int number = 0;
  int prime = 0;
};

}  // namespace EllipticCurveCryptography