#include "header.h"

// multiply function
int mul_matrix(node_t **result, node_t *node_1, node_t *node_2)
{
    if (!node_1 || !node_2)
        return ERR_PARAM;
    
    node_t *curr1 = node_1;
    node_t *curr2 = NULL;
    node_t *res = NULL;

    int value = 0;
    int max_cols = 0;
    for (node_t *node = node_2; node; node = node->next)
        if (node->cols > max_cols)
            max_cols = node->cols;

    for (int i = 0; curr1; i++)
    {
        if (curr1->rows == i)
        {
            for (int j = 0; j <= max_cols; j++)
            {
                value = 0;
                curr2 = node_2;
                node_t *node_01 = curr1;
                while (node_01 && node_01->rows == i && curr2)
                {
                    if (curr2->cols != j)
                        curr2 = curr2->next;
                    else
                    {
                        if (curr2->rows > node_01->cols)
                            node_01 = node_01->next;
                        else if (curr2->rows == node_01->cols)
                        {
                            value += node_01->num * curr2->num;
                            node_01 = node_01->next;
                            curr2 = curr2->next;
                        }
                        else
                            curr2 = curr2->next;
                    }
                }
                if (value != 0)
                {
                    res = create_node(value, i, j);
                    *result = add_list_end(*result, res);
                }
            }
        }
        while (curr1 && (curr1->rows == i))
            curr1 = curr1->next;
    }
    return OK;
}