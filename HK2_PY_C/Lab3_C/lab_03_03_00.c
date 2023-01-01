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

int sum_ele(int a[N][M], int j, int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
        sum += a[j][i];
    return sum;
}

void sort(int a[N][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int jmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (sum_ele(a, j, m) < sum_ele(a, jmin, m))
                jmin = j;
        }
        for (int j = 0; j < m; j++)
        {
            int buf = a[jmin][j];
            for (int k = jmin; k > i; k--)
                a[k][j] = a[k - 1][j];
            a[i][j] = buf;
        }
    }
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
        if (err != 0)
        {
            printf("Error input element");
            return err;
        }
        else
        {
            sort(a, n, m);
            write_matrix(a, n, m);
        }
    }
    return OK;
}
