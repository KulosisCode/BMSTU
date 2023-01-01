#include "dot.h"

int to_radians(rotating_t &rotate)
{
    rotate.alpha *= (M_PI / 180);

    return OK;
}

void dot_move(dot_t &dot, const moving_t &move)
{
    dot.x += move.dx;
    dot.y += move.dy;
}

void dot_scale(dot_t &dot, const scaling_t &scale, const dot_t &center)
{
    dot.x = scale.kx * dot.x + center.x * (1 - scale.kx);
    dot.y = scale.ky * dot.y + center.y * (1 - scale.ky);
}

void dot_rotate(dot_t &dot, rotating_t rotate, const dot_t &center)
{
    to_radians(rotate);

    double sin_r, cos_r;
    double tmp;
    cos_r = cos(rotate.alpha);
    sin_r = sin(rotate.alpha);
    tmp = dot.x;

    dot.x = (center.x +
                (dot.x - center.x) * cos_r +
                (dot.y - center.y) * sin_r);

    dot.y = (center.y -
                (tmp - center.x) * sin_r +
                (dot.y - center.y) * cos_r);

}
