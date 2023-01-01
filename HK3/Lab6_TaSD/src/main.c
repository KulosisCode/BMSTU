#include "define.h"
#include"tree.h"
#include "hash.h"
#include "efficiency.h"

int main()
{
    int done;

    node_t *root = NULL;
    node_t *bal_root = NULL;

    FILE *f;
    f = fopen(DATA_NAME, "r");
    root = create_tree(root, f);
    rewind(f);
    bal_root = create_bal_tree(bal_root, f);
    fclose(f);
    int x = 1;

    node_hash **table = NULL;
    int len_table = 0;

    while(x)
    {
        menu();
        int choice;
        if (scanf("%d", &choice) != 1 || choice < 0 || choice > 9)
        {
            printf("Wrong choice!\n");
            continue;
        }

        switch(choice)
        {
            case 1:
            {
                FILE *f = fopen(TREE_FILE_NAME, "w");
                export_to_dot(f, "test_tree", root);
                // system("dot -Tpng tree.dot -o tree.png");
                fclose(f);
                break;
            }
            case 2:
            {
                FILE *f = fopen(BAL_TREE_FILE_NAME, "w");
                export_to_dot(f, "test_tree", bal_root);
                // system("dot -Tpng bal_tree.gv -o bal_tree.png");
                fclose(f);
                break;
            }
            case 3:
            {
                int flag = 0;
                char s[100];
                printf("Input word: ");
                scanf("%s", s);
                root = search(s, root, &done, &flag);
                if (flag == 1)
                    printf("YES\n");
                else
                    printf("NO\n");
                break;
            }
            case 4:
            {
                int flag = 0;
                char s[100];
                printf("Input word: ");
                scanf("%s", s);
                bal_root = search(s, bal_root, &done, &flag);
                if (flag == 1)
                    printf("YES\n");
                else
                    printf("NO\n");
                break;
            }
            case 5:
            {
                printf("Input size hash table (integer number): \n");
                int error = check_int(&len_table, -1, 1000);
                int copy = len_table;
                if (!error)
                {
                    f = fopen(DATA_NAME, "r");
                    table = build_table(f, &len_table);
                    if (copy != len_table)
                    {
                        printf("New length hash table: %d\n", len_table);
                    }
                }
                else
                    printf("Error input!\n");
                break;
            }
            case 6:
            {
                if (!table)
                    printf("Empty table\n");
                else
                {
                    printf("Hash table: \n");
                    print_table(table, len_table);
                }
                break;
            }
            case 7:
            {
                if (!table)
                    printf("Empty table\n");
                else
                {
                    char s[100];
                    printf("Input word: ");
                    scanf("%s", s);
                    done = SUCCESS;
                    search_in_hash_table(s, table, len_table, &done);
                    if (done == 1)
                        printf("YES\n");
                    else
                        printf("NO\n");
                }
                break;
            }
            case 8:
            {
                rewind(f);
                char s[100];
                printf("Input word: ");
                scanf("%s", s);
                int flag = search_in_file(f, s);
                if (flag == 1)
                    printf("YES\n");
                else
                    printf("NO\n");
                break;
            }
            case 9:
            {
                efficiency();
            }
            case 0:
            {
                x = 0;
                break;
            }
            default:
            {
                printf("Incorrect parameter!\n");
                break;
            }
        }
    }
}