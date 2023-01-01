#include "header.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    hash_t **table = NULL;
    int len_table = 0;

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("ERROR OPEN FILE!");
        return ERR_OPEN;
    }
    else
    {
        int command;
        printf("1) Create hash table\n");
        printf("2) Search in hash table\n");
        printf("3) Print table\n");
        printf("0) EXIT\n");
        while (scanf("%d", &command) == 1 && command >= 0 && command <= 3)
        {

            if (command == 1)
            {
                printf("Input size hash table: ");
                if (scanf("%d", &len_table) == 1 && len_table > 0)
                {
                    int tmp = len_table;
                    table = build_table(file, &len_table);
                    if (tmp != len_table)
                    {
                        printf("New size hash table: %d\n", len_table);
                    }
                }
                else
                {
                    printf("ERROR INPUT\n");
                }
            }
            else if (command == 2)
            {
                int find;
                int done = 0;
                int flag = 0;
                if (!table || len_table <= 0)
                {
                    printf("EMPTY HASH TABLE!\n");
                }   
                printf("Input number: ");                 
                if (scanf("%d", &find) == 1)
                {
                    search_in_hash_table(find, table, len_table, &done, &flag);
                    if (done == 1)
                        printf("YES\n");
                    else
                        printf("NO\n");
                    printf("COUNT COMPARE :%d", flag);
                }
                else
                {
                    printf("ERROR INPUT\n");
                }
            }
            else if (command == 3)
            {
                if (!table)
                {
                    printf("EMPTY HASH TABLE!\n");
                } 
                else
                {
                    printf("Hash table: \n");
                    print_table(table, len_table);
                }
            }
            else if (command == 0)
            {
                break;
            }
            printf("\n1) Create hash table\n");
            printf("2) Search in hash table\n");
            printf("3) Print table\n");
            printf("0) EXIT\n");
        }
        fclose(file);
    }
    return OK;
}