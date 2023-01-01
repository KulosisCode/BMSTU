#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long abc(long long a, long long n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
        result = result * a;  
    return result;
}

int main()
{
    long long a, n = -1;
    long long result = 1;
    scanf("%lld", &a);
    if (n != -1)
    {
        printf("Inpur error");
        return -1;
    }
    scanf("%lld", &n);
    if (n <= 0)
    {
        printf("Inpur error");
        return -1;
    }
    result = abc(a, n);
    printf("%lld", result);
    return EXIT_SUCCESS;
}
