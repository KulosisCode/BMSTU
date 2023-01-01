#include "func.h"

int main(void)
{
    FILE *file;
    file = stdin;
    int n = 0;
    n = progress(file);
    if (n == 0)
    {
        printf("NO DATA!");
        return ERR_NO_DATA;
    }
    else if (n == FILE_NOT_EXIST)
    {
        printf("FILE NOT EXIST!");
        return FILE_NOT_EXIST;
    }
    printf("%d", n);
    return OK;
}
