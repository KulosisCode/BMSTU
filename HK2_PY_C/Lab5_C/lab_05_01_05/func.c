#include "func.h"

int progress(FILE* file)
{
    int rc = 0;
    int x = 0;
    int x_old = 0;
    int count = 1;
    int count_max = 0;
    int root = 0;
    if (file == NULL)
    {
        return FILE_NOT_EXIST;
    }
    while (rc != EOF)
    {
        rc = fscanf(file, "%d", &x);
        if (rc == EOF)
        {
            break;
        }
        if (rc != 1 && rc != EOF)
            break;
        else
        {
            if (root)
            {
                if (x == x_old)
                    count++;
                else 
                    count = 1;
            }
            x_old = x;
            if (count_max < count)
                count_max = count;
        }
        root++; 
    }
    return count_max;
}