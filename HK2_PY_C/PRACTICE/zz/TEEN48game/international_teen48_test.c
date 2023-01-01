#include "international_teen48.h"

int main(void)
{
    int successful_tests = 0;

    matrix_t board;
    int *d[MAX_SIZE];

    board.rows = 4;
    board.columns = 4;
    int a1[4][4] = {{0, 0, 0, 0},
                    {2, 2, 4, 0},
                    {0, 8, 16, 0},
                    {2, 0, 0, 2}};
    create_matrix(d, *a1, 4);
    board.matrix = d;
    char result1 = teen48game(board);
    if (result1 == 'l')
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 1 failed\n");
    }

    board.rows = 4;
    board.columns = 4;
    int a2[4][4] = {{4, 2, 4, 2},
                    {2, 4, 2, 4},
                    {4, 2, 4, 2},
                    {2, 4, 8, 8}};
    create_matrix(d, *a2, 4);
    board.matrix = d;
    char result2 = teen48game(board);
    if (result2 == 'r')
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 2 failed\n");
    }

    board.rows = 4;
    board.columns = 4;
    int a3[4][4] = {{0, 0, 0, 0},
                    {0, 0, 2, 4},
                    {0, 0, 0, 2},
                    {8, 2, 4, 2}};
    create_matrix(d, *a3, 4);
    board.matrix = d;
    char result3 = teen48game(board);
    if (result3 == 'u')
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 3 failed\n");
    }
    board.rows = 6;
    board.columns = 6;
    int a4[6][6] = {{2, 4, 2, 4, 2, 2},
                    {0, 2, 2, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0}};
    create_matrix(d, *a4, 6);
    board.matrix = d;
    char result4 = teen48game(board);
    if (result4 == 'd')
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 4 failed\n");
    }

    printf("%d / 4 TESTS SUCCESSFUL\n", successful_tests);
    return 0;
}