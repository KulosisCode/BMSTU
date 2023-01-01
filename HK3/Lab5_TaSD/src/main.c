#include "header.h"

int main(void)
{
    setbuf(stdout, NULL);
    array_queue_t array;
    array.head = -1;
    array.last = -1;
    array.len = 0;

    list_queue_t list;
    list.head = malloc(sizeof(node_t));
    list.last = malloc(sizeof(node_t));
    list.head->next = list.last;
    list.head->elem = ZERO;
    list.last->next = NULL;
    list.last->elem= ZERO;
    list.len = 0;

    int command;
    int elem;

    size_t *free_elem = calloc(MAX_ELEM, sizeof(size_t));
    int count_free = 0;

    int run = 1;
    while(run)
    {
        menu();
        if ((scanf("%d", &command) == 1) && command >= MIN_COMMAND && command <= MAX_COMMAND)
        {
            int code = 0;
            switch (command)
            {
                case 1:
                {
                    }
                    printf("\nInput a number: ");
                    code =  input_number(&elem);
                    if (code == OK)
                    {
                        if (array_queue_add(&array, elem) == OK)
                            printf("\nAdd elment successfully!\n");
                        else
                            printf("\nQueue is full\n");
                    }
                    else
                    {
                        clear();
                        message(code);
                    break;
                }
                case 2:
                {
                    if (array.len == 0)
                        printf("Queue is empty!\n");
                    else
                    {
                        elem = array_queue_pop(&array);
                        printf ("\nDelete element : %d\n", elem);
                    }
                    break;
                }
                case 3:
                {
                    if (array.len == 0)
                        printf("Queue is empty!\n");
                    else
                    {
                        print_array_queue(array);
                    }
                    break;
                }
                case 4:
                {
                    array_queue_process();
                    break;
                }
                case 5:
                {
                    printf("\nInput a number: ");
                    code =  input_number(&elem);
                    if (code == OK)
                    {
                        if (list_queue_add(&list, elem) == OK)
                        {
                            printf("\nAdd elment successfully!\n");
                        }
                        else
                            printf("\nQueue is full\n");
                    }
                    else
                        message(code);
                    break;
                }
                case 6 :
                {
                    if (list.len == 0)
                        printf("Queue is empty!\n");
                    else
                    {
                        free_elem[count_free++] = (size_t)list.head->next;
                        elem = list_queue_pop(&list);
                        printf ("\nDelete element : %d\n", elem);
                    }
                    break;
                }
                case 7:
                {
                    if (list.len == 0)
                        printf("Queue is empty!\n");
                    else
                    {
                        print_list(list);
                        print_address_free(free_elem, count_free);
                    }
                    break;
                }
                case 8:
                {
                    list_queue_process();
                    break;
                }
                case 9:
                {
                    time_effect();
                    break;
                }
                case 0:
                {
                    free_list(&list);
                    free(free_elem);
                    run = 0;
                    break;
                }
            }
        }
        else
        {
            message(ERR_COMMAND);
            fgetc(stdin);
        }
    }
    return OK;
}