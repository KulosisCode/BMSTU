#ifndef POINT_H
#define POINT_H

#include <cassert>

struct point_t
{
    double x, y;
    point_t(double x = 0, double y = 0);

    double &operator[](int i);
};

#endif // POINT_H
