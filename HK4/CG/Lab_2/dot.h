#ifndef DOT_H
#define DOT_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

struct dot_t
{
    double x;
    double y;
};

struct moving_t
{
    double dx;
    double dy;
};

struct scaling_t
{
    double kx;
    double ky;
};

struct rotating_t
{
    double alpha;
};

int to_radians(rotating_t &rotate);

void dot_move(dot_t &dot, const moving_t &move);

void dot_scale(dot_t &dot, const scaling_t &scale, const dot_t &center);

void dot_rotate(dot_t &dot, rotating_t rotate, const dot_t &center);

#endif // DOT_H
