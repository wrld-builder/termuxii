#include "ecc.h"
#include "exceptions.h"

#if DEBUG
#include <iostream>
#endif

using EllipticCurveCryptography::FieldElement;
using EllipticCurveCryptography::Point;

int main() {
  auto p1 = Point(-1, -1, 5, 7);
  auto p2 = Point(-1, -2, 5, 7);
}