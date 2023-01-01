#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
// #define STOP 1
#define EQUAL 0
#define MORE 1
#define LESS -1

#define ERR_DATA -1
#define ERR_ALLOCCATED -2
#define ERR_READ -3
#define ERR_PARAM -4
#define ERR_OPEN -5


typedef struct node node_t;
struct node
{
    void *data;
    node_t *next;
};

node_t *create_node(int x);
node_t *add_list_end(node_t *head, node_t *pers);
node_t *read_file(FILE *file, int *exit);
void free_all_list(node_t *head);
void print_all_node(node_t *head);

int comparator(const void *a, const void *b);
//task 1
void *pop_front(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);

//task 2
void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*));

//task 3
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void front_back_split(node_t *head, node_t **back);
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));
#endif