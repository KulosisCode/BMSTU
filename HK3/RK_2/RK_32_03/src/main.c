#include <stdio.h>

#include "define.h"
#include "funcs.h"
#include "list_funcs.h"
#include "struct.h"

int main(int argc, char** argv)
{
    if (argc < MIN_ARGS || argc > MAX_ARGS)
    {
        printf("ERROR ARGS!\n");
        return ARG_ERROR;
    }

    int rc;
    FILE* f = fopen(argv[1], "r");
    if (!f)
    {
        printf("ERROR OPEN FILE!\n");
        return OPEN_FILE_ERROR;
    }

    node_t* list = NULL;
    rc = create_list(&list, f);
    if (rc == OK)
    {
        if (argc == 2)
        {
            print_list(list);
            free_list(list);
        }
        else if (argc == 3)
        {
            node_t* student_list = create_group_list(argv[2], list);
            if (student_list != NULL)
            {
                print_list(student_list);
                free_list(student_list);
            }
            else
            {
                printf("NO Student!");
                return OK;
            }
        }
    }
    else 
    {
        printf("ERROR CREATE LIST!\n");
        if (list)
            free_list(list);
    }
    fclose(f);
    return OK;
}