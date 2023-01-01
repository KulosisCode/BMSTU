#include "header.h"

int main(int argc, char **argv)
{
    stuff *things = NULL;
    size_t size = 0;
    char filter[FILTER_SIZE] = { '\0' };
    if (argc < MIN_ARG || argc > MAX_ARG)
    {
        //printf("ERROR ARGS");
        return ERR_ARG;
    }
    else 
    {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            //printf("FILE NOT EXIST!");
            return ERR_EXIST;
        }
        else 
        {
            int rc = count_things(file, &size);
            if (rc != OK)
            {
                fclose(file);
                return rc;
            }
            rewind(file);
            things = calloc(size, sizeof(stuff));
            if (things == NULL)
            {
                fclose(file);
                //printf("ERROR ALLOCATE!");
                return ERR_ALLOCATE;
            }
            else
            {
                read_all_things(file, things, size);
                if (argc == 2)
                {
                    int rc_1 = sorted_stuff(things, size);
                    if (rc_1 != OK)
                        return rc_1;
                    print_info(things, size, argc, filter);    
                }
                else if (argc == 3)
                {
                    strcpy(filter, argv[2]);
                    print_info(things, size, argc, filter);
                }
                free_things(things, size);
                if (fclose(file) == EOF)
                    return ERR_CLOSE;
            }
        }
    }
    return OK;
}