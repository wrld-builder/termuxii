#include "ecc.h"

#if DEBUG
#include <iostream>
#endif

using EllipticCurveCryptography::FieldElement;

int main() {
  auto a = std::make_shared<FieldElement>(33, 57);
  auto b = std::make_shared<FieldElement>(44, 57);

  auto c = *a.get() + b;
  c->PrintFieldElement();
}