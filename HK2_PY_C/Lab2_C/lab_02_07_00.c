#include <stdio.h>
#include <stdlib.h>
#define N 10000

void bubblesort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                int t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
        }
    }
}

int main()
{
    int n;
    int a[N];
    int s;
    if (scanf("%d", &n) != 1 || n < 1 )
    {
        printf("Input error");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &s) != 1)
        {
            printf("Input error");
            return EXIT_FAILURE;  
        }
        else
            a[i] = s;
    }
    bubblesort(a, n);
    return EXIT_SUCCESS;
}