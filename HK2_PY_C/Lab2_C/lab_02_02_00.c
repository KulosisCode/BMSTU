#include <stdio.h>

#define N 10

int read(int a[], int *n)
{
    printf("Inpur size of array(intrger) ");
    int fi;
    int rc = scanf("%d", n);
    if (rc == 1)
    {
        fi = 1;
        if ((*n > 0) && (*n <= 10))
        {
            fi = 1;
            int s;
            for (int i = 0; i < *n; i++)
            {
                printf("Element of array ");
                rc = scanf("%d", &s);
                if (rc == 1)
                    a[i] = s;
                else
                {
                    fi = 0;
                    break;
                }
            }
        }
        else
        {
            fi = 0;
        }
    }
    else
    {
        fi = 0;
    }
    return fi;
}

int bigger_arr(int a, int n, double medium)
{
    if (a * n > medium)
    {
        return a;
    }
    else
        return 0;
}

void print(int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}

int main()
{
    int a[N], b[N];
    int n;
    int fi = read(a, &n);
    if (fi)
    {
        int j = 0;
        int k;
        double sum = 0.0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        for (int i = 0; i < n; i++)
        {
            k = bigger_arr(a[i], n, sum);
            if (k)
            {
                b[j] = k;
                j++;
            }
        }
        if (j)
        {
            print(b, j);
            return 0;
        }
        else
        {
            printf("Input error");
            return -1;
        }
    }
    else
    {
        printf("Input error");
        return -1;
    }
}
