#include "ecc.h"
#include "exceptions.h"

#if DEBUG
#include <iostream>
#endif

using EllipticCurveCryptography::FieldElement;

int main() {
  auto a = std::make_shared<FieldElement>(3, 31);
  auto b = std::make_shared<FieldElement>(24, 31);

  auto c = *a / b;
  c->PrintFieldElement();

  auto x = std::make_shared<FieldElement>(17, 31);
  x->Pow(-3);
  x->PrintFieldElement();

  auto z = std::make_shared<FieldElement>(3, 13);
  auto y = std::make_shared<FieldElement>(1, 13);

  z = z->Pow(3);
  z->PrintFieldElement();
  y->PrintFieldElement();

  std::cout << (*z == y) << std::endl;
}