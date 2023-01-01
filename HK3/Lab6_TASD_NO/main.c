#include "header.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
    {
        printf("ERROR ARGS!\n");
        return ERR_ARGS;
    }
    tree_t *tree = NULL;
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("ERROR OPEN FILE!\n");
        return ERR_OPEN;
    }
    tree = create_tree(tree, file);
    fclose(file);
    
    FILE *f = fopen("tree.dot", "w");
    export_to_dot(f, "tree", tree);
    fclose(f);
    system("dot -Tpng tree.dot -o tree.png");
    print_height(tree);

    return OK;
}