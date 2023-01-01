#ifndef _TREE_H_
#define _TREE_H_

#include"define.h"

typedef struct tree_node node_t;
// узел дерева
struct tree_node
{
    char *word;
    int balance;
    struct tree_node *left;
    struct tree_node *right;
};

// создание нового узла
struct tree_node* create_node(char *word);

void count_node_tree(node_t *tree, int *sum);
node_t* create_tree(node_t *root, FILE *f);
node_t* create_bal_tree(node_t *root, FILE *f);
void export_to_dot(FILE *f, const char *tree_name, struct tree_node *tree);

struct tree_node* bal_insert(struct tree_node *root, struct tree_node *node);
node_t* balance(node_t* p);
node_t* rotateleft(node_t* q);
node_t* rotateright(node_t* p);
void fixheight(node_t* p);
int height(node_t* p);
int bfactor(node_t* p);

node_t *search(char *rem, node_t *tree, int *done, int *flag);

void menu(void);

#endif
