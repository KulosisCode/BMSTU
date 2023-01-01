#include "shape.h"

shape_t &shape_init(void)
{
    static shape_t shape;
    circle_init(shape.circle, 0, 0, 0, 0);
    parabol_init(shape.parabol, 0, 0);

    return shape;
}

void shape_free(shape_t &shape)
{
    parabol_free(shape.parabol);
}

int shape_check(const shape_t &shape)
{
    int rc = parabol_check(shape.parabol);
    if (rc == OK)
    {
        rc = circle_check(shape.circle);
    }

    return rc;
}

// get center
int shape_find_center(shape_t &shape)
{
    int rc = shape_check(shape);
    if (rc == OK)
    {
        shape.center.x = (shape.circle.a + shape.parabol.c) / 2;
        shape.center.y = (shape.circle.b + shape.parabol.d) / 2;
    }

    return rc;
}

int shape_download(shape_t &shape, const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (!file)
    {
        return ERR_FILE;
    }

    shape_t tmp_shape = shape_init();

    int rc = circle_input(tmp_shape.circle, file);
    if (rc == OK)
    {
        rc = parabol_input(tmp_shape.parabol, file);
        if (rc == OK)
        {
            shape_find_center(tmp_shape);
            shape = tmp_shape;
        }
    }

    fclose(file);
    return rc;

}


int shape_draw(const shape_t &shape, const painter_t &painter)
{
    int rc = shape_check(shape);
    if (rc == OK)
    {
        rc = painter_clear_screen(painter);
        if (rc == OK)
        {
            painter_draw_circle(shape.circle, painter);
            parabol_draw(shape.parabol, painter);
        }
    }

    return rc;
}



int shape_move(shape_t &shape, const moving_t &move)
{
    int rc = shape_check(shape);
    if (rc == OK)
    {
        rc = circle_move(shape.circle, move);
        if (rc == OK)
        {
            rc = parabol_move(shape.parabol, move);
            if (rc == OK)
            {
                dot_move(shape.center, move);
            }
        }

    }

    return rc;
}

int shape_scale(shape_t &shape, const scaling_t &scale)
{
    int rc = shape_check(shape);
    if (rc == OK)
    {
        rc = circle_scale(shape.circle, scale);
        if (rc == OK)
        {
            rc = parabol_scale(shape.parabol, scale, shape.center);
        }
    }

    return rc;
}


int shape_rotate(shape_t &shape, const rotating_t &rotate)
{
    int rc = shape_check(shape);
    if (rc == OK)
    {
        rc = circle_rotate(shape.circle, rotate, shape.center);
        if (rc == OK)
        {
            rc = parabol_rotate(shape.parabol, rotate, shape.center);
        }
    }

    return rc;
}


