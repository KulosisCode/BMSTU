#include "international_num63rs.h"

int main(void)
{
    int successful_tests = 0;

    int result1 = numbers_game(1, 10);
    if (result1 == 2520)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 1 failed\n");
    } 

    int result2 = numbers_game(7, 20);
    if (result2 == 232792560)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 2 failed\n");
    } 
    
    int result3 = numbers_game(5,5);
    if (result3 == 5)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 3 failed\n");
    } 

    int result4 = numbers_game(10,11);
    if (result4 == 110)
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