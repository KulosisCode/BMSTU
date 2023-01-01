#include "edges.h"

int edges_list_begin(edges_list_t &edges_list, edge_t * const array, const int &count)
{
    edges_list.array = array;
    edges_list.count = count;
    return OK;
}

int edges_list_check_array(const edges_list_t &edges_list)
{
    if (!edges_list.array || !edges_list.count)
    {
        return ERR_NO_EDGE;
    }
    return OK;
}


int edges_list_free_array(edges_list_t &edges_list)
{
    if (edges_list.array)
        free(edges_list.array);
    edges_list.count = 0;
    return OK;
}

int edges_list_read_count(edges_list_t &edges_list, FILE *file)
{
    int count = 0;

    if (fscanf(file, "%d", &count) !=1)
    {
        return ERR_INPUT;
    }

    if (count < 1)
    {
        return ERR_AMOUNT_EDGES;
    }

    edges_list.count = count;

    return OK;
}

int edges_list_allocate_array(edges_list_t &edges_list)
{
    edge_t *tmp_arr = (edge_t *) malloc (edges_list.count * sizeof(edge_t));
    if (!tmp_arr)
    {
        return ERR_MEMORY;
    }

    edges_list.array = tmp_arr;

    return OK;
}

int array_read_edges(edge_t *array_edge, const int &count, FILE *file)
{
    if (!array_edge)
    {
        return ERR_NO_EDGE;
    }

    if (!file)
    {
        return ERR_FILE;
    }

    int rc = OK;
    for(int i = 0; (i < count) && (rc == OK); i++)
    {
        if (fscanf(file, "%d %d", &array_edge[i].point_1, &array_edge[i].point_2) != 2)
        {
            rc = ERR_INPUT;
        }
    }
    return rc;
}

int edges_list_read_array(edges_list_t &edges_list, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    int rc = array_read_edges(edges_list.array, edges_list.count, file);

    return rc;
}

int edges_list_input(edges_list_t &edges_list, FILE *file)
{
    if (!file)
    {
        return ERR_FILE;
    }

    int rc = edges_list_read_count(edges_list, file);
    if (rc == OK)
    {
        rc = edges_list_allocate_array(edges_list);
        if (rc == OK)
        {
            rc = edges_list_read_array(edges_list, file);
            if (rc != OK)
            {
                edges_list_free_array(edges_list);
            }
        }
    }

    return rc;
}

int edges_array_output(const edge_t *array_edges, const int &count, FILE *file)
{
    if(!file)
    {
        return ERR_FILE;
    }

    if (!array_edges)
    {
        return ERR_NO_EDGE;
    }

    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d %d\n", array_edges[i].point_1, array_edges[i].point_2);
    }

    return OK;
}

int edges_list_output(FILE *file, const edges_list_t &edges_list)
{
    if (!file)
    {
        return ERR_FILE;
    }

    int rc = edges_array_output(edges_list.array, edges_list.count, file);

    return rc;
}

int edge_draw(const edge_t &edge, const point_t * const point_arr, const painter_t &painter)
{
    if (!point_arr)
    {
        return ERR_NO_POINT;
    }

    point_t point_1 = point_arr[edge.point_1];
    point_t point_2 = point_arr[edge.point_2];

    int rc = painter_draw_edge(painter, point_1, point_2);

    return rc;
}

int edges_list_draw(const edges_list_t &edges_list, const points_list_t &points_list, const painter_t &painter)
{
    int rc = OK;

    for (int i = 0; (rc == OK) && (i < edges_list.count); i++)
    {
        rc = edge_draw(edges_list.array[i], points_list.array, painter);
    }

    return rc;
}
