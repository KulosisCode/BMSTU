#include <stdlib.h>
#include <stdio.h>

#include "input.h"
#include "define.h"

int input_matrix(int*** matrix, int* row, int* col, FILE* f)
{
    int rc;
    if ((rc = fscanf(f, "%d %d", row, col)) != 2)
        return INPUT_ERROR;
    if (*row <= 0 || *col <= 0)
        return ROW_COL_VALUE_ERROR;
    if (*row != *col)
        return NOT_SQUARE_MATRIX;

    int** data = malloc(*row * sizeof(int*));
    if (data == NULL)
        return MALLOC_ERROR;

    for (int i = 0; i < *row; i++)
    {
        int* q = malloc(*col * sizeof(int));
        if (q == NULL)
        {
            for (int j = 0; j < i; j++)
                free(data[j]);
            free(data);
            return MALLOC_ERROR;
        }
        for (int j = 0; j < *col; j++)
        {
            if ((rc = fscanf(f, "%d", q + j)) != 1)
            {
                free(q);
                for (int k = 0; k < i; k++)
                    free(data[k]);
                free(data);
                return INPUT_ERROR;
            }
        }
        data[i] = q;
    }
    *matrix = data;
    return EXIT_SUCCESS;
}

void free_matrix(int** matrix, const int row)
{
    for (int i = 0; i < row; i++)
        free(matrix[i]);
    free(matrix);
}