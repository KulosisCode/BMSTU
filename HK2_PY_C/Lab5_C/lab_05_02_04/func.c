#include "func.h"

int find_min_max(FILE *file, int  *pos_1, int *pos_2)
{
    int rc = 0, x; 
    int index = 0, min, max;
    while (rc != EOF)
    {
        rc = fscanf(file, "%d", &x);
        if (rc == EOF)
            break;
        if (rc != 1)
            return ERR_INPUT;
        if (index == 0)
        {
            min = x;
            max = x;
            *pos_1 = 0;
            *pos_2 = 0;
        }
        else
        {
            if (min > x)
            {
                min = x;
                *pos_1 = index;
            }
            if (max < x)
            {
                max = x;
                *pos_2 = index;
            }
        }
        index++;
    }
    return index;
}

int process(FILE *file, float *avg)
{
    int pos_1, pos_2;
    int num = find_min_max(file, &pos_1, &pos_2);
    if (num == ERR_INPUT)
    {
        return ERR_INPUT;
    }
    else if (num <= 1)
    {
        return ERR_DATA;
    }
    else
    {
        rewind(file);
        int rc = 0, x;
        int index = 0;
        int sum = 0;
        if (pos_1 > pos_2)
        {
            int temp = pos_1;
            pos_1 = pos_2;
            pos_2 = temp;
        }
        if (pos_2 - pos_1 < 2)
        {
            return ERR_DATA;
        }
        while (rc != EOF)
        {
            rc = fscanf(file, "%d", &x);
            if (rc == EOF)
                break;
            if (index > pos_1 && index < pos_2)
            {
                sum += x;
            }
            index++;
        }
        *avg = (float)sum / (pos_2 - pos_1 - 1);
        return OK;
    }
}