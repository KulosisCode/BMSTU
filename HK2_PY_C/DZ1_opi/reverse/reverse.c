#include <stdio.h>

#define OK           0
#define ERR_IO      -1
#define ERR_ODD     -2
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

int main ()
{
    int n,rc;
    printf("Enter n:\n");
    if (scanf("%d", &n) == 1)
    {
        if  (n >= 0)
        {
            if (SumDigits(n) == 0)
            {
                printf("Reverse of %d : %d\n", n, ReverseNumber(n));
                rc = OK;
            }
            else
            {
                printf("Sum digits must be odd number \n");
                rc = ERR_ODD;
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