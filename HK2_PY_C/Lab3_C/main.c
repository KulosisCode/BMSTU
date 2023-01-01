#include<stdio.h>
#include<stdlib.h>
#define N 10
#define M 10
#define NMAX 512

int input_matrix(int a[NMAX][NMAX], size_t r, size_t c)
{
    for (size_t i = 0; i < r; ++i)
        for (size_t j = 0; j < c; ++j)
            if (scanf("%d", &a[i][j]) != 1)
                return EXIT_FAILURE;     
    return EXIT_SUCCESS;
}
int digit1(size_t a)
{
    while (a >= 10)
    {
        a = a / 10;
    }
    return a;
}
int digit2(size_t a)
{
    return a % 10;
}
void insert_array(int a[NMAX][NMAX], size_t *n, size_t m, size_t k)
{
    for (size_t i = *n; i > k; i--)
    {
        for (size_t j = 0; j < m; j++)
            a[i][j] = a[i - 1][j];
    }
    for (size_t j = 0; j < m; j++)
    {
        a[k][j] = 100;
    }
    *n += 1;
}
void make_list(int a[NMAX][NMAX], size_t *n, size_t m, int k)
{
    int p = *n;
    for(int i = p - 1; i > -1; i--)
    {
        int count1 = 0; 
        int count2 = 0;
        for (size_t j = 0; j < m; j++)
        {
            if (digit1(a[i][j]) == k)
                count1 += 1;
            if (digit2(a[i][j]) == k)
                count2 += 1;
        }
        if (count1 == count2 && count1 != 0)
        {
            insert_array(a, n, m, i + 1);
        }        
    }
}


void write_matrix(int a[NMAX][NMAX], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    size_t n, m;
    int a[NMAX][NMAX];
    int k;
    if (scanf("%zu", &n) != 1 || n < 1 || n > N)
    {
        printf("Input error");
        return -1;
    }
    if (scanf("%zu", &m) != 1 || m < 1 || m > N)
    {
        printf("Input error");
        return -1;
    }
    if (input_matrix(a, n, m))
    {
        printf("Input error");
        return -1;
    }
    if (scanf("%d", &k) != 1 || k < 0 || k > 9)
    {
        printf("Input error");
        return -1;
    }
    make_list(a, &n, m, k);
    write_matrix(a, n, m);
    return EXIT_SUCCESS;
}