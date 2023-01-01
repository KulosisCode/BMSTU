#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *my_strrchr(char *s1, int c)
{
    int i, j = -1;
    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == c)
            j = i;
    }
    if (c == '\0')
        return &s1[i];
    if (j != -1)
        return &s1[j];
    return 0;
}

char *my_strpbrk(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)      
            if (s1[i] == s2[j])
            {
                return &s1[i];
            }   
    }
    return 0;
}


