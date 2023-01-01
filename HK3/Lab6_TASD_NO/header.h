#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define ERR_IO -1
#define ERR_OPEN -2
#define ERR_ALLOCATE -3
#define ERR_ARGS -4

typedef struct node
{
    int num;
    int height;
    struct node *left;
    struct node *right;
} tree_t;


void to_dot(tree_t *tree, FILE *file);
void export_to_dot(FILE *file, const char *tree_name, tree_t *tree);
tree_t *create_node(int num);
int height(tree_t *node);
void fix_height(tree_t *node);
tree_t *insert_node(tree_t *tree, tree_t *node);
tree_t *create_tree(tree_t *tree, FILE *file);
void print_height(tree_t *tree);

#endif