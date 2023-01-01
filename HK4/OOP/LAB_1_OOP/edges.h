#ifndef EDGES_H
#define EDGES_H

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "points.h"
#include "painter.h"

struct edge_t
{
    int point_1;
    int point_2;
};

struct edges_list_t
{
    int count;
    edge_t *array;
};

int edges_list_begin(edges_list_t &edges_list, edge_t * const array, const int &count);

int edges_list_check_array(const edges_list_t &edges_list);

int edges_list_free_array(edges_list_t &edges_list);

int edges_list_read_count(edges_list_t &edges_list, FILE *file);

int edges_list_allocate_array(edges_list_t &edges_list);

int array_read_edges(edge_t *array_edge, const int &count, FILE *file);

int edges_list_read_array(edges_list_t &edges_list, FILE *file);

int edges_list_input(edges_list_t &edges_list, FILE *file);

int edges_array_output(const edge_t *array_edges, const int &count, FILE *file);

int edges_list_output(FILE *file, const edges_list_t &edges_list);

int edge_draw(const edge_t &edge, const point_t * const point_arr, const painter_t &painter);

int edges_list_draw(const edges_list_t &edges_list, const points_list_t &points_list, const painter_t &painter);

#endif // EDGES_H
