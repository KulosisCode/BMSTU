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
        if ((*n > 0) && (*n < 11) && (*m > 0) && (*m < 11) && (*n == *m))
            return OK;
        else
            return ERR_LOGIC;
    }
    else
        return ERR_INPUT;
}
int read_matrix(int n, int m, int a[N][M])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int rc = scanf("%d", &a[i][j]);
            if (rc != 1)
                return ERR_INPUT;
        }
    return OK;
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
        err = read_matrix(n, m, a);
        if (err)
        {
            printf("Error input element");
            return err;
        }
        else
        {
            int count = 0;
            int min = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (a[i][j] % 2)
                    {
                        min = a[i][j];
                        count++;
                    }
                }
            }
            if (count == 0)
            {
                printf("Error input element");
                return -1;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (a[i][j] % 2 && a[i][j] < min)
                        {
                            min = a[i][j];
                        }
                    }
                }
                printf("%d", min);
            }
        }
    }
    return OK;
}
