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
}