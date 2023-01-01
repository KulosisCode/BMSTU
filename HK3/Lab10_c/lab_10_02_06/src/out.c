#include "header.h"

int message(int rc)
{
    switch (rc)
    {
        case -1: 
            printf("ERROR DATA."); 
            break;
        case -2: 
            printf("ERROR READING."); 
            break;
        case -3: 
            printf("ERROR OPENING."); 
            break;
        case -4: 
            printf("ERROR ALLOCATING."); 
            break;
        case -5: 
            printf("ERROR PARAMETER."); 
            break;
        case -6: 
            printf("ERROR ACTION."); 
            break;
        default:
            break;
    }
    return rc;
}

void print_all_node(node_t *head)
{
    node_t *cur = head;

    for (; cur; cur = cur->next)
    {
        printf("%d ", cur->rows);
        printf("%d ", cur->cols);
        printf("%d ", cur->num);
    }
}