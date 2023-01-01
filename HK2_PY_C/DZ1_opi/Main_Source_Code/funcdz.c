#include "funcdz.h"

int ReadFile(FILE *file, int a[], int n)
{
    n = 0;
    int rc = 0, temp;
    char str[100];
    scanf("%s", str);
    if ((file = fopen(str, "r")) == NULL)
    {
        fclose(file);
        return NOT_EXIST;
    }
    while ((rc) != EOF)
    {
        rc = fscanf(file,"%d", &temp);
        if ((rc != EOF && rc != 1) || temp < 0)
        {
            fclose(file);
            return Input_Error;
        }
        if (rc != EOF)
        {
            if ( n < MAX_ARR)
            {
                a[n] = temp;
                n++; 
            }
            else
                return ERR_100;
        }
    }
    fclose(file);
    return n;
}

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
