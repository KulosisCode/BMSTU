#include "myfunc.h"

int get_data_from_file_text(FILE* f, int* count, char arr[N][LENGTH + 1])
{
    char cur[LENGTH + 1];
    memset(cur, 0, sizeof(cur));

    while (fgets(cur, LENGTH + 1, f) != NULL)
    {
        if (strcmp(cur, "\n") == 0)
            continue;

        if (cur[strlen(cur) - 1] != '\n' && strlen(cur) >= LENGTH)
            return OUT_OF_LENGTH;

        if (cur[strlen(cur) - 1] == '\n')
            cur[strlen(cur) - 1] = '\0';

        while (cur[strlen(cur) - 1] == ' ')
            cur[strlen(cur) - 1] = '\0';

        if (strchr(cur, ' ') != NULL)
            return TWO_WORDS_IN_A_LINE;

        strcpy(arr[*count], cur);
        (*count)++;
    }

    if (*count == 0)
        return NO_INPUT_DATA;
    return OK;
} 

int first_equal_last(char word[LENGTH + 1])
{
    return (word[0] == word[strlen(word) - 1]);
}