#include <stdio.h>
#include <stdlib.h>
#define N 10

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

void print(int a[], int n)
{
    printf("Sorted array ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int n = 0;
    int a[N];
    int s;
    int fi = 0;
    while (scanf("%d", &s) == 1)
    {
        if (n == 10)
        {
            fi = 100;
            break;            
        }
        a[n] = s;
        n += 1;
    }
    if (n == 0)
    {
        printf("empty array");
        return EXIT_FAILURE;
    }
    bubblesort(a, n);
    print(a, n);
    if (fi == 100) 
        return 100;
    else
        return EXIT_SUCCESS;
}