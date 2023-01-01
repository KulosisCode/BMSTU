#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "funcs.h"
#include "define.h"
#include "list_funcs.h"

int create_list(node_t** root, FILE *f)
{
    char name[MAX_LEN + 1] = { 0 };
    int year;
    char group[MAX_LEN + 1] = { 0 };
    int rc;
    int is_empty_file = TRUE;
    while ((rc = fscanf(f, "%s", name)) == 1)
    {
        if (strlen(name) > MAX_NAME)
            return ERR_LEN;
        node_t* student = malloc(sizeof(node_t));
        if (!student)
            return MALLOC_ERROR;
        student->name = malloc(sizeof(char) * strlen(name) + 1);
        if (!student->name)
            return MALLOC_ERROR;
        strcpy(student->name, name);

        if ((rc = fscanf(f, "%d", &year)) != 1 || year < 0)
            return INPUT_ERROR;
        student->year = year;

        if ((rc = fscanf(f, "%s", group)) != 1)
            return INPUT_ERROR;
        if (strlen(group) > MAX_GROUP)
            return ERR_LEN;
        student->group = malloc(sizeof(char) * strlen(name) + 1);
        if (!student->group)
            return MALLOC_ERROR;
        strcpy(student->group, group);

        student->next = NULL;

        is_empty_file = FALSE;
        add_last_node(root, student);
    }   
    if (is_empty_file)
        return EMPTY_FILE_ERROR;
    return OK;
}
node_t* create_group_list(char* group_name, node_t* list)
{
    node_t* student_list = NULL;
    
    node_t* cur = list;
    for (; cur; cur = cur->next)
    {
        if (strcmp(cur->group, group_name) == 0)
        {
            node_t* new_node = create_node();
            if (!new_node)
                return NULL;
            new_node->name = malloc(sizeof(char) * strlen(cur->name) + 1);
            new_node->group = malloc(sizeof(char) * strlen(cur->group) + 1);
            if (!new_node->name || !new_node->group)
                return NULL;

            strcpy(new_node->name, cur->name);
            strcpy(new_node->group, cur->group);
            new_node->year = cur->year;
            add_last_node(&student_list, new_node);
        }
    }

    return student_list;
}
