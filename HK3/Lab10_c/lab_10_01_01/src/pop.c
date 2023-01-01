#include "header.h"

void *pop_front(node_t **head)
{
    node_t *new = NULL;
    void *data = NULL;
    if (head && (*head))
    {
        data = (*head)->data;
        new = (*head)->next;
        (*head)->next = NULL;
        free(*head);
        *head = new;
    }
    return data;
}