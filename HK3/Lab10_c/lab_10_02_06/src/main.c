#include "header.h"

int main(void)
{
    setbuf(stdout, NULL);
    node_t *node_1 = NULL, *node_2 = NULL;
    node_t *result = NULL;
    char action[MAX_LEN];

    if (fscanf(stdin ,"%s", action) == 1)
    {
        if (strcmp(action, OUT) == 0)
        {
            int rc = 0;
            node_1 = read_file(stdin, &rc);
            if (rc == OK)
            {
                print_all_node(node_1);
                free_all_list(node_1);
            }
            else
                return message(rc);
        }
        else if (strcmp(action, ADD) == 0)
        {
            int rc = 0;
            node_1 = read_file(stdin, &rc);
            if (rc != OK)
            {   
                free_all_list(node_1);
                return message(rc);
            }
            node_2 = read_file(stdin, &rc);
            if (rc != OK)
            {
                free_all_list(node_1);
                free_all_list(node_2);
                return message(rc);
            }

            rc = add_matrix(&result, node_1, node_2);
            free_all_list(node_1);
            free_all_list(node_2);
            if (rc != OK)
                return message(rc);
            else 
                print_all_node(result);
            
            free_all_list(result);
        }
        else if (strcmp(action, MUL) == 0)
        {
            int rc = 0;
            node_1 = read_file(stdin, &rc);
            if (rc != OK)
            {   
                free_all_list(node_1);
                return message(rc);
            }
            node_2 = read_file(stdin, &rc);
            if (rc != OK)
            {
                free_all_list(node_1);
                free_all_list(node_2);
                return message(rc);
            }

            rc = mul_matrix(&result, node_1, node_2);
            free_all_list(node_1);
            free_all_list(node_2);
            if (rc != OK)
                return message(rc);
            else 
                print_all_node(result);
            
            free_all_list(result);
        }
        else if (strcmp(action, LIN) == 0)
        {
            int rc = 0;
            node_1 = read_file(stdin, &rc);
            if (rc != OK)
                return message(rc);
            else
            {
                int i = find_max_ele(node_1);
                node_1 = delete_row_matrix(node_1, i);
            }
            print_all_node(node_1);
            free_all_list(node_1);
        }
        else
        {
            //
            return ERR_ACTION;
        }
    }
    return EXIT_SUCCESS;
}