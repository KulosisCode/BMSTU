#include "international_teen48.c"

int main(void)
{
    matrix_t board;
    int *d[MAX_SIZE];

    board.rows = 4;
    board.columns = 4;
    int a1[4][4] = {{4, 4, 8, 4},
                    {8, 2, 2, 2},
                    {64, 64, 0, 8},
                    {16, 256, 0, 0}};
    create_matrix(d, *a1, 4);
    board.matrix = d;
    char result1 = teen48game(board);
    printf("%c\n", result1);
    for (int i = 0; i < board.rows; i++)
    {
        for (int j = 0 ; j < board.columns; j++)
            printf("%d ", board.matrix[i][j]);
        printf("\n");
    }
    return 0;
}