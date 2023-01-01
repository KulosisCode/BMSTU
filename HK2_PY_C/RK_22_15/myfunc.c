#include "myfunc.h"

int count_vowel_consonant(FILE *f, int *nguyen_am, int *phu_am)
{
    char c;
    while (fscanf(f , "%c", &c))
    {
        if (feof(f))
            break;
        if (!isalpha(c) && !isspace(c) && c != '\n')
            return ERR_LETTER;
        if (c != '\n' && isupper(c))
            return ERR_UPPER ;
        if (strchr("ueoaiy", c) != NULL)
            (*nguyen_am)++;
        else
            (*phu_am)++;
    }

    if ((*nguyen_am) == 0 && (*phu_am) == 0)
        return NO_INPUT_DATA;

    return OK;
}

void print_file(FILE* f)
{
    char c;
    while (fscanf(f, "%c", &c))
    {
        if (feof(f))
            break;
        fprintf(stdout, "%c", c);
    }
}

void print_new_file(FILE* f)
{
    char c;
    while (fscanf(f, "%c", &c))
    {
        if (feof(f))
            break;
        if (strchr("ueoaiy", c) != NULL)
            fprintf(stdout, "%c", (char)((int)c + 1));
        else
            fprintf(stdout, "%c", c);
    }
}