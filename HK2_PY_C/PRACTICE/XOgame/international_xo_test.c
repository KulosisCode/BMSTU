#include "international_xo.h"

void create_matrix(char **a, char *buf, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = buf + n * i;
}

int main(void)
{
    int successful_tests = 0;

    char *bf1[3];
    char a1[3][3] = {{'O', 'X', 'X'},
                    {' ', 'O', 'X'},
                    { ' ', ' ', ' '}};
    create_matrix(bf1, *a1, 3);
    int field_size1 = 3;
    int result1 = xogame(bf1, field_size1, 'X');
    if (result1 == 8)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 1 failed\n");
    }

    char *bf2[3];
    char a2[3][3] = {{'O', 'X', 'X'},
                    {'O', 'X', ' '},
                    { ' ', ' ', ' '}};
    create_matrix(bf2, *a2, 3);
    int field_size2 = 3;
    int result2 = xogame(bf2, field_size2, 'O');
    if (result2 == 6)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 2 failed\n");
    }

    char *bf3[3];
    char a3[3][3] = {{'O', 'X', 'X'},
                    {' ', ' ', 'O'},
                    { ' ', ' ', ' '}};
    create_matrix(bf3, *a3, 3);
    int field_size3 = 3;
    int result3 = xogame(bf3, field_size3, 'X');
    if (result3 == 4)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 3 failed\n");
    } 

    char *bf4[5];
    char a4[5][5] = {{'O', 'O', 'O', 'O', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', 'X', 'X', ' '},
                    {' ', ' ', 'X', ' ', ' '},
                    {' ', ' ', ' ', ' ', 'X'}};
    create_matrix(bf4, *a4, 5);
    int field_size4 = 5;
    int result4 = xogame(bf4, field_size4, 'X');
    if (result4 == 4)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 4 failed\n");
    }

    char *bf5[5];
    char a5[5][5] = {{'O', 'O', ' ', ' ', 'X'},
                    {' ', 'O', ' ', ' ', ' '},
                    {' ', 'O', 'X', 'X', 'O'},
                    {' ', ' ', 'X', ' ', ' '},
                    {'X', ' ', ' ', ' ', 'X'}};
    create_matrix(bf5, *a5, 5);
    int field_size5 = 5;
    int result5 = xogame(bf5, field_size5, 'O');
    if (result5 == 7)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 5 failed\n");
    }
    char *bf6[5];
    char a6[5][5] = {{'O', 'O', ' ', ' ', 'X'},
                    {' ', 'O', 'X', 'X', ' '},
                    {' ', 'O', 'X', 'X', 'O'},
                    {' ', 'X', 'X', 'O', ' '},
                    {'O', ' ', ' ', ' ', 'O'}};
    create_matrix(bf6, *a6, 5);
    int field_size6 = 5;
    int result6 = xogame(bf6, field_size6, 'X');
    if (result6 == 2)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 6 failed\n");
    }
    printf("%d / 6 TESTS SUCCESSFUL\n", successful_tests);
    return 0;
}