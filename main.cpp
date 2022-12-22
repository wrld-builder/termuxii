#include "ecc.h"
#include "exceptions.h"

#if DEBUG
#include <iostream>
#endif

using EllipticCurveCryptography::FieldElement;
using EllipticCurveCryptography::Point;

int main() {
  auto p1 = std::make_shared<Point>(Point(-1, -1, 5, 7));
  auto p2 = std::make_shared<Point>(Point(-1, 1, 5, 7));
  auto inf = std::make_shared<Point>(Point(NULL, NULL, 5, 7));

  auto res1 = *p1 + inf;
  res1->PrintPoint();

  auto res2 = *p1 + p2;
  res2->PrintPoint();
}