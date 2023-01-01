#include "func.h"

int main(int argc, char **argv)
{
    stuff things[MAX_THINGS];
    char filter[FILTER_SIZE] = { '\0' };
    if (argc < MIN_ARG || argc > MAX_ARG)
    {
        printf("ERROR ARG");
        return ERR_ARG;
    }
    else
    {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            printf("FILE NOT EXIST");
            return ERR_EXIST;
        }
        int n = read_file(file, things);
        if (fclose(file) == EOF)
                return ERR_CLOSE;
        if (n == ERR_DATA)
        {
            printf("ERROR DATA");
            return ERR_DATA;
        }
        else if (n == ERR_EMPTY)
        {
            printf("EMPTY FILE");
            return ERR_EMPTY;
        }
        else if (n == ERR_MAX_THINGS)
        {
            printf("ERROR MAX THINGS");
            return ERR_MAX_THINGS;
        }
        if (argc == 2)
        {
            sorted_stuff(things, n);
            print_info(things, n, argc, filter);
        }
        else if (argc == 3)
        {
            strcpy(filter, argv[2]);
            print_info(things, n, argc, filter);
        }
    }
    return OK;
}