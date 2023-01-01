#include "international_7equeence.h"

int main(void)
{
    int successful_tests = 0;
    int arr[1000] = {0};
    long long result1 = sequence_game(arr);
    if (result1 == 0)
    {
        successful_tests++;
    }
    else
    {
        printf("Test 1 failed\n");
    }

    for (int i = 0; i < 1000; i++)
    {
        arr[i] = -1;
    }
    long long result2 = sequence_game(arr);
    if (result2 == -1)
    {
        successful_tests++;
    }
    else
    {
        printf("Test 2 failed\n");
    }

    for (int i = 0; i < 1000; i++)
    {
        arr[i] = (i % 3) + 1;
    }
    long long result3 = sequence_game(arr);
    if (result3 == 3888)
    {
        successful_tests++;
    }
    else
    {
        printf("Test 3 failed\n");
    }

    arr[0] = -2;
    for (int i = 1; i < 1000; i++)
    {
        arr[i] = 2;
    }
    long long result4 = sequence_game(arr);
    if (result4 == 8192)
    {
        successful_tests++;
    }
    else
    {
        printf("Test 4 failed\n");
    }

    for (int i = 0; i < 1000; i++)
    {
        if (i % 2 == 0) 
            arr[i] = -1;
        else
            arr[i] = 2;
    }
    long long result5 = sequence_game(arr);
    if (result5 == 128)
    {
        successful_tests++;
    }
    else
    {
        printf("Test 5 failed\n");
    }

    arr[999] = 12;
    for (int i = 0; i < 999; i++)
    {
        arr[i] = 1;
    }
    long long result6 = sequence_game(arr);
    if (result6 == 12)
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