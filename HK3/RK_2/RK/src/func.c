#include "header.h"

node_t *create_node(const char *name, const int year, const char *group)
{
    if (name == NULL || group == NULL)
        return ERR_PARAM;
    char *temp_name = NULL;
    strcpy(temp_name, name);
    char *temp_gr = NULL;
    strcpy(temp_gr, group);
    node_t *node = malloc(sizeof(node_t));
    if (node && temp_name != NULL && temp_gr != NULL)
    {
        node->name = temp_name;
        node->year = year;
        node->group = temp_gr;
        node->next = NULL;
    }
    return node;
}

node_t *add_node_end(node_t *head, node_t *per)
{
    node_t *cur = head;
    if (!head)
        return per;
    for (; cur->next; cur = cur->next);
    cur->next = per;
    return head;
}

char *read_char(FILE *file)
{
    int count = 0;
    char ch;
    char *name = NULL;
    if (fscanf(file, "%c", ch) == 1 && ch != '\n' && ch != EOF)
    {
        count++;
        char *tmp = NULL;
        tmp = realloc(name, count * sizeof(char) + 1);
        if (tmp)
            name  = tmp;
        name[count - 1] = ch;
    }
    if (count == 0)
        return NULL;
    name[count - 1] = '\0';
    return name;
}

int input(FILE *file ,node_t **head)
{
    if (!head)
        return ERR_PARAM;
    char *name = NULL;
    int year;
    char *group = NULL;

    
}

