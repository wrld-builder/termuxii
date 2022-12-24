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

  auto x1 = std::make_shared<FieldElement>(192, 223);
  auto y1 = std::make_shared<FieldElement>(105, 223);
  auto p1 = std::make_shared<Point>(x1, y1, a, b);
  p1->PrintPoint();

  auto x2 = std::make_shared<FieldElement>(17, 223);
  auto y2 = std::make_shared<FieldElement>(56, 223);
  auto p2 = std::make_shared<Point>(x2, y2, a, b);
  p2->PrintPoint();

  // auto x3 = std::make_shared<FieldElement>(200, 223);
  // auto y3 = std::make_shared<FieldElement>(119, 223);
  // auto p3 = std::make_shared<Point>(x3, y3, a, b);

  auto x4 = std::make_shared<FieldElement>(1, 223);
  auto y4 = std::make_shared<FieldElement>(193, 223);
  auto p4 = std::make_shared<Point>(x4, y4, a, b);
  p4->PrintPoint();

  // auto x5 = std::make_shared<FieldElement>(42, 223);
  // auto y5 = std::make_shared<FieldElement>(99, 223);
  // auto p5 = std::make_shared<Point>(x5, y5, a, b);
  // p5->PrintPoint();
}