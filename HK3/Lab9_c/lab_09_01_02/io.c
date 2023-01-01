#include "header.h"

void print_structure(FILE *out, stuff *things)
{
    fprintf(out, "%s\n", things->name);
    fprintf(out, "%.6lf\n", things->weight);
    fprintf(out, "%.6lf\n", things->volume);
}

void print_info(stuff *things, const size_t n, int argc, char *filter)
{
    stuff *bg = things;
    for (size_t i = 0; i < n; i++)
    {
        if (argc == 2 || strcmp(filter, ALL) == OK)
            print_structure(stdout, bg);
        else
        {
            if (strncmp(filter, bg->name, strlen(filter)) == OK)
                print_structure(stdout, bg);
        }
        bg++;
    }
}

//free objects
void free_single_thing(stuff *thing)
{
    free(thing->name);
}

void free_things(stuff *things, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((things + i))
        {
            free_single_thing((things + i));
        }
    }
    free(things);
}
