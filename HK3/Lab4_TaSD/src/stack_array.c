#include "header.h"

int add_symbol_to_arr(stack_arr_t *array, const char sym)
{
    if (array->len > MAX_STACK)
        return ERR_OVER_FLOW;
    array->array[array->len++] = sym;
    return OK;
}

int array_input(stack_arr_t *array)
{
    char sym;
    array->len = 0;

    while ((scanf("%c", &sym) == 1) && sym != '\n')
    {
        if (add_symbol_to_arr(array, sym) != OK)
            return ERR_OVER_FLOW;
    }
    if (array->len == 0)
    {
        return ERR_EMPTY_STACK;
    }
    return OK;
}

char pop_stack_array(stack_arr_t *arr)
{
    arr->len--;
    return arr->array[arr->len];
}

int print_array(stack_arr_t *arr)
{
    if (arr->len == 0)
        return ERR_EMPTY_STACK;

    stack_arr_t temp = *arr;
    int count =  temp.len;
    while (count)
    {
        printf("%c\n", pop_stack_array(&temp));
        count--;
    }
    return OK;
}

int array_is_palindrome(stack_arr_t *arr)
{
    stack_arr_t temp;
    temp.len = 0;
    char sym;
    int size = arr->len;

    for (int i = 0; i < size / 2; i++)
    {
        sym = pop_stack_array(arr);
        add_symbol_to_arr(&temp, sym);
    }

    for (int i = 0; i < size % 2; i++)
        pop_stack_array(arr);
    for (int i = 0; i < arr->len; i++)
    {
        if (pop_stack_array(arr) != pop_stack_array(&temp))
        {
            return NOT_PALINDROME;
        }
    }

    return PALINDROME;
}