#include "header.h"
#include <time.h>
#include <inttypes.h>
#include <sys/time.h>

#define TIME (float)rand() / RAND_MAX

void get_time(float *result, float time_1, float time_2)
{
    *result = (time_2 - time_1) * (float)(TIME) + time_1;
}

int time_effect()
{
    array_queue_t array;
    array.head = -1;
    array.last = -1;
    array.len = 0;

    list_queue_t list;
    list.head = malloc(sizeof(node_t));
    list.last = malloc(sizeof(node_t));
    list.head->next = list.last;
    list.head->elem = ZERO;
    list.last->next = NULL;
    list.last->elem= ZERO;
    list.len = 0;

    struct timeval tv_start, tv_stop;
    int64_t s_1 = 0, s_2 = 0, mem_1 = 0, mem_2 = 0;
    srand(time(NULL));


    int num;
    printf("\nInput amount number :");
    scanf("%d",&num);
    printf("ARRAY :\n");

    // time adding stack
    gettimeofday(&tv_start, NULL);
    for (int i = 0; i < num; i++)
    {
        array_queue_add(&array, NUMBER);
    }
    gettimeofday(&tv_stop, NULL);
    s_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    printf("Time add : %10ld\n", s_1);

    //time delete
    s_1 = 0;
    gettimeofday(&tv_start, NULL);
    for (int i = 0; i < num; i++)
    {
        array_queue_pop(&array);
    }
    gettimeofday(&tv_stop, NULL);
    s_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    printf("Time delete : %10ld\n", s_1);

    mem_1 = sizeof(int) * 3 + sizeof(int) * MAX_ELEM;
    printf("Memory usage : %ld\n", mem_1);

    //################################################//

    printf("\nLIST :\n");

    // time adding 
    gettimeofday(&tv_start, NULL);
    for (int i = 0; i < num; i++)
    {
        list_queue_add(&list, NUMBER);
    }
    gettimeofday(&tv_stop, NULL);
    s_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    printf("Time add : %10ld\n", s_2);

    //time delete
    s_2 = 0;

    mem_2 = sizeof(list_queue_t) * (num + 2);

    gettimeofday(&tv_start, NULL);
    for (int i = 0; i < num; i++)
    {
        list_queue_pop(&list);
    }
    gettimeofday(&tv_stop, NULL);
    s_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    printf("Time delete : %10ld\n", s_2);
    
    printf("Memory usage : %ld\n", mem_2);

    free_list(&list);
    return OK;
}