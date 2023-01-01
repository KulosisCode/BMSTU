#include <stdio.h>

#define N 10

int read(int a[], int *n)
{
    printf("Input size of array(intrger) ");
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

int palindrome(int a)
{
    int rsv = 0, orn = a;
    while (a != 0)
    {
        rsv = rsv * 10 + a % 10;
        a /= 10;
    }
    if (rsv == orn)
        return 1;
    else
        return 0;
}

void removearr(int a[], int n, int i)
{
    for (int k = i; k < n - 1; k++)
        a[k] = a[k + 1];
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[N];
    int n;
    int fi = read(a, &n);
    if (fi)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 0)
                if (palindrome(a[i]) == 0)
                    j++; 
                else
                {
                    removearr(a, n, i);
                    n--;
                    i--;
                }
            else
            {
                printf("Input error");
                return -1;
            }
        }
        if (j == 0)
        {
            printf("No more elements in array");
            return -1;
        }
        else 
            print(a, j);
    }
    else
    {
        printf("Input error");
        return -1;
    }
}
