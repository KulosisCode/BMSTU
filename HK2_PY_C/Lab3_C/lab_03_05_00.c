# include <stdio.h>
# include <stdbool.h>

# define OK 0
# define ERROR_IO -1
# define ERROR_RANGE -2
# define ERROR_COUNT -3

# define ROW_MAX 10
# define COLUMN_MAX 10

int matrix_input(int ar[][COLUMN_MAX], int *m, int *n)
{
    int rc = OK;
    if (scanf("%d%d", m, n) != 2)
        rc = ERROR_IO;
    else if (*m < 1 || *m > ROW_MAX || *n < 1 || *n > COLUMN_MAX)
        rc = ERROR_RANGE;
    else
    {
        for (int i = 0; i < *m && rc == OK; i++)
            for (int j = 0; j < *n && rc == OK; j++)
                if (scanf("%d", &ar[i][j]) != 1)
                    rc = ERROR_IO;
    }

    return rc;
}

void matrix_output(int ar[][COLUMN_MAX], int m, int n)
{
    printf("Maxtrix after sorting: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", ar[i][j]);
        printf("\n");
    }
}

bool prime(int n)
{
    if (n < 2)
        return false;
    else
    {
        int d = 0;
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
                d++;
            if (d != 0)
                break;
        }
        if (d == 0)
            return true;
        else
            return false;
    }
}

int array_prime(int ar1[][COLUMN_MAX], int *ar2, int m, int n)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (prime(ar1[i][j]))
            {
                ar2[cnt] = ar1[i][j];
                cnt++;
            }

    return cnt;
}

void array_reverse(int *ar, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = ar[i];
        ar[i] = ar[n - i - 1];
        ar[n - i - 1] = temp;
    }
}

void array_to_matrix(int ar1[][COLUMN_MAX], int *ar2, int m, int n, int cnt)
{
    cnt = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (prime(ar1[i][j]))
            {
                ar1[i][j] = ar2[cnt];
                cnt++;
            }
}

int main(void)
{
    int array[ROW_MAX][COLUMN_MAX], m, n;
    int rc = matrix_input(array, &m, &n);
    int ar[ROW_MAX * COLUMN_MAX], cnt;
    if (rc == OK)
    {
        cnt = array_prime(array, ar, m, n);
        if (cnt != 0)
        {
            array_reverse(ar, cnt);
            array_to_matrix(array, ar, m, n, cnt);
            matrix_output(array, m, n);
        }
        else
            rc = ERROR_COUNT;
    }
    else
        printf("ERROR.\n");
    return rc;
}
