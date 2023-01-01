#include "header.h"

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *back = NULL;
    if ((head) && (head->next))
    {
        front_back_split(head, &back);
        head = sort(head, comparator);
        back = sort(back, comparator);
        head = sorted_merge(&head, &back, comparator);
    }
    return head;
}

void front_back_split(node_t *head, node_t **back)
{
    int count = 0;
    node_t *cur = head;
    node_t *prev = NULL;
    for (; cur; cur = cur->next)
        count++;
    if (count <= 1)
        *back = NULL;
    else
    {
        count -= (count / 2);
        cur = head;
        for (int i = 0; i < count; i++, cur = cur->next)
            prev = cur;
        *back = cur;
        prev->next = NULL;
    }
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    node_t *result = NULL;
    node_t *cur = NULL;

    while (*head_a || *head_b)
    {
        if (*head_a && !(*head_b))
        {
            if (!cur)
            {
                cur = *head_a;
                result = cur;
            }
            else
            {
                cur->next = *head_a;
                cur = cur->next;
            }
            *head_a = (*head_a)->next;
            cur->next = NULL;
        }
        else if (!(*head_a) && *head_b)
        {
            if (!cur)
            {
                cur = *head_b;
                result = cur;
            }
            else
            {
                cur->next = *head_b;
                cur = cur->next;
            }
            *head_b = (*head_b)->next;
            cur->next = NULL;
        }
        else
        {
            if (comparator((*head_a)->data, (*head_b)->data) <= 0)
            {
                if (!cur)
                {
                    cur = *head_a;
                    result = cur;
                }
                else
                {
                    cur->next = *head_a;
                    cur = cur->next;
                }
                *head_a = (*head_a)->next;
                cur->next = NULL;
            }
            else
            {
                if (!cur)
                {
                    cur = *head_b;
                    result = cur;
                }
                else
                {
                    cur->next = *head_b;
                    cur = cur->next;
                }
                *head_b = (*head_b)->next;
                cur->next = NULL;
            }
        }
    }
    return result;
}
