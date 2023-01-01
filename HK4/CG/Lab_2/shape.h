#ifndef SHAPE_H
#define SHAPE_H

#include <QTableWidget>
#include "errors.h"
#include "painter.h"
#include "dot.h"


#define SCENE_WIDTH 950
#define SCENE_HEIGHT 750

struct circle_t
{
    double a;
    double b;
    double r_a;
    double r_b;
};

struct parabol_t
{
    double c;
    double d;
    dot_t *arr;
    int count;
};

struct shape_t
{
    circle_t circle;
    parabol_t parabol;
    dot_t center;
};

//circle
int circle_init(circle_t &circle, const double a, const double b, const double r_a, const double r_b);
int circle_check(const circle_t &circle);
int circle_read(circle_t &circle, FILE *file);
int circle_input(circle_t &circle, FILE *file);
int circle_move(circle_t &circle, const moving_t &move);
int circle_scale(circle_t &circle, const scaling_t &scale);
int circle_rotate(circle_t &circle, rotating_t rotate, const dot_t &center);
int painter_draw_circle(const circle_t &circle, const painter_t &painter);

//parabol
int parabol_init(parabol_t &parabol, const double c, const double d);
double parabol_get_value(const double &y, const parabol_t &parabol);
int parabol_make(parabol_t &parabol);
int parabol_check(const parabol_t &parabol);
void parabol_free(parabol_t &parabol);
int parabol_input(parabol_t &parabol, FILE *file);
int parabol_make(parabol_t &parabol);
int parabol_move(parabol_t &parabol, const moving_t &move);
int parabol_scale(parabol_t &parabol, const scaling_t &scale, const dot_t &center);
int parabol_rotate(parabol_t &parabol, rotating_t rotate, const dot_t &center);
int parabol_draw(const parabol_t &parabol, const painter_t &painter);

//shape
shape_t &shape_init(void);
void shape_free(shape_t &shape);
int shape_check(const shape_t &shape);
int shape_find_center(shape_t &shape);
int shape_download(shape_t &shape, const char *file_name);
int shape_draw(const shape_t &shape, const painter_t &painter);
int shape_move(shape_t &shape, const moving_t &move);
int shape_scale(shape_t &shape, const scaling_t &scale);
int shape_rotate(shape_t &shape, const rotating_t &rotate);
#endif // SHAPE_H
