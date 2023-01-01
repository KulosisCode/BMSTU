#include "func.h"

#define STR_LEN 257
int read(char str[STR_LEN])
{
    int count = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
            count++;
    }
    return count;
}

void del_begin(char str[STR_LEN])
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

int check(char str[STR_LEN], char delims[10])
{
    del_begin(str);
    if (!isupper(str[0]))
        str[0] = toupper(str[0]);
    for (size_t i = 1; i < strlen(str); i++)
        if (isalpha(str[i]))
            str[i] = tolower(str[i]);
    size_t num = strlen(str);
    for (size_t i = 0; i < num; i++)
    {
        if (isspace(str[i]))
            if(isspace(str[i + 1]) || strchr(delims, str[i + 1]) != NULL || str[i + 1] == '.')
            {
                for (size_t j = i + 1; j < num; j++)
                    str[j - 1] = str[j];
                str[num - 1] = '\0';
                num--;
                i--;
            }
        if (strchr(delims, str[i]) != NULL)
            if (strchr(delims, str[i + 1]) != NULL)
                return -1;
            else if (isalpha(str[i + 1]))
            {
                for (size_t j = num ; j > i + 1 ; j--)
                    str[j] = str[j - 1];
                str[i + 1] = ' ';
                num++;
                str[num] = '\0';
            }
    }
    int n = strlen(str);
    if (isspace(str[n - 1]) && str[n - 2] != '.')   
        str[n - 1] = '.';
    if (str[n - 1] != '.')
    {
        str[n] = '.';
        str[n+1] = '\0';
    }
    return 0;
}
