#include "header.h"

int sorted_stuff(stuff *things, const size_t n)
{
    if (things == NULL || n == 0)
        return ERR_PARAM;
    stuff *obj = things;
    for (size_t i = 0; i < n; i++)
    {
        if (fabs(obj->volume) < EPS)
            return ERR_DATA; 
        obj->density = obj->weight / obj->volume;
        obj++;
    }
    stuff *bg = things;
    stuff *ed = things + n;

    for (stuff *i = bg; i < ed - 1; i++)
    {
        int flag = 1;
        for (stuff *j = bg; j < ed - 1 - (i - bg); j++)
        {
            stuff *k = j + 1;  
            if (((j->density) - (k->density)) > EPS)
            {
                stuff temp = *k;
                *k = *j;
                *j = temp;
                flag = 0;
            }
        }
        if (flag)
            break;
    }
    return OK;
}