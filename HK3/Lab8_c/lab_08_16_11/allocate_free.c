#include "io.h"

double **allocate_matrix(int n, int m)
{
    double **matrix = calloc(n, sizeof(double*));
    if (!matrix)
        return ((void*)0);

    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(m * sizeof(double));
        if (!matrix[i])
        {
            free_matrix(matrix, n);
            return ((void*)0);
        }
    }
    return matrix;
}

void free_matrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}