#ifndef PAINTER_H
#define PAINTER_H

#include <QGraphicsView>
#include "errors.h"

typedef QGraphicsScene *scene_t;

struct painter_t
{
    scene_t scene;
    double height;
    double width;
};

int painter_clear_screen(const painter_t &painter);
#endif // PAINTER_H
