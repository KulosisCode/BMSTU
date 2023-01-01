#include "../inc/key.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    size_t num_el = 0;

    if (pb_src == NULL || pe_src - pb_src <= 0)
        return ERR_INVALID_PARAM;
    
    for (const int *pa = pb_src; pa < pe_src; pa++)
    {
        if (*pa >= 0)
            num_el++;
        else
            break;
    }

    if (num_el == 0)
        return NO_DATA_LEFT;
    *pb_dst = malloc(num_el * sizeof(int));

    const int *pa = pb_src;
    int *pb = *pb_dst;
    for (size_t i = 0; i < num_el; i++)
    {
        *(pb++) = *(pa++);
    }
    *pe_dst = *pb_dst + num_el;

    return OK;
}