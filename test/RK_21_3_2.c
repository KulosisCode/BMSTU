#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10

int main(void)
{
    int n;
    int a[N];
    printf("Enter n: ");
    if(scanf("%d", &n) != 1 || n < 1 || n > N)
    {
        printf("Input error");
        return -1;
    }
    for (int i = 0; i < n; ++i)
        if(scanf("%d", &a[i]) != 1)
        {
            printf("Input error");
            return -1;
        }
    for(int i = 0; i < n; ++i)
    {
        int flag = 0;
        for(int j = 0; j < i; ++j)
            if(a[j] == a[i])
                flag = 1;
        if (flag)
            continue;
        flag = 0;
        for(int j = i + 1; j < n; ++j)
            if(a[j] == a[i])
                flag = 1;
        if (flag)
            printf("%d ", a[i]);
    }
    return EXIT_SUCCESS;
}