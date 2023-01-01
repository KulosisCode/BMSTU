#include "header.h"

void to_dot(tree_t *tree, FILE *file)
{
    if (tree == NULL || file == NULL)
        return;

    if (tree->left)
        fprintf(file, "\"%d \" -> \"%d \";\n", tree->num, tree->left->num);
    if (tree->right)
        fprintf(file, "\"%d \" -> \"%d \";\n", tree->num, tree->right->num);
    
    to_dot(tree->left, file);
    to_dot(tree->right, file);
}

void export_to_dot(FILE *file, const char *tree_name, tree_t *tree)
{
    fprintf(file, "digraph %s {\n", tree_name);
    to_dot(tree, file);
    fprintf(file, "}\n");
}

tree_t *create_node(int num)
{
    tree_t *node;
    node = malloc(sizeof(tree_t));
    if (node)
    {
        node->num = num;
        node->height = 0;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

int height(tree_t *node)
{
    return node ? node->height : 0;
}

void fix_height(tree_t *node)
{
    int left = height(node->left);
    int right = height(node->right);
    node->height = (left > right ? left : right) + 1;
}

tree_t *insert_node(tree_t *tree, tree_t *node)
{
    if (tree == NULL)
        return node;
    if (node->num < tree->num)
    {
        tree->left = insert_node(tree->left, node);
        fix_height(tree);
    }
    else if (node->num > tree->num)
    {
        tree->right = insert_node(tree->right, node);
        fix_height(tree);
    }
    fix_height(tree);
    return tree;
}

tree_t *create_tree(tree_t *tree, FILE *file)
{
    tree_t *node;
    int tmp;
    while(!feof(file))
    {
        if (fscanf(file, "%d", &tmp) == 1)
        {
            node = create_node(tmp);
            tree = insert_node(tree, node);
        }
    }
    return tree;
}

void print_height(tree_t *tree)
{
    if (tree == NULL)
        return;
    
    printf("node : %d -- height : %d\n", tree->num, tree->height);
    if (tree->left)
    {
        print_height(tree->left);
    }
    if (tree->right)
    {
        print_height(tree->right);
    }
}