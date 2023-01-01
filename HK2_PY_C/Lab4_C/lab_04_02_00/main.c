#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfuncstr.c"

#define OK 0
#define ERRORLOGIC 1
#define ERRORINPUT 2

int main(void)
{
    shortstring_t str;
    shortstring_t delims = " ,;:-.!?\n";
    shortstrings_t words;
    size_t n;
    printf("Input string: \n");
    char *p = fgets(str, STR_LEN, stdin);
    if ((p == NULL) || (str[strlen(str) - 1] != '\n'))
    {
        printf("Input error");
        return ERRORINPUT;
    }
    else
    {
        n = split(str, words, delims);
        if (n == 0)
        {
            printf("Input error");
            return ERRORINPUT;
        }
        else
        {
            n = blank_words_remove(words, n);
            n = dup_words_remove(words, n);
            if (n < 1)
                return ERRORINPUT;
            for (size_t i = 0; i < n; i++)
                if (strlen(words[i]) >= MAX_WORD_LEN)
                {
                    printf("Input error");
                    return ERRORINPUT;      
                }
            printf("Result: \n");
            for (size_t i = 0; i < n; i++)
                printf("%s %d\n", words[i], count(str, words[i], delims));
            printf("\n");
            return EXIT_SUCCESS;
        }
    }
}