#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>
#include "graph.h"
#include "constants.h"

void print_conditions(void);

int get_graph(graph_t *graph, const char *filename);

void print_graph(int **graph, const int size);

#endif