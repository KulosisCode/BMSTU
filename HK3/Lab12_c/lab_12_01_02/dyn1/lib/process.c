#include "sort.h"
#include "key.h"
#include "constan.h"
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



int key(const int *src, int len_src, int **dst, int *len_dst)
{
    size_t num_el = 0;

    if (src == NULL || len_src <= 0)
        return ERR_INVALID_PARAM;
    const int *pa = src;
    for (int i = 0; i < len_src; i++)
    {
        if (*pa >= 0)
        {
            num_el++;
            pa++;
        }
        else
            break;
    }
    
    if (num_el <= 0)
        return NO_DATA_LEFT;

    if (*len_dst < num_el)
    {
        *len_dst = num_el;
        return OK;
    }
    //*pb_dst = malloc(num_el * sizeof(int));

    pa = src;
    int *pb = *dst;
    for (size_t i = 0; i < num_el; i++)
    {
        *(pb++) = *(pa++);
    }

    return OK;
}