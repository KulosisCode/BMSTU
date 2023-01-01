#include "header.h"

void free_matrix_only(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    
    free(matrix);
}

void free_matrix(matrix *mtr, int n)
{
    for (int i = 0; i < n; i++)
        free(mtr->matrix[i]);
    
    free(mtr->matrix);
}


void free_sparse(sparse_matrix *mtr)
{
    free(mtr->num);
    free(mtr->cols);
    free(mtr->rows);
}