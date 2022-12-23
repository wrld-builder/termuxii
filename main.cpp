#include "ecc.h"
#include "exceptions.h"

#if DEBUG
#include <cmath>
#include <iostream>
#endif

using EllipticCurveCryptography::FieldElement;
using EllipticCurveCryptography::Point;

int main() {
  auto p1 = std::make_shared<Point>(Point(-1, -1, 5, 7));
  auto p2 = std::make_shared<Point>(Point(-1, -1, 5, 7));
  auto inf = std::make_shared<Point>(Point(NULL, NULL, 5, 7));

  auto res = *p1 + p2;
  res->PrintPoint();

  long double a = 5;
  long double x1 = -1;
  long double y1 = -1;

  auto s = (3 * std::pow(x1, 2) + a) / (2 * y1);
  auto x3 = std::pow(s, 2) - 2 * x1;
  auto y3 = s * (x1 - x3) - y1;

  std::cout << x3 << " " << y3 << std::endl;
}