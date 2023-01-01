#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfuncstr.h"

#define STR_LEN 257
#define MAX_WORD_LEN 17
#define MAX_WORDS 512

typedef char shortstring_t[STR_LEN];
typedef shortstring_t shortstrings_t[100];

size_t blank_words_remove(shortstrings_t a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (a[i][0] == 0)
        {
            for (size_t j = i + 1; j < n; j++)
                strncpy(a[j - 1], a[j], 16);
            i--;
            n--;
        }
    return n;
}
size_t dup_words_remove(shortstrings_t a, size_t n)
{
    int f;
    for (size_t i = 0; i < n; i++)
    {
        f = 0;
        for (size_t j = i - 1; j < n; j--)
            if (strncmp(a[i], a[j], 17) == 0)
                f = 1;
        if (f)
        {
            for (size_t k = i + 1; k < n; k++)
                strncpy(a[k - 1], a[k], 16);
            i--;
            n--;
        }
    }
    return n;
}
size_t split(shortstring_t str, shortstrings_t a, shortstring_t delims)
{
    size_t i = 0, j = 0, k = 0;
    a[0][0] = 0;
    while (str[k])
    {
        if (!(strchr(delims, str[k]) && j < MAX_WORD_LEN))
            a[i][j++] = str[k];
        else if (j >= MAX_WORD_LEN)
            return 0;
        else if (j > 0)
        {
            a[i++][j] = 0;
            j = 0;
        }
        k++;
    }
    if (j > 0)
    {
        a[i][j] = 0;
        return i + 1;
    }
    return i;
}
int count(shortstring_t str, shortstring_t word, shortstring_t delims)
{
    int c = 0;
    size_t k = 0;
    size_t kol = strlen(word);
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] != word[k])
            k = 0;
        else if (k > 0 || (k == 0 && (i == 0 || (i > 0 && strchr(delims, str[i - 1])))))
            k++;
        if (k == kol && (str[i + 1] == '\0' || strchr(delims, str[i + 1])))
            c++;
    }
    return c;
}