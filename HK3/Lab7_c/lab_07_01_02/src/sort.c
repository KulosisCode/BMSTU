#include "../inc/sort.h"

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void swap(size_t size, char *num_1, char *num_2)
{
    char temp;
    while (size > 0)
    {
        temp = *num_1;
        *num_1 = *num_2;
        *num_2 = temp;

        num_1++;
        num_2++;
        size--;
    }
}

int mysort(void *base, size_t nitems, size_t size, int (*compare)(const void*, const void*))
{
    if (nitems < 1 || base == NULL || compare == NULL)
        return ERR_INVALID_PARAM;
    char *p_1, *p_2, *pbegin, *pend;
    char *p_origin = (char*) base;
    pbegin = p_origin + size;
    pend = p_origin + nitems * size;
    for (size_t i = 1; pbegin < pend; pbegin += size, i++)
    {
        size_t bg = 0;
        size_t ed = i;
        size_t mid;
        if (bg == ed)
            bg ++;
        else 
        {
            while (bg < ed)
            {
                mid = (bg + ed) / 2;
                p_1 = p_origin + mid * size;
                if (compare(pbegin, p_1) < 0)
                    ed = mid;
                else 
                    bg = mid + 1;
            }
        }
        size_t j = i;
        while (j > bg && j > 0)
        {
            p_1 = p_origin + j * size;
            p_2 = p_1 - size;
            swap(size, p_1, p_2);
            j--;
        }
    }
    return OK;
}