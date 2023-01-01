#include "header.h"

int len_list(hash_t *head)
{
    int len = 0;
    for (; head; head = head->next)
        len++;
    return len;
}

int next_prime_number(int number)
{
    while (1)
    {
        int count_del = 0;
        number++;
        for (int i = 2; i < number - 1; i++)
            if (!(number % i))
                count_del++;

        if (!count_del)
            return number;
    }
}

hash_t *create_node(int num)
{
    hash_t *node = malloc(sizeof(hash_t));
    if (node)
    {
        node->num = num;
        node->next = NULL;
    }
    else
        return NULL;
    return node;
}

hash_t *add_node_end(hash_t *head, hash_t *node)
{
    if (!head)
        return node;
    hash_t *cur = head;
    for (; cur->next; cur = cur->next)
    {
        if (cur->num == node->num)
            return head;
    }
    cur->next = node;
    return head;
}

int calc_index(int num, int len_table)
{
    int hash = 0;
    int pow = 1;
    int tmp = num;
    if (tmp < 0)
        tmp = -tmp;
    while (tmp != 0)
    {
        int end_num = tmp % 10;
        hash += (end_num + 1) * pow;
        pow *= NUM_HASH;

        tmp /= 10;
    }
    return hash % len_table;
}

hash_t **insert_hash_table(hash_t **table, int *len_table, hash_t *node)
{
    int index = calc_index(node->num, *len_table);
    table[index] = add_node_end(table[index], node);
    int len = len_list(table[index]);

    hash_t **new_table;
    int new_len;

    while (len > MAX_LIST)
    {
        new_len = next_prime_number(*len_table);
        new_table = calloc(new_len, sizeof(hash_t));

        for (int i = 0; i < *len_table; i++)
        {
            for (hash_t *j = table[i]; j; j = j->next)
            {
                int tmp = j->num;
                node = create_node(tmp);
                index = calc_index(node->num, new_len);
                new_table[index] = add_node_end(new_table[index], node);
            }
        }

        len = 0;
        for (int i = 0; i < new_len; i++)
            if (len_list(new_table[i]) > len)
                len = len_list(new_table[i]);

        free(table);
        *len_table = new_len;
        table = new_table;
    }

    return table;
}

hash_t **build_table(FILE *f, int *len_table)
{
    hash_t **table = NULL;
    hash_t *node;
    int num;

    table = calloc(*len_table, sizeof(hash_t *));

    while (!feof(f))
    {
        if (fscanf(f, "%d", &num) == 1)
        {
            node = create_node(num);
            table = insert_hash_table(table, len_table, node);
        }
    }
    return table;
}

void search_in_hash_table(int num, hash_t **table, int len_table, int *done, int *compare)
{
    int index = calc_index(num, len_table);
    hash_t *cur = table[index];

    *done = 0;
    *compare = 0;
    for (; cur; cur = cur->next)
    {
        (*compare)++;
        if (num == cur->num)
        {
            *done = 1;
            return;
        }
    }
    *done = 0;
}

void print_table(hash_t **table, int len_table)
{
    for (int i = 0; i < len_table; i++)
    {
        printf("%d )", i);
        hash_t *cur = table[i];
        for (; cur; cur = cur->next)
        {
            printf(" -> %d", cur->num);
        }
        if (!cur)
            printf(" -> NULL\n");
    }
    printf("\n");
}