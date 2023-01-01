#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OK 0
#define ERR_ALLOCATE 1
#define ERR_INPUT 2
#define ERR_EMPTY 3

typedef struct node
{
    int num;
    struct node *next;
} node_t;

node_t *create_node(int num)
{
    node_t *cur = malloc(sizeof(node_t));
    if (cur)
    {
        cur->num = num;
        cur->next = NULL;
    }
    return cur;
}

node_t *insert_front(node_t *head, node_t *node)
{
    if (!head)
        return node;
    if (!node)
        return head;
    node->next = head;

    return node;
}

void free_thing(node_t *head)
{
    if (!head)
        return;
    node_t *cur = head;
    node_t *next;
    for (; cur; cur = next)
    {
        next = cur->next;
        free(cur);
    }
}

void print_thing(node_t *head)
{
    node_t *cur = head;
    for (; cur; cur = cur->next)
    {
        printf("%d ", cur->num);
    }
}

int main(void)
{
    int num;
    node_t *pos = NULL, *neg = NULL;

    int run = 1;
    node_t *node = NULL;
    while (run)
    {
        if (scanf("%d", &num) == 1)
        {
            if (num == 0)
            {
                run = 0;
                break;
            }
            node = create_node(num);
            if (!node)
            {
                free_thing(pos);
                free_thing(neg);
                return ERR_ALLOCATE;
            }
            else if (num < 0)
            {
                neg = insert_front(neg, node);
            }
            else
            {
                pos = insert_front(pos, node);
            }
        }
        else
        {
            free_thing(pos);
            free_thing(neg);
            return ERR_INPUT;
        }
    }
    print_thing(pos);
    printf("\n");
    print_thing(neg);
    node_t *cur = pos;
    if (!cur)
        cur = neg;
    else
    {
        for(; cur->next; cur = cur->next)
        {

        }
        cur->next = neg;
    }  
    print_thing(pos);
    free_thing(pos);
    //free_thing(neg);
    return OK;
}

{
    //     #include <stdio.h>
    // #include <stdlib.h>

    // #define OK 0
    // #define ERR_INPUT 1
    // #define ERR_ALLOCATE 2

    // int *input_number(FILE *file, int *rc, int *n)
    // {
    //     *rc = OK;
    //     int *arr;
    //     int num, x;
    //     if (fscanf(file, "%d", &num) == 1 && num > 0)
    //     {
    //         arr = malloc (num * sizeof(int));
    //         if (!arr)
    //         {
    //             *rc = ERR_ALLOCATE;
    //             return NULL;
    //         }
    //     }
    //     else 
    //     {
    //         *rc = ERR_INPUT;
    //         return NULL;
    //     }
    //     for (int i = 0; i < num; i++)
    //     {
    //         if (fscanf(file, "%d", &x) == 1)
    //         {
    //             arr[i] = x;
    //         }
    //         else
    //         {
    //             *rc = ERR_INPUT;
    //             return NULL;
    //         }
    //     }
    //     *n = num;
    //     return arr;
    // }

    // void print_arr(int *arr, int n)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         printf("%d ", arr[i]);
    //     }
    //     printf("\n");
    // }

    // void change_locate(int *arr, int n)
    // {
    //     if (arr == NULL || n <= 0)
    //         return;
            
    //     int index = 0;
    //     int min = arr[0];
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (min > arr[i])
    //         {
    //             index = i;
    //         }
    //     }
        
    //     if (index != 0)
    //     {
    //         int tmp = arr[0];
    //         arr[0] = arr[index];
    //         arr[index] = tmp;
    //     }
    // }


    // int main(void)
    // {
    //     int *arr;
    //     int rc = OK;
    //     int n;
        
    //     arr = input_number(stdin, &rc, &n);
    //     if (rc != OK)
    //     {
    //         printf("ERROR: %d", rc);
    //         return rc;
    //     }
    //     else
    //     {
    //         change_locate(arr, n);
    //         print_arr(arr, n);
    //     }
    //     if (arr)
    //         free(arr);
    //     return OK;
    // }
}