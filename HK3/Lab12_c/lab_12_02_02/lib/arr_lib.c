#include "arr_lib.h"

int is_repeat(int *array, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (array[i] == array[index])
            return 1;
    }
    return 0;
}

void fibonacci_fill(int size, int *array)
{
    array[0] = 1;
    if (size > 1)
    {
        int i = 1;
        array[i] = 1;
        for (i = 2; i < size; i++)
        {
            array[i] = array[i - 1] + array[i - 2];
        }
    }   
}

void get_first_meet(int *src, int size_src, int *dst, int *dst_len)
{
    int count = 0;
    for (int i = 0; i < size_src; i++)
        if (!is_repeat(src, i))
        {
            count++;
        }

    //don't allocated
    if (count > *dst_len)
    {
        *dst_len = count;
        return;
    }

    //Fill array
    *dst_len = count;
    count = 0;
    for (int i = 0; i < size_src; i++)
    {
        if (!is_repeat(src, i))
        {
            dst[count++] = src[i];
        }
    }
}