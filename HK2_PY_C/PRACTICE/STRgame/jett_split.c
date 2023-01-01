//#include "jett_split.h"
#include <stdio.h>
#include <stdlib.h>
int split(const char *string, char **matrix, const char symbol)
{
    int number = 0, count = 0;
    char cur;
    for (size_t i = 0; string[i] != '\0'; i++)
    {
        cur = string[i];
        if (cur == symbol)
        {
            matrix[number++][count] = '\0';
            count = 0;
        }
        else
            matrix[number][count++] = cur;

        if (string[i + 1] == '\0' && count != 0)
            matrix[number++][count] = '\0';
    }
    return number;
}

int main(void)
{
    int successful_tests = 0;
    char str4[100] = "...I.AM.A.ROBOT...";
    char symbol4 = '.';
    char **matrix4 = (char**) malloc (100 * 100);
    for (int i = 0; i < 100; i++)
    {
        matrix4[i] = (char*) malloc (100);
    }
    int result4 = split(str4, matrix4, symbol4);
    if (result4 == 4)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 4 failed\n");
    }
    printf("%d / 5 TESTS SUCCESSFUL\n", successful_tests);
}