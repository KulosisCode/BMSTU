#include <stdlib.h>

#include "list_funcs.h"

node_t* create_node()
{
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node)
    {
        new_node->next = NULL;
        new_node->name = NULL;
        new_node->year = 0;
        new_node->group = NULL;
    }
    return new_node;
}
void add_last_node(node_t** head, node_t* new_node)
{
    if (*head == NULL)
        *head = new_node;
    else
    {
        node_t* cur = *head;
        while (cur->next)
            cur = cur->next;
        cur->next = new_node;
    }
}

void print_list(node_t* head)
{
    node_t* cur = head;
    for (; cur; cur = cur->next)
    {
        printf("%s\n%d\n%s\n", cur->name, cur->year, cur->group);
        printf("\n");
    }
}

void free_list(node_t* head)
{
    node_t* cur = head;
    for (; cur->next;)
    {
        node_t* temp = cur->next;
        free_node(cur);
        cur = temp;
    }
    free_node(cur);
}

void free_node(node_t* cur_node)
{
    free(cur_node->name);
    free(cur_node->group);
    free(cur_node);
}