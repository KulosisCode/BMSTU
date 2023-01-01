#include "header.h"

node_t *create_node(int x)
{
    node_t *curr = malloc(sizeof(node_t));
    int *temp = (int *)malloc(sizeof(int));
    *temp = x;
    if (curr)
    {
        curr->data = temp;
        curr->next = NULL;
    }
    else 
        return NULL;
    return curr;
}

node_t *add_list_end(node_t *head, node_t *pers)
{
    node_t *cur = head;

    if (!head)
        return pers;
    
    for (; cur->next; cur = cur->next);
    cur->next = pers;
    return head;
}

node_t *read_file(FILE *file, int *exit)
{
    if (file == NULL)
    {
        *exit = ERR_PARAM;
        return NULL;
    }

    node_t *head = NULL;
    node_t *cur = NULL;
    int run = 1, rc = 0;
    int data;
    while (run)
    {
        if ((rc = fscanf(file, "%d", &data)) == 1)
        {
            // int *x = malloc(sizeof(int));
            // *x = data;
            cur = create_node(data);
            head = add_list_end(head, cur);
        }
        else if (rc == EOF)
            break;
        else
        {
            
            *exit = ERR_DATA;
            free_all_list(head);
            return NULL;
        }
    }
    return head;
}

void print_all_node(node_t *head)
{
    node_t *cur = head;

    for (; cur; cur = cur->next)
    {
        int *num = (int *)cur->data;
        printf("%d ", *num);
    }
    printf("\n");
}

void free_all_list(node_t *head)
{
    node_t *next;

    for (; head; head = next)
    {
        next = head->next;
        head->next = NULL;
        free(head);
    }
}