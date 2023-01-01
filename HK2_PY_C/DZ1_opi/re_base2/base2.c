#include <stdio.h>
#include <assert.h>

#define OK           0
#define ERR_IO      -1
#define ERR_EVEN    -2
#define ERR_NEG     -3

int SumDigits(int num)
{
    int sum = 0;
    if (num < 0) 
        return -1;
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

int ConverNumberToBase2(int num)
{
    assert(num >= 0);
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

int main ()
{
    int n,rc;
    printf("Enter n:\n");
    if (scanf("%d", &n) == 1)
    {
        if (n >= 0)
        {
            if (SumDigits(n) == 1)
            {
                printf("Base2 of %d : %d\n", n, ConverNumberToBase2(n));
                rc = OK;
            }
            else
            {
                printf("Sum digits must be even number \n");
                rc = ERR_EVEN;
            }
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