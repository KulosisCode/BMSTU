#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OUT "out"
#define ADD "add"
#define MUL "mul"
#define LIN "lin"
#define FIRST 1
#define SECOND 2
#define MAX_LEN 5


#define OK 0
#define ERR_DATA -1
#define ERR_READ -2
#define ERR_OPEN -3
#define ERR_ALLOCATE -4
#define ERR_PARAM -5
#define ERR_ACTION -6

typedef struct node
{
    int num;
    int rows;
    int cols;
    struct node *next;
} node_t;

//io
node_t *create_node(int const num, int const rows, int const cols);
node_t *add_list_end(node_t *head, node_t *pers);
node_t *read_file(FILE *file, int *rc);

void free_all_list(node_t *head);
void print_all_node(node_t *head);
int message(int rc);

// matrix processing
int position(node_t *node_1, node_t *node_2);
int add_matrix(node_t **result, node_t *mtr_1, node_t *mtr_2);

int mul_matrix(node_t **result, node_t *node_1, node_t *node_2);

int find_max_ele(node_t *node);
node_t *delete_row_matrix(node_t *head, int const rows);

#endif