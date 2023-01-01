#include "myfunc.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return NOT_ENOUGH_ARG;

    argv[1] = "in.txt";
    FILE* f = fopen(argv[1], "r");
    if (f == NULL)
        return NO_INPUT_FILE;

    char words[N][LENGTH + 1];

    int count = 0;
    int result = get_data_from_file_text(f, &count, words);

    if (result == NO_INPUT_DATA)
        return NO_INPUT_DATA;

    if (result == OUT_OF_LENGTH)
        return OUT_OF_LENGTH;

    /*if (result == TWO_WORDS_IN_A_LINE)
        return TWO_WORDS_IN_A_LINE;*/

    fclose(f);

    size_t min_len = OO;
    for (int i = 0; i < count; i++)
    {
        if (first_equal_last(words[i]))
            if (strlen(words[i]) < min_len)
            {
                min_len = strlen(words[i]);
                printf("%ld ", min_len);
            }
                
    }

    if (min_len == OO)
        return NO_VALID_WORD;

    printf("%ld ", min_len);

    return OK;
}
