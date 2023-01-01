#include "header.h"

int main()
{
    setbuf(stdout, NULL);
    int command;
    stack_arr_t array;
    array.len = 0;
    stack_list_t *list = NULL;
    locate_t *address = NULL;
    int run = 1;
    int check = 0;
    while (run)
    {
        menu();
        if (check)
        {
            check = 0;
            clear();
        }
        if ((scanf("%d", &command) == 1) && command >= MIN_COMMAND && command <= MAX_COMMAND)
        {
            int code = 0;
            switch (command)
            {
                case 1:
                {
                    clear();
                    if (array.len > 0)
                        printf("Stacks was created before!\n");                  
                    else if ((code = array_input(&array)) == OK)
                        printf("Stacks was created successfully!\n");
                    else
                        message(code);
                    if (code == ERR_OVER_FLOW)
                        check = 1;
                    break;
                }
                case 2:
                {
                    clear();
                    printf("Input symbol: ");
                    char sym;
                    input_symbol(&sym);
                    if ((code = add_symbol_to_arr(&array, sym)) == OK)
                    {
                        printf("Add successfully!\n");
                    }
                    else
                        message(code);
                    clear();
                    break;
                }
                case 3:
                {
                    if (array.len == 0)
                        printf("Stacks is empty!\n");
                    else
                    {
                        pop_stack_array(&array);
                        printf("Element was delete!\n");
                    }
                    break;
                }
                case 4:
                {
                    if (array.len == 0)
                        printf("Stacks is empty!\n");
                    else
                    {
                        stack_arr_t temp;
                        temp.len = array.len;
                        strcpy(temp.array, array.array);

                        if (array_is_palindrome(&temp) == PALINDROME)
                            printf("PALINDROME!\n");
                        else
                            printf("NOT PALINDROME!\n");
                    }
                    break;
                }
                case 5:
                {
                    if ((code = print_array(&array)) != OK)
                        message(code);
                    break;
                }
                case 6:
                {
                    clear();
                    if (list != NULL)
                        printf("Stacks was created before!\n");                  
                    else if ((code = list_input(&list)) == OK)
                    {   
                        address = create_address();
                        printf("Stacks was created successfully!\n");
                    }
                    else
                        message(code);
                    if (code == ERR_OVER_FLOW)
                        check = 1;
                    break;
                }
                case 7:
                {
                    clear();
                    printf("Input symbol: ");
                    char sym;
                    input_symbol(&sym);
                    if (list == NULL)
                    {
                        printf("Stacks not exist!\n");
                    }
                    else if ((code = add_node_to_list(&list, sym)) == OK)
                    {
                        printf("Add successfully!\n");
                    }
                    else
                        message(code);
                    clear();
                    break;
                }
                case 8:
                {
                    if (!list)
                        printf("Stacks is empty!\n");
                    else
                    {
                        size_t locate = 0;
                        pop_stack_list(&list, &locate);
                        address->arr[address->size++] = locate;
                        printf("Element was delete!\n");
                    }
                    break;
                }
                case 9:
                {
                    if (!list)
                        printf("Stacks is empty!");
                    else
                    {
                        stack_list_t *temp = list;
                        //temp->len =  list->len;

                        if (list_is_palindrome(&temp) == PALINDROME)
                            printf("PALINDROME!\n");
                        else
                            printf("NOT PALINDROME!\n");
                    }
                    break;
                }
                case 10:
                {
                    if (!list)
                        printf("Stacks is empty!\n");
                    else 
                    {
                        if ((code = print_list(&list, *address)) != OK)
                            message(code);
                    }
                    break;
                }
                case 11:
                {
                    time_effect();
                    break;
                }
                case 0:
                {
                    free_list(list);
                    free_array_address(address);
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