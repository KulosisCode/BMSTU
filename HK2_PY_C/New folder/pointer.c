#include <stdio.h>

int example(int **str, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
            str[i][j] = 1;
    }
    return 0;
}


void trans(int **a, int *buf, int n)
{
    for (int i =0; i < 10;  i++)
    {
        a[i] = buf + i * n;
    }
}
int main(void)
{
    //char str[10][10];
    // char **str = (char *) malloc (100 * 100);
    // for (int i = 0; i < 100;  i++)
    // {
    //     str[i] = (char *) malloc (100);
    // }
    int matrix[10][10] = {0};
    int *d[10];
    trans(d, *matrix, 10);
    int n = example(d, 10);
    return 0;
}