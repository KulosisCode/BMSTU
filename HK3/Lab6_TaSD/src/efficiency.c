#include "efficiency.h"


unsigned long int tick(void)
{
    unsigned long int d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

void efficiency(void)
{
    printf("Node tree: 50\n");
    int start = time(NULL);
    srand(start);
    unsigned long int time_b, time_e;
    unsigned long int time_tree = 0, time_bal_tree = 0, time_hash = 0,
            time_file = 0;
    double count_tree = 0, count_bal_tree = 0, count_hash = 0,
            count_file = 0;

    node_t *root = NULL;
    node_t *bal_root = NULL;
    node_hash **table = NULL;
    int len_table = 5;
    int done;
    int len_file;

    FILE *f;
    f = fopen(DATA_EFFICIENCY, "r");
    root = create_tree(root, f);
    rewind(f);
    bal_root = create_bal_tree(bal_root, f);
    rewind(f);
    table = build_table(f, &len_table);
    rewind(f);

    FILE *f2;
    f2 = fopen("data_copy.txt", "r");
    char *word = malloc((SIZE_WORD + 1)*sizeof(char));
    while(!feof(f))
    {
        fgets(word, SIZE_WORD, f);
        fprintf(f2, "%s", word);
    }
    fclose(f);
    fclose(f2);

    int count_node = 0;
    count_node_tree(bal_root, &count_node);
    int memory_tree = count_node*((sizeof(char*))*3);
    int memory_bal_tree = count_node*((sizeof(char*))*3 + sizeof(int));
    int memory_hash = count_node_table(table, len_table);

    int flag = 0;
    int len = 0;
    int count_word = COUNT_WORD;
    for (int i = 0; i < COUNT; i++)
    {
        int number = rand() % count_word;
        int count = 0;
        f = fopen("data_copy.txt", "r");
        while(!feof(f))
        {
            fgets(word, SIZE_WORD, f);
            check_end(word);
            if (count == number)
                break;
            count++;
        }
        fclose(f);

        done = 0;
        flag = 0;
        time_b = tick();
        root = search(word, root, &done, &flag);
        time_e = tick();
        time_tree += time_e - time_b;
        count_tree += done;
        done = 0;

        flag = 0;
        char s2[] = "love";
        time_b = tick();
        bal_root = search(s2, bal_root, &done, &flag);

        time_e = tick();
        time_bal_tree += time_e - time_b;
        count_bal_tree += done;
        done = 0;

        time_b = tick();

        char s1[] = "love";
        search_in_hash_table(s1, table, len_table, &done);

        time_e = tick();
        time_hash += time_e - time_b;
        count_hash += done;
        done = 0;

        f = fopen(DATA_EFFICIENCY, "r");
        rewind(f);
        char s[] = "love";
        time_b = tick();
        len_file = search_in_file(f, s);
        time_e = tick();
        if (!len)
            len = len_file;
        time_file += time_e - time_b;
        count_file += number;

        done = 0;
        count_word--;
    }


    len = 2920;
    for (int i = 0; i < COUNT_SPACE; i++)
        printf("-");
    printf("\n");

    printf("|                      |");
    printf("     tree      |");
    printf(" balanced tree |");
    printf("   hash table  |");
    printf("     file      |\n");

    for (int i = 0; i < COUNT_SPACE; i++)
        printf("-");
    printf("\n");

    printf("|   time (clock)       |");
    printf("     %8ld  |", time_tree/COUNT);
    printf("     %8ld  |", time_bal_tree/COUNT);
    printf("     %8ld  |", time_hash/COUNT);
    printf("     %8ld  |\n", time_file/COUNT);

    printf("|   memory (bites)     |");
    printf("     %8d  |", memory_tree + len_file);
    printf("     %8d  |", memory_bal_tree + len_file);
    printf("     %8d  |", memory_hash + len_file);
    printf("     %8d  |\n", len);

    printf("| count of comparisins |");
    printf("     %8.2lf  |", count_tree/COUNT);
    printf("     %8.2lf  |", count_bal_tree/COUNT);
    printf("     %8.2lf  |", count_hash/COUNT);
    printf("     %8.2lf  |\n", count_file/COUNT);

    for (int i = 0; i < COUNT_SPACE; i++)
        printf("-");
    printf("\n");
}



int count_node_table(node_hash **table, int len_table)
{
    int sum = 0;
    for (int i = 0; i < len_table; i++)
    {
        node_hash *cur= table[i];
        for ( ; cur; cur = cur->next)
        {
            sum += sizeof(char*)*2;
        }
        sum += sizeof(node_hash*);
    }
    return sum;
}