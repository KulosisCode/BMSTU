#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_HASH 15
#define MAX_LIST 3

#define OK 0
#define ERR_ARGS -1
#define ERR_OPEN -2
#define ERR_ALLOCATE -3
#define ERR_IO -4

typedef struct node
{
    int num;
    struct node *next;
} hash_t;

int len_list(hash_t *head);
int next_prime_number(int number);
hash_t *create_node(int num);
hash_t *add_node_end(hash_t *head, hash_t *node);
int calc_index(int num, int len_table);
hash_t **insert_hash_table(hash_t **table, int *len_table, hash_t *node);
hash_t **build_table(FILE *f, int *len_table);
void search_in_hash_table(int num, hash_t **table, int len_table, int *done, int *compare);
void print_table(hash_t **table, int len_table);

#endif
