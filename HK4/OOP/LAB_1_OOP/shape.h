#ifndef SHAPE_H
#define SHAPE_H

//#include "ui_mainwindow.h"
#include "error.h"
#include "points.h"
#include "edges.h"
#include "painter.h"

struct shape_t
{
    points_list_t points;
    edges_list_t edges;
    point_t center;
};

int shape_init_null(shape_t &shape);

shape_t &shape_init(void);

int shape_free(shape_t &shape);

int shape_find_center(point_t &center, const points_list_t &points_list);

int shape_process_download(shape_t &shape, FILE *file);

int shape_download(shape_t &shape, const char *file_name);

int shape_check_arrays(const points_list_t &points_list, const edges_list_t &edges_list);

int shape_upload(const shape_t& shape, const char *file_name);

int shape_draw(const shape_t& shape, const painter_t &painter);

int shape_move(shape_t& shape, const move_info_t& moving);

int shape_scale(shape_t& shape, const scale_info_t &scale);

int shape_rotate(shape_t& shape, const rotate_info_t &rotate);

#endif // SHAPE_H
