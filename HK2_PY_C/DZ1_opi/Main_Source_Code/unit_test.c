#include "funcdz.c"

void test1()
{
    int n = 25;
    int result  = 0;
    if (SumDigits(n) == result)
    {
        printf("Test 1 - SumDigits passed.\n");
    }
    else
    {
        printf("Test 1 - SumDigits fail!\n");
    }
}

void test2()
{
    int n = 22;
    int result = 1;
    if (SumDigits(n) == result)
    {
        printf("Test 2 - SumDigits passed.\n");
    }
    else
    {
        printf("Test 2 - SumDigits fail!\n");
    }
}

void test3()
{
    int n = 27;
    int result = 72;
    if (ReverseNumber(n) == result)
    {
        printf("Test 3 - ReverseNumber passed.\n");
    }
    else
    {
        printf("Test 3 - ReverseNumber fail!\n");
    }
}

void test4()
{
    int n = 320;
    int result = 23;
    if (ReverseNumber(n) == result)
    {
        printf("Test 4 - ReverseNumber passed.\n");
    }
    else
    {
        printf("Test 4 - ReverseNumber fail!\n");
    }
}

void test5()
{
    int n = 12;
    int result = 1100;
    if (ConverNumberToBase2(n) == result)
    {
        printf("Test 5 - ConverNumberToBase2 passed.\n");
    }
    else
    {
        printf("Test 5 - ConverNumberToBase2 fail!\n");
    }
}
void test6()
{
    int n = 24;
    int result = 11000;
    if (ConverNumberToBase2(n) == result)
    {
        printf("Test 6 - ConverNumberToBase2 passed.\n");
    }
    else
    {
        printf("Test 6 - ConverNumberToBase2 fail!\n");
    }
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}