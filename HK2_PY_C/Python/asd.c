#include <stdio.h>

void print(const int arr[])
{
    int n = sizeof(arr) / sizeof(arr[0]);
    int  i;
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    print(arr);
    return 0;
}