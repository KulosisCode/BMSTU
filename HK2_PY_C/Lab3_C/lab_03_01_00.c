#include <stdio.h>
#include <math.h>
#define OK 0
#define ERROR -1
#define INPUT_OK 1

int get_arr(int a[10][10], int row, int col)
{
    int s;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (scanf("%d", &s) == INPUT_OK)
                a[i][j] = s; 
            else
            {
                printf("Input Error!");
                return ERROR;
            }   
        } 
    return OK;  
}

void check_arr(int a[10][10], int row, int col)
{
    int flag;
    for (int j = 0; j < col; j++)
    {
        flag = 1;
        for (int i = 0; i < row - 1; i++)
        {
            if (a[i][j] <= a[i + 1][j])
            {
                flag = 0; 
                break;
            }
        }
        if (row == 1)
            flag = 0;
        printf("%d ", flag); 
    }      
}
int main()
{
    int a[10][10];
    int row, col;
    int rc;
    printf("Input number of row: ");
    rc = scanf("%d", &row);

    if (rc != INPUT_OK || row > 10 || row < 1) 
    {
        printf("Input Error");
        return ERROR;
    }
    printf("Input number of column: ");
    rc = scanf("%d", &col);

    if (rc != INPUT_OK || col > 10 || col < 1)
    {
        printf("Input Error");
        return ERROR;
    } 

    if (get_arr(a, row, col) == OK)
    {
        check_arr(a, row, col);
        return OK;
    }
    return ERROR;
}