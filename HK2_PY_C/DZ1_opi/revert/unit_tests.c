#include <stdio.h>

#define OK           0
#define ERR_IO      -1
#define ERR_NEG     -2
#define ERR_INPUT   -3
int SumDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    if (sum % 2 == 0)
        return 1;
    else 
        return 0;
}

int ReverseNumber(int num)
{
    int reverse = 0;
    while (num != 0)
    {
        reverse = reverse*10 + num % 10;
        num /= 10;
    }
    return reverse;
}

int ConverNumberToBase2(int num)
{
    int x_num = 0;
    int a[20];
    int i = 0;
    if (num == 0)
        return 0;
    while (num != 0)
    {
        x_num = num % 2;
        num /= 2;
        a[i] = x_num;
        i++;
    }
    x_num = 0;
    for (int k = i - 1; k > -1; k--)
        x_num = x_num*10 + a[k];
    return x_num;
}

void ConverNumber(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (SumDigits(a[i]) == 1)
            a[i] = ConverNumberToBase2(a[i]);
        else
            a[i] = ReverseNumber(a[i]);
    }
}

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
                {
                    a[i] = s;
                }
                else
                {
                    printf("Input Error!");
                    return ERR_INPUT;
                }
            }
            ConverNumber(a, n);
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