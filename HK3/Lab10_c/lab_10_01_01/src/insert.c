#include "header.h"

void insert(node_t **head, node_t *elem, node_t *before)
{
    if (*head && elem)
    {
        node_t *cur = NULL;
        cur = *head;
        if (cur == before)
        {
            elem->next = *head;
            *head = elem;
        }
        else
        {
            for (; cur; cur = cur->next)
            {
                if (cur->next == before)
                {
                    cur->next = elem;
                    elem->next = before;
                    break;
                }
            }
        }
    }
}