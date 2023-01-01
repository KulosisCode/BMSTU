#include <stdio.h>

#define OK           0
#define ERR_IO      -1
#define ERR_NEG     -2

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

int main ()
{
    int n,rc;
    printf("Enter n:\n");
    if (scanf("%d", &n) == 1)
    {
        if (n >= 0)
        {
            printf("Sum digits of %d : %d\n", n, SumDigits(n));
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