#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT 1
#define ERR_LOGIC 2

int read_n_m(int *n, int *m)
{
    printf("Input (integer) N and M: ");
    int rc = scanf("%d%d", n, m);
    if (rc == 2)
    {
        if ((*n > 0) && (*n < 11) && (*m > 0) && (*m < 11))
            return OK;
        else
            return ERR_LOGIC;
    }
    else
        return ERR_INPUT;
}

void write_matrix(int a[N][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
void walk_matrix(int a[N][M], int n, int m)
{
    int k = 1;
    for (int j = 0; j < m; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                a[i][j] = k;
                k++; 
            }
        }
        else
        {
            for (int i = n - 1; i > -1; i--)
            {
                a[i][j] = k;
                k++;
            }
        }
    }  
}
int main()
{
    int a[N][M];
    int n, m;
    int err = read_n_m(&n, &m);
    if (err != OK)
    {
        printf("Input error");
        return err;
    }
    else
    {
        walk_matrix(a, n, m);
        write_matrix(a, n, m);
    }
    return OK;
}
