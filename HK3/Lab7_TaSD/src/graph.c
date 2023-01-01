#include "graph.h"

int get_index_min(int *distances, char *go_through, const int size)
{
    int min = INT_MAX;
    int index_min;

    for (int i = 0; i < size; i++)
    {
        if (go_through[i] == 0 && distances[i] <= min)
        {
            min = distances[i];
            index_min = i;
        }
    }

    return index_min;
}

int Method_Dijkstra(graph_t *graph, const int start)
{
    char *go_through = calloc(graph->size, sizeof(char));

    for (int i = 0; i < graph->size; i++)
    {
        graph->road[start][i] = INT_MAX;
    }

    graph->road[start][start] = 0;

    for (int i = 0; i < graph->size; i++)
    {
        int index_min = get_index_min(graph->road[start], go_through, graph->size);
       go_through[index_min] = 1;

        for (int j = 0; j < graph->size; j++)
        {
            if (!go_through[j] && graph->matrix[index_min][j] && graph->road[start][index_min] != INT_MAX
                && graph->road[start][index_min] + graph->matrix[index_min][j] < graph->road[start][j])
                graph->road[start][j] = graph->road[start][index_min] + graph->matrix[index_min][j];
        }
    }

    for (int i = 0; i < graph->size; i++)
    {
        if (graph->road[start][i] == INT_MAX)
        {
            printf("\nThe graph is not connected!\n");
            free(go_through);
            return ERR_GRAPH;
        }
    }

    free(go_through);

    return OK;
}


int get_best_way(graph_t *graph, int *best_index)
{
    for (int i = 0; i < graph->size; i++)
    {
        if (Method_Dijkstra(graph, i))
            return ERR_GRAPH;
    }

    int min_sum_path = 0, now_sum;
    *best_index = 0;

    for (int i = 0; i < graph->size; i++)
        min_sum_path += graph->road[0][i];
    
    for (int i = 0; i < graph->size; i++)
    {
        now_sum = 0;

        for (int j = 0; j < graph->size; j++)
            now_sum += graph->road[i][j];

        if (now_sum < min_sum_path)
        {
            min_sum_path = now_sum;
            *best_index = i;
        }
    }

    return OK;
}


void init_graph(graph_t *graph)
{
    graph->size = 0;
    graph->matrix = NULL;
    graph->road = NULL;
}

int graph_create(graph_t *graph)
{
    graph->matrix = calloc(graph->size, sizeof(int *));

    if (!(graph->matrix))
        return ERR_ALLOCATE;
    
    for (int i = 0; i < graph->size; i++)
    {
        (graph->matrix)[i] = calloc(graph->size, sizeof(int));

        if (!(graph->matrix)[i])
        {
            free_graph(graph);
            return ERR_ALLOCATE;
        }
    }

    return OK;
}

void free_graph(graph_t *graph)
{
    for (int i = 0; i < graph->size; i++)
    {
        free(graph->matrix[i]);
        free(graph->road[i]);
    }
    free(graph->matrix);
    free(graph->road);
}