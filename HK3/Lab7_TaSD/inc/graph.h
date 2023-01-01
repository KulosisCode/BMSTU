#ifndef _GRAPH_T_
#define _GRAPH_T_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "constants.h"

typedef struct
{
    int size;
    int **matrix;
    int **road;
} graph_t;

void init_graph(graph_t *graph);

int graph_create(graph_t *graph);

void free_graph(graph_t *graph);

int get_index_min(int *distances, char *go_through, const int size);

int Method_Dijkstra(graph_t *graph, const int start);

int get_best_way(graph_t *graph, int *best_index);

#endif