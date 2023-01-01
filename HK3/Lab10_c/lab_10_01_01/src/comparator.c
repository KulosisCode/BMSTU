#include "header.h"

int comparator(const void *a, const void *b)
{
    int *num_a = (int *)a;
    int *num_b = (int *)b;
    if (*num_a == *num_b)
        return EQUAL;
    else if (*num_a > *num_b)
        return MORE;
    else
        return LESS;
}