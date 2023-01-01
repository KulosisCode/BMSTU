#ifndef PAINTER_H
#define PAINTER_H

//#include "ui_mainwindow.h"
#include <QGraphicsView>
#include "points.h"

typedef QGraphicsScene* scene_type;

struct painter_t
{
    scene_type scene;
    double width;
    double height;
};

int painter_clear_screen(const painter_t &painter);

int painter_draw_edge(const painter_t &painter, const point_t &point_1, const point_t &point_2);

#endif // PAINTER_H
