#include "point.h"

point_t::point(double x, double y) : x(x), y(y) {}

double &point::operator[](int i) {
  assert(i == 0 || i == 1);
  return i ? y : x;
}
