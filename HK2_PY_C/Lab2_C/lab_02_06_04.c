#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
#define OK 0
#define ERR -1


int process_1(int a[],int n);
int process_2(int *pa, int n);
int process_3(int *pa,int *pb);
void read_arr(int a[],int n);

int main()
{
    int a[5000];
    int *pa = a;
    int n, turn;
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time = 0;
    printf("Input number of repetitions  (integer) ");
    if (scanf("%d", &turn) != 1 || turn <= 0)
    {
        printf("Input error");
        return ERR;
    }
    printf("Input array size  (integer) ");
    int rc = scanf("%d", &n);
    if (rc == 1)
    {
        if (n > 0)
        {
            read_arr(a, n);
            for (int k; k < turn; k++)
            {
                gettimeofday(&tv_start, NULL);
                process_1(a, n);
                gettimeofday(&tv_stop, NULL);
                elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                                (tv_stop.tv_usec - tv_start.tv_usec);
            }
            printf("%" PRId64 " us\n", elapsed_time / turn);
            elapsed_time = 0;
            int *pb;
            pb = pa + n;
            for (int k; k < turn; k++)
            {
                gettimeofday(&tv_start, NULL);
                process_2(a, n);
                gettimeofday(&tv_stop, NULL);
                elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                                (tv_stop.tv_usec - tv_start.tv_usec);
            }
            printf("%" PRId64 " us\n", elapsed_time / turn);
            elapsed_time = 0;
            for (int k; k < turn; k++)
            {
                gettimeofday(&tv_start, NULL);
                process_3(pa, pb);
                gettimeofday(&tv_stop, NULL);
                elapsed_time += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                                (tv_stop.tv_usec - tv_start.tv_usec);
            }
            printf("%" PRId64 " us\n", elapsed_time / turn);  
        }
        else
        {
            printf("Input error");
            return ERR;
        }
    }
    else
    {
        printf("Input error");
        return ERR;
    }
}

void read_arr(int a[], int n)
{
    srand(time(0));
    for(int i = 0 ; i < n ; i++) 
    {
        a[i] = rand() % 100;
    }
}

int process_1(int a[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                flag++;
        }
        if (flag == 1)
            res++;
    }
    return res;
}

int process_2(int *pa, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        int *pa1 = pa + i;

        for (int j = 0; j < n; j++)
        {
            if (*(pa + i) == *(pa1 + j))
                flag++;
        }
        if (flag == 1)
            res++;
    }
    return res;
}

int process_3(int *pa, int *pb)
{
    int res = 0;
    for (; pa < pb; pa++)
    {
        int flag = 0;
        int *pa1 = pa;

        for (; pa1 < pb; pa1++)
        {
            if (*pa == *pa1)
                flag++;
        }
        if (flag == 1)
            res++;
    }
    return res;
}