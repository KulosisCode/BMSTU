#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERR_EMPTY    -1
#define Input_Error  -2
#define NOT_EXIST    -3
#define ERR_100      -4
#define MAX_ARR      100

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

void PrintArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[100];
    FILE *file = NULL;
    int n = 0;
    n = ReadFile(file, a, n);
    if (n == 0)
    {
        printf("Empty file !");
        return ERR_EMPTY;
    }
    else if (n == Input_Error)
    {
        printf("Incorrect data!");
        return Input_Error;
    }
    else if (n == ERR_100)
    {
        printf("The file line has more than 100 numbers!");
        return ERR_100;
    }
    else if (n == NOT_EXIST)
    {
        printf("The file does not exist!");
        return NOT_EXIST;
    }
    else 
    {
        PrintArr(a, n);
        return EXIT_SUCCESS;
    }
}