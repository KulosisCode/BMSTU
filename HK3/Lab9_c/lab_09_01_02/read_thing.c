#include "header.h"

int read_file(FILE *file, stuff *things)
{
    int rc = OK; 
    char temp_name[MAX_LEN + 1];
    double temp_weight = 0, temp_volume = 0;
    
    if (fscanf(file, "%s", temp_name) == 1)
    {
        if (strlen(temp_name) > MAX_LEN)
        {
            //printf("ERROR LEN NAME!");
            return ERR_DATA;
        }
        else if (fscanf(file, "%lf %lf", &temp_weight, &temp_volume) != 2)
        {
            //printf("ERROR DATA!");
            return ERR_DATA;
        }
        else if (temp_weight <= 0 || temp_volume <= 0)
        {
            //printf("ERROR VALUE!");
            return ERR_DATA;
        }
        rc = create_things(things, temp_name, temp_weight, temp_volume);
    }
    else 
        return ERR_DATA;
    return rc;
}

void read_all_things(FILE *file, stuff *things, size_t size)
{
    for (size_t i = 0; i < size; i++)
        read_file(file, things + i);
}

int count_things(FILE *file, size_t *size)
{
    int rc = OK;
    stuff thing;
    memset(&thing, 0, sizeof(stuff));
    *size = 0;
    
    while ((!feof(file)) && (rc == OK))
    {
        rc = read_file(file, &thing);
        if (rc == OK)
        {
            (*size)++;
            //free(thing);
        }
    }
    free_single_thing(&thing);
    //free(thing);
    if (*size > MAX_THINGS)
    {
        //printf("ERROR MAX THINGS!");
        return ERR_MAX_THINGS;
    }
    if (*size == 0)
    {
        //printf("EMPTY DATA!");
        return ERR_EMPTY;
    }
    return rc;
}