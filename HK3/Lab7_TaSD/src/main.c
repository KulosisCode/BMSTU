#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "io.h"
#include "graph.h"
#include "export.h"


int main(int argc, char **argv)
{
    print_conditions();

    graph_t graph;
    init_graph(&graph);

    int rc;
    if (argc == ARGS)
    {
        rc = get_graph(&graph, argv[1]);
        if (rc != OK)
            return rc;
    }
    else
    {
        printf("\nERROR ARGS\n");
        return ERR_ARGS;
    }

    graph.road = calloc(graph.size, sizeof(int *));

    if (!graph.road)
        return ERR_ALLOCATE;
    
    for (int i = 0; i < graph.size; i++)
    {
        graph.road[i] = calloc(graph.size, sizeof(int));

        if (!graph.road[i])
        {
            free_graph(&graph);
            return ERR_ALLOCATE;
        }
    }

    printf("\nМатрица смежности:\n");
    print_graph(graph.matrix, graph.size);
    visual_graph(graph.matrix, graph.size, "START", "start.dot", INT_MAX);

    int index_city;

    if (get_best_way(&graph, &index_city) == ERR_GRAPH)
        return ERR_GRAPH;
    
    printf("\nМатрица кратчайших расстояний:\n");
    print_graph(graph.road, graph.size);
    visual_graph(graph.road, graph.size, "RESULT", "result.dot", index_city + 1);

    printf("\nГород с минимальной суммой расстояний до других городов: %d\n\n", index_city + 1);

    system("dot -Tpng start.dot -o start.png");
    system("dot -Tpng result.dot -o result.png");

    free_graph(&graph);

    return OK;
}