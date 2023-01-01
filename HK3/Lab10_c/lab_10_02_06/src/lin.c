#include "header.h"

int find_max_ele(node_t *node)
{
    int max = node->num, i;
    for (; node; node = node->next)
    {
        if (max < node->num)
        {
            max = node->num;
            i = node->rows;
        }
    }
    return i;
}

// delete row function
node_t *delete_row_matrix(node_t *head, int const rows)
{
    node_t *curr = NULL, *prev = NULL;
    node_t *next = NULL;
    for (curr = head; curr; curr = next)
    {
        next = curr->next;
        if (curr->rows == rows)
        {
            if (prev)
                prev->next = curr->next;
            else 
                head = curr->next;
            free(curr);
        }
        else
            prev = curr;
    }
    return head;
}