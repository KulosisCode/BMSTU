#include "io.h"

int read_from_file(char *filename, double ***mtr, int *n, int *m)
{
    int n_t, m_t;
    double x;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file!");
        return ERR_OPEN;
    }
    else
    {
        if ((fscanf(file, "%d %d", &n_t, &m_t) != 2) || m_t <= 0 || n_t <= 0)
        {
            printf("ERR_DATA!");
            return ERR_DATA;
        }
        else
        {
            *mtr = allocate_matrix(n_t, m_t);
            if (mtr == NULL)
            {
                printf("ERR_ALLOCATE!");
                return ERR_ALLOCATE;
            }
            else
            {
                for (int i = 0; i < n_t; i++)
                {
                    for (int j = 0; j < m_t; j++)
                    {
                        if (fscanf(file, "%lf", &x) != 1)
                        {
                            printf("ERROR READING!");
                            free_matrix(*mtr, n_t);
                            return ERR_READ;
                        }
                        else
                        {
                            (*mtr)[i][j] = x;
                        }
                    }
                }
            }
        }
        fclose(file);
        *n = n_t;
        *m = m_t;
    }
    return OK;
}

void write_to_file(FILE *file, int n, int m, double **mtr)
{
    fprintf(file, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(file, "%lf ", mtr[i][j]);
        fprintf(file, "\n");
    }
}