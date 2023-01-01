#include "header.h"

int create_things(stuff *things, const char *name, double weight, double volume)
{
    char *temp_name = NULL;

    temp_name = calloc(strlen(name) + 1, sizeof(char));
    if (temp_name != NULL)
    {
        temp_name = strncpy(temp_name, name, strlen(name));
        if (things->name != NULL)
            free(things->name);

        things->name = temp_name;
        things->weight = weight;
        things->volume = volume;
    }
    else
        return ERR_ALLOCATE;
    return OK;
}