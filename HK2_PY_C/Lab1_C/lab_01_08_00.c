#include<stdio.h>
#include<stdlib.h>

void change_bit(unsigned int a, int n)
{
    n %= 32;
    for (int x = n - 1; x > -1; x--)
        printf("%d", (a >> x) & 1);
    for (int x = 31; x >= n; x--)
        printf("%d", (a >> x) & 1);    
}

int main()
{
    unsigned int a;
    int n;
    if (scanf("%u %d", &a, &n) == 2 && n >= 0)
    {
        printf("Result: ");
        change_bit(a, n);
    }
    else
    {
        printf("Error: Input error");
        return -1;
    }
    return EXIT_SUCCESS;
}
