#include <stdio.h>
#include <stdbool.h>
bool ham(int *a)
{
    return true, a;
}

int main()
{
    bool b = false;
    int a = 10;
    int c = 2;
    b, c = ham(&a);
    if (c)
        printf("%d", c);
    return 0;
}

// for (int i = 0; i < board.rows; i++)
//     {
//         for (int j = 0 ; j < board.columns; j++)
//             printf("%d ", board.matrix[i][j]);
//         printf("\n");
//     }