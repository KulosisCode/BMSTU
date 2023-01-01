#include <stdio.h>

#define OK           0
#define ERR_IO      -1
#define ERR_NEG     -2
#define ERR_INPUT   -3

void PrintArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int rc, n, s;
    int a[100];
    int num = 0;
    printf("Enter n:\n");
    if (scanf("%d", &n) == 1)
    {
        if (n >= 0)
        {
            for (int i = 0; i < n; i++)
            {
                if(scanf("%d", &s) == 1)
                    a[i] = s;
                else
                {
                    printf("Input Error!");
                    return ERR_INPUT;
                }
            }
            PrintArr(a, n);
            rc = OK;
        }
        else
        {
            printf("n must be zero or positive\n");
            rc = ERR_NEG;
        }
    }
    else
    {
        printf("IO error\n");
        rc = ERR_IO;
    }
    return rc;
}