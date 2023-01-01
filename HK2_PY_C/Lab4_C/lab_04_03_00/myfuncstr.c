#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfuncstr.h"

#define STR_LEN 257
#define MAX_WORD_LEN 17
#define MAX_WORDS 512

typedef char shortstring_t[STR_LEN];
typedef shortstring_t shortstrings_t[100];

size_t split(shortstring_t str, shortstrings_t a, shortstring_t delims)
{
    size_t i = 0;
    char *token;
    token = strtok(str, delims);
    while (token != NULL)
    {
        if (strlen(token) >= MAX_WORD_LEN)
            return 0;
        strcpy(a[i], token);
        i++;
        token = strtok(NULL, delims);
    }
    return i;
}

void change_word(shortstring_t st)
{
    size_t n = strlen(st);
    for (size_t i = 1; i < n; i++)
    {
        if (st[0] == st[i])
        {
            for (size_t k = i + 1; k < n; k++)
            {
                st[k - 1] = st[k];
            }
            st[n - 1] = '\0';
            i--;
            n--;
        }
    }
}

size_t revers_word(shortstrings_t words_arr, shortstring_t new_str, size_t n)
{
    size_t index = 0;
    for (size_t i = n - 2; i < n; i--)
        if (strncmp(words_arr[i], words_arr[n - 1], 17) != 0)
        {
            change_word(words_arr[i]);
            strcat(new_str, words_arr[i]);
            strcat(new_str, " ");
            index++;
        }
    return index;
}