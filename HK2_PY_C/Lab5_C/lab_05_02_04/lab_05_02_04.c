#include "func.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "ERROR FILE INPUT!");
        return ERR_FILE;
    }
    FILE *file = NULL;
    float avg;
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr,"FILE NOT EXIST!");
        return FILE_NOT_EXIST;
    }
    int result = process(file, &avg);
    fclose(file);
    if (result == ERR_INPUT)
    {
        fprintf(stderr,"ERROR INPUT!");
        return ERR_INPUT;
    }
    else if (result == ERR_DATA)
    {
        fprintf(stderr,"ERROR DATA!");
        return ERR_DATA;
    }
    else
    {
        fprintf(stdout,"%f", avg);
        return OK;
    }
}