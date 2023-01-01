#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <sys/time.h>
 
#define OK 0
#define ERROR -1
#define N 5000
 
int process_1(int arr[], int n)
{
    int cur = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cur *= arr[i];
        sum += cur;
        if (arr[i] < 0)
        {
            break;
        }
    }
    return sum;
}
 
int process_2(int* pa, int n)
{
    int cur = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cur *= *(pa + i);
        sum += cur;
        if (*(pa + i) < 0)
        {
            break;
        }
    }
    return sum;
}
 
int process_3(int* pa, int* pb)
{
    int cur = 1, sum = 0;
    int* ptr = pa;
    for (; ptr < pb; ptr++)
    {
        cur *= *(ptr);
        sum += cur;
        if (*ptr < 0)
        {
            break;
        }
    }
    return sum;
}
 
void make_arr(int arr[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}
 
int main()
{
    int arr[N], count = 0, n = 1;
    printf("Input n: ");
 
    int rc = scanf("%d", &n);
    if (rc == 1 && n > 0)
    {
        make_arr(arr, n);
    }
    else
    {
        return ERROR;
    }
 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    int repeat;
    printf("\nInput time you want to repeat: ");
    if (scanf("%d", &repeat) != 1)
    {
        return ERROR;
    }
 
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time = 0;
    for (int i = 0; i < repeat; i++)
    {
        gettimeofday(&tv_start, NULL);
        process_1(arr, n);
        gettimeofday(&tv_stop, NULL);
 
        elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    }
    printf("%" PRId64 " us\n", elapsed_time);
 
    printf("\n");
    printf("Process 2: %d \n", process_2(arr, n));
    printf("Process 3: %d \n", process_3(arr, arr + n));
 
    return 0;
 
}