#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 20


int get_abs(int n)
{
    return abs(n);
}
    
int get_arr(int arr[NMAX][NMAX], int row, int col)
{
    int s;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (scanf("%d", &s) == 1)
                arr[i][j] = s; 
            else
            {
                printf("Input Error!");
                return EXIT_FAILURE;
            }   
        } 
    return EXIT_SUCCESS; 
}

void add_100(int arr[NMAX][NMAX], int i, int *row, int *col)
{
    for (int j = *row; j > i + 1; j--)
    {
        for (int k = 0; k < *col; k++)
            arr[j][k] = arr[j - 1][k];  
    }
    for (int k = 0; k < *col; k++)
        arr[i + 1][k] = 100;
    *row += 1;
}

void check_arr(int arr[NMAX][NMAX], int *row, int *col, int key)
{
    int count1;
    int count2;
    int temp;
    for (int i = 0; i < *row; i++)
    {
        count1 = 0;
        count2 = 0;
        for (int k = 0; k < *col; k++)
        {
            int x = get_abs(arr[i][k]);
            if (x % 10 == key) 
                count1 += 1;
            temp = 0;
            while (x > 0)
            {
                temp = x % 10;
                x = x / 10;
            }
            if (temp == key)
                count2 += 1;
        }
        if (count1 == count2 && count1 != 0)
        {
            add_100(arr, i, row, col);
            i++;
        }
    }
}

void print_arr(int arr[NMAX][NMAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", arr[i][j]); 
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    int arr[NMAX][NMAX];
    int row;
    int col;
    int key;
    int rc;

    printf("Input number of row: ");
    rc = scanf("%d", &row);
    if (rc != 1 || row > 10 || row < 1) 
    {
        printf("Input Error");
        return -1;
    }
    printf("Input number of column: ");
    rc = scanf("%d", &col);
    if (rc != 1 || col > 10 || col < 1)
    {
        printf("Input Error");
        return -1;
    } 
    
    if (get_arr(arr, row, col) == 0)
    {
        printf("Input key number: ");
        rc = scanf("%d", &key);
        if (rc != 1 || key > 9 || key < 0)
        {
            printf("Input Key Error");
            return -1;
        }
        check_arr(arr, &row, &col, key);
        print_arr(arr, row, col);
        return EXIT_SUCCESS;
    }    
    return -1;
}