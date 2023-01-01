#include "io_table.h"

int main(void)
{
    setbuf(stdout, NULL);
    student *person = malloc (MAX_SIZE * sizeof(student));
    keys *key = malloc (MAX_SIZE * (sizeof(keys)));
    int index = 0;
    int choice = 0;
    while(1)
    {
        message();
        scanf("%d", &choice);
        if (choice < 0 || choice > 9)
            printf("Wrong choice!");
        else if (choice == 1)
        {
            printf("1 - Add record from file ?\n");
            printf("2 - Add record by input ?\n");
            printf("0 - Go to Menu\n");
            int x = 0;
            scanf("%d", &x);
            if (x == 1)
            {
                FILE *file = fopen("data.txt", "r");
                if (check_file(file) == OK)
                {
                    read_from_file(file, person, key, &index);
                    fclose(file);
                }
            }
            else if (x == 2)
            {
                add_record_to_table(person, key, &index);
            }
            else if (x == 0)
                continue;
            else
                printf("Wrong choice!");
        }
        else if (choice == 2)
        {
            if (index <= 0)
            {
                printf("Table is empty now!");
            }
            else
            {
                int num;
                printf("Input index of record (range[0..%d] :", index - 1);
                if (scanf("%d", &num) != 1 || num < 0 || num >= index)
                {
                    printf("Error input!\n");
                    continue;
                }
                for (int i = num; i < index - 1; i++)
                {
                    person[i] = person[i + 1];
                    key[i] = key[i + 1];
                }
                index--;
            }
        }
        else if (choice == 3)
            print_table(person, key, &index, 0);
        else if (choice == 4)
            print_key_table(key, &index);
        else if (choice == 5)
            print_table(person, key, &index, 1);
        else if (choice == 6)
        {
            if (index <= 0)
            {
                printf("Table is empty now!");
            }
            buble_sort(person, index);
        }
        else if (choice == 7)
        {
            if (index <= 0)
            {
                printf("Table is empty now!");
            }
            buble_sort_key(key, index);
        }
        else if (choice == 8)
        {
            if (index <= 0)
            {
                printf("Table is empty now!");
            }
            find_student(person, &index);
        }
        else if (choice == 9)
        {
            test_sort_table();
        }
        else if (choice == 0)
            break;  
    }
    

    return EXIT_SUCCESS;
}