#include "header.h"

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
    if (!head || !(*head))
        return;
    else
    {
        node_t *cur = *head;
        node_t *next = NULL;
        while (cur && cur->next)
        {
            next = cur->next;
            if (comparator(cur->data, next->data) == 0)
            {
                cur->next = next->next;
                next->next = NULL;
                //free(next->data); // memem
                free(next);
            }
            else
                cur = cur->next;
        }
    }
}