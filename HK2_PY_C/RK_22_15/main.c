#include "myfunc.c"

int main()
{
    FILE* f = fopen("data.txt", "r");
    if (f == NULL)
    {
        printf("No file finded!");
        return ERR_NOFILE; 
    }
    int nguyen_am = 0;
    int phu_am = 0;
    int res = count_vowel_consonant(f, &nguyen_am, &phu_am);
    printf("%d %d\n", nguyen_am, phu_am);
    if (res == NO_INPUT_DATA)
    {
        printf("NO INPUT DATA!");
        return NO_INPUT_DATA;
    }
    else if (res == ERR_UPPER)
    {
        printf("ERROR UPPER!");
        return ERR_UPPER;
    }    
    else if (res == ERR_LETTER)
    {
        printf("ERROR LETTER!");
        return ERR_LETTER;
    }
    rewind(f);
    print_file(f);
    printf("\n");

    rewind(f);
    print_new_file(f);
    fclose(f);
    return OK;
}