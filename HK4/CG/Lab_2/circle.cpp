#include "shape.h"

int circle_init(circle_t &circle, const double a, const double b, const double r_a, const double r_b)
{
    circle.a = a;
    circle.b = b;
    circle.r_a = r_a;
    circle.r_b = r_b;

    return OK;
}

int circle_check(const circle_t &circle)
{
    if (circle.r_a <= 0 || circle.r_b <= 0)
    {
        return ERR_PARAM;
    }

    return OK;
}

int circle_read(circle_t &circle, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    if (fscanf(file, "%lf %lf %lf", &circle.a, &circle.b, &circle.r_a) != 3)
    {
        return ERR_INPUT;
    }
    else
    {
        circle.r_b =circle.r_a;
    }

    return OK;
}

int circle_input(circle_t &circle, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    int rc = circle_read(circle, file);
    if (rc == OK)
        rc = circle_check(circle);

    return rc;
}

int circle_move(circle_t &circle, const moving_t &move)
{
    circle.a += move.dx;
    circle.b += move.dy;

    return OK;
}

int circle_scale(circle_t &circle, const scaling_t &scale)
{
    circle.r_a *= scale.kx;
    circle.r_b *= scale.ky;

    return OK;
}

int circle_rotate(circle_t &circle, rotating_t rotate, const dot_t &center)
{
    int rc = to_radians(rotate);
    if (rc == OK)
    {
        double sin_r, cos_r;
        double tmp;
        cos_r = cos(rotate.alpha);
        sin_r = sin(rotate.alpha);
        tmp = circle.a;

        circle.a = (center.x +
                    (circle.a - center.x) * cos_r +
                    (circle.b - center.y) * sin_r);

        circle.b = (center.y -
                    (tmp - center.x) * sin_r +
                    (circle.b - center.y) * cos_r);
    }
    return rc;
}

int painter_draw_circle(const circle_t &circle, const painter_t &painter)
{
    painter.scene->addEllipse(QRectF(circle.a - circle.r_a + painter.width / 2,
                                     circle.b - circle.r_b + painter.height / 2,
                                     2 * circle.r_a ,
                                     2 * circle.r_b));
    painter.scene->addEllipse(QRectF(circle.a + painter.width / 2,
                                     circle.b + painter.height / 2,
                                     2 ,2 ),QPen(Qt::red), QBrush(Qt::SolidPattern));
    painter.scene->addText(QString("(" + QString::number(circle.a) + ";"
                                       + QString::number(circle.b) + ")"));
    return OK;
}



















