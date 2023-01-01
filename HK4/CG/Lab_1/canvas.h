#ifndef CANVAS_H
#define CANVAS_H
#include "ui_mainwindow.h"

typedef QGraphicsScene* scene_type;

struct canvas_t
{
    scene_type scene;
    double width;
    double height;
};

#endif // CANVAS_H
