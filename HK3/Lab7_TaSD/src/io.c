#include "io.h"

int get_graph(graph_t *graph, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        printf("\nERROR READING FILE!\n");
        return ERR_READ;
    }

    int code = fscanf(file, "%d", &graph->size);

    if (!code || graph->size < MIN_NODES || graph->size > INT_MAX - 1)
    {
        printf("\nThe number of cities incorrectly!\n");
        return ERR_READ;
    }

    code = graph_create(graph);

    if (code)
    {
        printf("\nERROR ALLOCATE!\n");
        return code;
    }

    for (int i = 0; i < graph->size; i++)
    {
        for (int j = 0; j < graph->size; j++)
        {
            if (fscanf(file, "%d", &graph->matrix[i][j]) != 1 || graph->matrix[i][j] < 0)
            {
                printf("ERROR INPUT!");
                return ERR_READ;
            }
        }
    }

    fclose(file);

    return OK;
}


void print_graph(int **matrix, const int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%5d ", matrix[i][j]);
        
        printf("\n");
    }
}

void print_conditions(void)
{
    printf("%s",
           "\nПрограмма предназначена для работы с графом. Граф:\n"
           "\n - связный\n"
           "\n - взвешенный\n"
           "\n - с положительными весами ребер\n"
           "\n - неориентированный\n"
           "\nДля системы двусторонних дорог, соединяющих города, программа\n"
           "\nнаходит город с минимальной суммой расстояний до других городов\n"
           "\nпри помощи алгоритма Дейкстры.\n");
}