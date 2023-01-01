#include "func.h"

int read_file(FILE *file, stuff *things)
{   
    int n = 0;
    while (fscanf(file, "%s", things[n].name) == 1)
    {
        if (strlen(things[n].name) > MAX_LEN)
            return ERR_DATA;
        if (fscanf(file, "%f", &things[n].weight) != 1)
            return ERR_DATA;
        if (fscanf(file, "%f", &things[n].volume) != 1)
            return ERR_DATA;
        if (things[n].weight <= 0 || things[n].volume <= 0)
            return ERR_DATA;
        n++;
        if (n == MAX_THINGS)
            return ERR_MAX_THINGS;
    }
    if (n == 0)
        return ERR_EMPTY;
    return n;
}

void print_structure(const stuff *const things, const int index)
{
    printf("%s\n", things[index].name);
    printf("%.6f\n", things[index].weight);
    printf("%.6f\n", things[index].volume);
}

void sorted_stuff(stuff *things, const int n)
{
    stuff temp;
    for (int i = 0; i < n; i++)
        things[i].density = things[i].weight / things[i].volume;
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (things[j].density > things[j + 1].density)
            {
                temp = things[j];
                things[j] = things[j + 1];
                things[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag)
            break;
    }
}

void print_info(stuff *things, const int n, int argc, char *filter)
{
    for (int i = 0; i < n; i++)
    {
        if (argc == 2 || strcmp(filter, ALL) == OK)
            print_structure(things, i);
        else 
        {
            if (strncmp(filter, things[i].name, strlen(filter)) == OK)
                print_structure(things, i);
        }
    }
}