#include "shape.h"

int parabol_init(parabol_t &parabol, const double c, const double d)
{
    parabol.c = c;
    parabol.d = d;
    parabol.arr = NULL;
    parabol.count = 1000;
    return OK;
}

double parabol_get_value(const double &y,const parabol_t &parabol)
{
    double x = parabol.c + (y - parabol.d) * (y - parabol.d);

    return x;
}


int parabol_make(parabol_t &parabol)
{
    dot_t *tmp_arr = (dot_t *) malloc ( (parabol.count + 1) *sizeof (dot_t));
    if (!tmp_arr)
        return ERR_MEMORY;
    for (int i = 0; i < (parabol.count); i++)
    {
        tmp_arr[i].y = (i - (parabol.count / 2)) / 2;
        tmp_arr[i].x = parabol_get_value(tmp_arr[i].y, parabol);
    }
    parabol.arr = tmp_arr;
    return OK;
}

void parabol_free(parabol_t &parabol)
{
    if (parabol.arr)
    {
        free(parabol.arr);
    }
}

int parabol_check(const parabol_t &parabol)
{
    if (!parabol.arr)
    {
        return ERR_NO_DATA;
    }
    return OK;
}

int parabol_input(parabol_t &parabol, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    if (fscanf(file, "%lf %lf", &parabol.c, &parabol.d) != 2)
    {
        return ERR_INPUT;
    }
    int rc = parabol_make(parabol);

    return rc;
}




int parabol_move(parabol_t &parabol, const moving_t &move)
{
    if (!parabol.arr)
    {
        return ERR_NO_DATA;
    }

    for (int i = 0; i < parabol.count; i++)
    {
        dot_move(parabol.arr[i], move);
    }

    return OK;
}


int parabol_scale(parabol_t &parabol, const scaling_t &scale, const dot_t &center)
{
    if (!parabol.arr)
    {
        return ERR_NO_DATA;
    }
    for (int i = 0; i < parabol.count; i++)
    {
        dot_scale(parabol.arr[i], scale, center);
    }
    return OK;
}



int parabol_rotate(parabol_t &parabol, rotating_t rotate, const dot_t &center)
{
    if (!parabol.arr)
    {
        return ERR_NO_DATA;
    }
    for (int i = 0;  i < parabol.count; i++)
    {
        dot_rotate(parabol.arr[i], rotate, center);
    }
    return OK;
}

int parabol_draw(const parabol_t &parabol, const painter_t &painter)
{
    for (int i = 0; i < parabol.count - 1; i++)
    {
        painter.scene->addLine(
                    parabol.arr[i].x + painter.width / 2,
                    parabol.arr[i].y + painter.height /2,
                    parabol.arr[i + 1].x + painter.width / 2,
                    parabol.arr[i + 1].y + painter.height /2);
    }
    return OK;
}
