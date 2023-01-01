#include "io.h"

int main(int argc, char **argv)
{
    double **mtr1 = NULL;
    double **mtr2 = NULL;
    double **result;
    double det;
    int n1 = 0, m1 = 0, n2 = 0, m2 = 0;

    if (argc < 4 || argc > 5)
    {
        printf("ERROR ARGS!");
        return ERR_ARGS;
    }
    
    if (argc == 5)
    {
        if (strcmp(argv[1], "a") && strcmp(argv[1], "m"))
        {
            printf("ERROR ARGS!");
            return ERR_ARGS;
        }
        else
        {
            int rc = read_from_file(argv[2], &mtr1, &n1, &m1);
            if (rc != OK)
                return rc;

            rc = read_from_file(argv[3], &mtr2, &n2, &m2);
            if (rc != OK)
            {
                free_matrix(mtr1, n1);
                return rc;
            }

            FILE *out = fopen(argv[4], "w");
            if (out == NULL)
            {
                printf("ERROR OPEN FILE!");
                free_matrix(mtr1, n1);
                free_matrix(mtr2, n2);
                return ERR_OPEN;
            }

            if (strcmp(argv[1], "a") == 0)
            {
                if (n1 != n2 || m1 != m2)
                {
                    printf("ERROR SIZE!");
                    free_matrix(mtr1, n1);
                    free_matrix(mtr2, n2);
                    return ERR_SIZE;
                }
                result = allocate_matrix(n1, m1);
                matrix_addition(mtr1, mtr2, result, n1, m1);
                write_to_file(out, n1, m1, result);
                free_matrix(mtr1, n1);
                free_matrix(mtr2, n1);
                free_matrix(result, n1);
            }
            else if (strcmp(argv[1], "m") == 0)
            {
                if (m1 != n2)
                {
                    printf("ERROR SIZE!");
                    free_matrix(mtr1, n1);
                    free_matrix(mtr2, n2);
                    return ERR_SIZE;
                }
                result = allocate_matrix(n1, m2);
                matrix_multi(mtr1, mtr2, result, n1, m1, m2);
                write_to_file(out, n1, m2, result);
                free_matrix(mtr1, n1);
                free_matrix(mtr2, n2);
                free_matrix(result, n1);
            }
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "o") != 0)
        {
            printf("ERROR ARGS!");
            return ERR_ARGS;
        }
        else
        {
            int rc = read_from_file(argv[2], &mtr1, &n1, &m1);
            if (rc != OK)
                return rc;
            if (n1 != m1)
            {
                printf("ERROR SIZE!");
                free_matrix(mtr1, n1);
                return ERR_SIZE;
            }
            FILE *out = fopen(argv[3], "w");
            if (out == NULL)
            {
                printf("ERROR OPEN FILE!");
                free_matrix(mtr1, n1);
                return ERR_OPEN;
            }

            det = gauss_caculation(mtr1, n1);
            fprintf(out, "%lf", det);
            free_matrix(mtr1, n1);
        }
    }
    return OK;
}