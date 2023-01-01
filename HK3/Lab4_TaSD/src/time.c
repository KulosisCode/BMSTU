#include "header.h"
#include <time.h>
#include <inttypes.h>
#include <sys/time.h>

int array_input_tmp(stack_arr_t *array, int64_t *s)
{
    srand(time(NULL));
    char sym;
    array->len = 0;
    struct timeval tv_start, tv_stop;

    while ((scanf("%c", &sym) == 1) && sym != '\n')
    {
        gettimeofday(&tv_start, NULL);
        if (add_symbol_to_arr(array, sym) != OK)
            return ERR_OVER_FLOW;
        gettimeofday(&tv_stop, NULL);
        *s += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    }
    if (array->len == 0)
    {
        return ERR_EMPTY_STACK;
    }
    return OK;
}

int list_input_tmp(stack_list_t **head, int64_t *s)
{
    srand(time(NULL));
    char sym;
    int count = 0;
    struct timeval tv_start, tv_stop;
    while((scanf("%c", &sym) == 1) && sym != '\n')
    {
        gettimeofday(&tv_start, NULL);
        if ((*head) == NULL)
            *head = create_node(sym);
        else
        {
            if (add_node_to_list(head, sym) != OK)
                return ERR_OVER_FLOW;
        }
        count++;
        gettimeofday(&tv_stop, NULL);
        *s += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    }

    if (count == 0)
        return ERR_EMPTY_STACK;
    return OK;
}

int time_effect()
{
    stack_arr_t array;
    array.len = 0;
    stack_list_t *list = NULL;

    struct timeval tv_start, tv_stop;
    int64_t s_1 = 0, s_2 = 0, mem_1 = 0, mem_2 = 0;
    srand(time(NULL));

    printf("\nInput stacks(array):\n");
    // time adding stacks
    clear();
    array_input_tmp(&array, &s_1);
    printf("Time add : %10ld\n", s_1);

    //time check palindrome
    stack_arr_t temp;
    temp.len = array.len;
    strcpy(temp.array, array.array);
    s_1 = 0;

    gettimeofday(&tv_start, NULL);
    array_is_palindrome(&temp);
    gettimeofday(&tv_stop, NULL);
    s_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    printf("Time check palindrome : %10ld\n", s_1);

    //time delete
    s_1 = 0;
    int size  = array.len;
    gettimeofday(&tv_start, NULL);
    for (int i = 0; i < size; i++)
        pop_stack_array(&array);
    gettimeofday(&tv_stop, NULL);
    s_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    printf("Time delete all : %10ld\n", s_1);

    mem_1 = sizeof(int) + sizeof(char) * MAX_STACK;
    printf("Memory usage : %ld\n", mem_1);

    //################################################//

    printf("\nInput stacks(list):\n");

    // time adding stacks
    //clear();
    list_input_tmp(&list, &s_2);
    printf("Time add : %10ld\n", s_2);

    //time check palindrome
    stack_list_t *head = list;
    s_2 = 0;

    gettimeofday(&tv_start, NULL);
    list_is_palindrome(&head);
    gettimeofday(&tv_stop, NULL);
    s_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    printf("Time check palindrome : %10ld\n", s_2);

    //time delete
    s_2 = 0;
    size_t locate = 0;
    int size_list = list->len;

    mem_2 = sizeof(stack_list_t) * (list->len + 1);

    gettimeofday(&tv_start, NULL);
    while (size_list >= 0)
    {
        pop_stack_list(&list, &locate);
        size_list--;
    }
    gettimeofday(&tv_stop, NULL);
    s_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);
    printf("Time delete all : %10ld\n", s_2);
    
    printf("Memory usage : %ld\n", mem_2);

    free_list(list);

    return OK;
}