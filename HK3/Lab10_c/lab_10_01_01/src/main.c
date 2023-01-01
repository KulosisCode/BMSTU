#include "header.h"

void free_all_node(node_t *head)
{
    node_t *next;

    for (; head; head = next)
    {
        next = head->next;
        head->next = NULL;
        free(head->data);
        free(head);
    }
}

int main(void)
{
    node_t *head = NULL;
    int rc = 0;
    FILE *file = fopen("a.txt", "r");
    if (file)
    {
        head = read_file(file, &rc);
        if (rc == OK)
        {
            if (head == NULL)
            {
                printf("EMPTY DATA.\n");
                return ERR_DATA;
            }
            // show node
            printf("DATA : ");
            print_all_node(head);

            //sort
            printf("DATA AFTER SORT : ");
            head = sort(head, comparator);
            print_all_node(head);

            //test pop
            void *value = pop_front(&head);
            printf("Value have been pop : %d\n", *(int *)value);
            printf("DATA AFTER POP : ");
            free(value); // free mem
            print_all_node(head);
            if (head == NULL)
                return OK;

            //test insert 10 in index 2
            node_t *node = head;
            if (node)
                node = node->next;
            int x = 10;
            node_t *elem = malloc(sizeof(node_t));
            int *data = malloc(sizeof(int)); //mem
            *data = x;
            elem->data = data;
            elem->next = NULL;
            insert(&head, elem, node);
            printf("DATA AFTER INSERT : ");
            print_all_node(head);

        
            //remove_duplicates
            printf("DATA AFTER REMOVE_DUP : ");
            remove_duplicates(&head, comparator);
            print_all_node(head);

            free_all_node(head);
        }
        else
        {
            printf("ERROR DATA.\n");
            return ERR_DATA;
        }
        fclose(file);
    }
    else
    {
        printf("ERROR OPENING.\n");
        return ERR_OPEN;
    }
    return EXIT_SUCCESS;
}
