#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "myfuncstr.h"

#define STR_LEN 257
#define MAX_WORD_LEN 17
#define MAX_WORDS 512

typedef char shortstring_t[STR_LEN];
typedef shortstring_t shortstrings_t[100];

char *my_fgets(shortstring_t str, FILE *f)
{
    char buf[STR_LEN + 1];
    if (!fgets(buf, STR_LEN + 1, f))
        return NULL;
    if ((strlen(buf) >= STR_LEN) && buf[STR_LEN - 1] != '\n')
        return NULL;
    char *pos = strrchr(buf, '\n');
    if (pos)
        pos = "\0";
    strcpy(str, buf);
    return str;
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
void strimb(shortstring_t str)
{
    char *s1, *s2;
    s1 = str;
    s2 = str;
    while (isspace(*s1))
        s1++;
    while (*s1)
    {
        *s2 = *s1;
        s2++;
        s1++;
    }
    *s2 = '\0';
}
void strime(shortstring_t str)
{
    size_t n = strlen(str);
    char *s1 = str + n - 1;
    while (isspace(*s1))
        s1--;
    *(s1 + 1) = '\0';
}
int isnumber(shortstring_t str)
{
    for (size_t i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int isaddress(shortstring_t str)
{
    shortstrings_t ans;
    strimb(str);
    strime(str);
    size_t n = split(str, ans, ".\n");
    if (n != 4)
        return 0;
    for (size_t i = 0; i < n; i++)
    {
        if (strlen(ans[i]) > 3 || atol(ans[i]) >= 256 || !isnumber(ans[i]))
            return 0;
    }
    return 1;
}