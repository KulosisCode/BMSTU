#include "header.h"

node_t *create_node(int const num, int const rows, int const cols)
{
    if (num == 0) 
        return NULL;
    node_t *cur = malloc(sizeof(node_t));
    if (cur)
    {
        cur->num = num;
        cur->rows = rows;
        cur->cols = cols;
        cur->next = NULL;
    }
    else
        return NULL;
    return cur;
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

node_t *read_file(FILE *file, int *rc)
{
    node_t *head = NULL;
    int rows, cols;
    if (fscanf(file, "%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
    {
        *rc = ERR_DATA;
        return NULL;
    }
    else 
    {
        int x;
        node_t *cur = NULL;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (fscanf(file, "%d", &x) != 1)
                {
                    *rc = ERR_DATA;
                    free_all_list(head);
                    return NULL;
                }
                else 
                {
                    cur = create_node(x, i, j);
                    head = add_list_end(head, cur);
                }
            }
        }
    }
    return head;
}


void free_all_list(node_t *head)
{
    node_t *next;

    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}