#include "international_split.h"

int main(void)
{
    int successful_tests = 0;

    char str1[100] = "How are you";
    char symbol1 = ' ';
    char **matrix1 = (char**) malloc (100 * 100);
    for (int i = 0; i < 100; i++)
    {
        matrix1[i] = (char*) malloc (100);
    }
    int result1 = split(str1, matrix1, symbol1);
    if (result1 == 3)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 1 failed\n");
    }

    char str2[100] = "Where-are-you-from!";
    char symbol2 = '-';
    char **matrix2 = (char**) malloc (100 * 100);
    for (int i = 0; i < 100; i++)
    {
        matrix2[i] = (char*) malloc (100);
    }
    int result2 = split(str2, matrix2, symbol2);
    if (result2 == 4)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 2 failed\n");
    }

    char str3[100] = "";
    char symbol3 = ' ';
    char **matrix3 = (char**) malloc (100 * 100);
    for (int i = 0; i < 100; i++)
    {
        matrix3[i] = (char*) malloc (100);
    }
    int result3 = split(str3, matrix3, symbol3);
    if (result3 == 0)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 3 failed\n");
    }

    char str4[100] = "       ";
    char symbol4 = ' ';
    char **matrix4 = (char**) malloc (100 * 100);
    for (int i = 0; i < 100; i++)
    {
        matrix4[i] = (char*) malloc (100);
    }
    int result4 = split(str4, matrix4, symbol4);
    if (result4 == 0)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 4 failed\n");
    }
    char str5[100] = "abc";
    char symbol5 = ' ';
    char **matrix5 = (char**) malloc (100 * 100);
    for (int i = 0; i < 100; i++)
    {
        matrix5[i] = (char*) malloc (100);
    }
    int result5 = split(str5, matrix5, symbol5);
    if (result5 == 1)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 5 failed\n");
    }

    printf("%d / 5 TESTS SUCCESSFUL\n", successful_tests);
    return 0;
}