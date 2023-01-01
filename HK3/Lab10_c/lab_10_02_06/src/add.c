#include "header.h"

int position(node_t *node_1, node_t *node_2)
{
    if (node_1 && !node_2)
        return FIRST;
    else if (!node_1 && node_2) 
        return SECOND;
    
    if (node_1->rows < node_2->rows)
        return FIRST;
    else if (node_1->rows > node_2->rows)
        return SECOND;
    else if (node_1->rows == node_2->rows)
    {
        if (node_1->cols < node_2->cols)
            return FIRST;
        else if (node_1->cols > node_2->cols)
            return SECOND;
        else if (node_1->cols == node_2->cols)
            return OK;
    }
    return OK;
}

// add funtion
int add_matrix(node_t **result, node_t *mtr_1, node_t *mtr_2)
{
    if (!mtr_1 || !mtr_2)
        return ERR_PARAM;
    
    node_t *curr = mtr_1;
    node_t *pers = mtr_2;
    while (curr || pers)
    {
        node_t *sub = NULL;
        int rc = position(curr, pers);

        if (rc == FIRST)
        {
            sub = create_node(curr->num, curr->rows, curr->cols);
            curr = curr->next;
        }
        else if (rc == SECOND)
        {
            sub = create_node(pers->num, pers->rows, pers->cols);
            pers = pers->next;
        }
        else if (rc == OK)
        {
            sub = create_node(curr->num + pers->num, curr->rows, curr->cols);
            curr = curr->next;
            pers = pers->next;
        }

        if (sub != NULL)
            *result = add_list_end(*result, sub);
    }
    return OK;
}