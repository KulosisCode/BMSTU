#include "header.h"

stack_list_t *create_node(const char sym)
{
    stack_list_t *node = malloc(sizeof(stack_list_t));
    if (node)
    {
        node->len = 0;
        node->sym = sym;
        node->next = NULL;
    }
    return node;
}

int add_node_to_list(stack_list_t **head, const char sym)
{
    if ((*head)->len >= MAX_STACK)
        return ERR_OVER_FLOW;
    stack_list_t *node = create_node(sym);

    if (node)
    {
        node->len = (*head)->len + 1;
        node->next = *head;
        *head = node;
    }
    return OK;
}

int list_input(stack_list_t **head)
{
    char sym;
    int count = 0;
    while((scanf("%c", &sym) == 1) && sym != '\n')
    {
        if ((*head) == NULL)
            *head = create_node(sym);
        else
        {
            if (add_node_to_list(head, sym) != OK)
                return ERR_OVER_FLOW;
        }
        count++;
    }

    if (count == 0)
        return ERR_EMPTY_STACK;
    return OK;
}

char pop_stack_list(stack_list_t **head, size_t *locate)
{
    stack_list_t *temp = *head;
    *head = (*head)->next;
    *locate = (size_t)temp;
    char ele = temp->sym;

    return ele;
}

int print_list(stack_list_t **head, locate_t address)
{
    if (!(*head))
        return ERR_EMPTY_STACK;
    
    stack_list_t *temp = *head;
    int size = (*head)->len;
    size_t locate;
    while (size >= 0)
    {
        char ch = pop_stack_list(&temp, &locate);
        printf("\nElement : %c Address : %zx\n", ch, locate);
        size--;
    }

    printf("\nArray free memory area:\n");
    print_address(address);

    return OK;
}

int list_is_palindrome(stack_list_t **head)
{
    stack_list_t *temp = NULL;
    char sym;
    int size = (*head)->len + 1;
    size_t locate = 0;

    for (int i = 0; i < size / 2; i++)
    {
        sym = pop_stack_list(head, &locate);
        if (temp == NULL)
            temp = create_node(sym);
        else
            add_node_to_list(&temp, sym);
    }

    for (int i = 0; i < size % 2; i++)
        pop_stack_list(head, &locate);
    for (int i = 0; i <= (*head)->len; i++)
    {
        if (pop_stack_list(head, &locate) != pop_stack_list(&temp, &locate))
        {
            return NOT_PALINDROME;
        }
    }
    return PALINDROME;
}

void free_list(stack_list_t *head)
{
    stack_list_t *next;

    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}

locate_t *create_address(void)
{
    locate_t *address = malloc(sizeof(locate_t));
    if (!address)
        return NULL;
    address->size =  0;
    address->arr = malloc(MAX_STACK * sizeof(size_t));
    return address;
}

void print_address(const locate_t address)
{
    if (address.size == 0)
        printf("\nArray free memory empty!\n");
    else
    {
        for (int i = 0; i < address.size; i++)
            printf("\n%zx\n", address.arr[i]);
    }
}

int free_array_address(locate_t *address)
{
    if (address)
    {
        if (address->arr)
        {
            free(address->arr);
            free(address);
            return OK;
        }
        free(address);
        return OK;
    }
    return OK;
}