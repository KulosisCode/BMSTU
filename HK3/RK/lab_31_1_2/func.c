#include "header.h"

int read_file(FILE *file, int **mtr, int *a, int *b)
{
    int rows, cols;
    int x = 0;
    if (fscanf(file, "%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
    {
        printf("ERROR READING : SIZE MATRIX.\n");
        return ERR_READ;
    }
    else 
    {
        *a = rows;
        *b = cols;
        mtr = (int**) calloc(rows, sizeof(int*));
        if (!mtr)
        {
            printf("ERROR ALLOCATE.");
            return ERR_ALLOCATE;
        }
        for (int i = 0; i < rows; i++)
        {
            mtr[i] = calloc(cols, sizeof(int));
            if (!mtr[i])
            {
                printf("ERROR ALLOCATE.");
                free_mtr(mtr, rows);
                return ERR_ALLOCATE;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (fscanf(file,"%d",&x) == 1)
                {
                    mtr[i][j] = x;
                }
                else 
                {
                    printf("ERROR READING.");
                    free_mtr(mtr, rows);
                    return ERR_READ;
                }
            }
        }
    }
    return OK;
}

int process(int **mtr, int const *rows, int const *cols)
{
    if (!mtr || *rows <= 0 || *cols <= 0)
    {
        printf("ERROR PARAM.");
        return ERR_PARAM;
    }
    int flags = 0;
    int col, row;
    col = *cols;
    row = *rows;
    int res = 0;
    for (int i = row - 1 ; i > 0; i--)
    {
        for (int j = col - 1 ; j > res; j--)
        {
            if (mtr[i][j] % 10 == 5)
            {
                printf("%d ", mtr[i][j]);
                flags++;
            }
        }
        res++;
    }
    if (flags == 0)
    {
        printf("NO NUMBER WITH ENDING SYMBOL IS 5.\n");
    }
    return OK;
}

void free_mtr(int **mtr, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(mtr[i]);
    }
    free(mtr);
}