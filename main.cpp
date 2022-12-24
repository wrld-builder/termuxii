#include "ecc.h"
#include "exceptions.h"

#if DEBUG
#include <cmath>
#include <iostream>
#endif

using EllipticCurveCryptography::FieldElement;
using EllipticCurveCryptography::Point;

int main() {
  auto a = std::make_shared<FieldElement>(0, 223);
  auto b = std::make_shared<FieldElement>(7, 223);

  ///////////////////////////////////////////////

  auto x1 = std::make_shared<FieldElement>(170, 223);
  auto y1 = std::make_shared<FieldElement>(142, 223);
  auto p1 = std::make_shared<Point>(x1, y1, a, b);

  auto x2 = std::make_shared<FieldElement>(60, 223);
  auto y2 = std::make_shared<FieldElement>(139, 223);
  auto p2 = std::make_shared<Point>(x2, y2, a, b);

  auto c1 = *p1 + p2;
  c1->PrintPoint();

  ///////////////////////////////////////////////

  auto x3 = std::make_shared<FieldElement>(47, 223);
  auto y3 = std::make_shared<FieldElement>(71, 223);
  auto p3 = std::make_shared<Point>(x3, y3, a, b);

  auto x4 = std::make_shared<FieldElement>(17, 223);
  auto y4 = std::make_shared<FieldElement>(56, 223);
  auto p4 = std::make_shared<Point>(x4, y4, a, b);

  auto c2 = *p3 + p4;
  c2->PrintPoint();

  ///////////////////////////////////////////////

  auto x5 = std::make_shared<FieldElement>(143, 223);
  auto y5 = std::make_shared<FieldElement>(98, 223);
  auto p5 = std::make_shared<Point>(x5, y5, a, b);

  auto x6 = std::make_shared<FieldElement>(76, 223);
  auto y6 = std::make_shared<FieldElement>(66, 223);
  auto p6 = std::make_shared<Point>(x6, y6, a, b);

  auto c3 = *p5 + p6;
  c3->PrintPoint();
}