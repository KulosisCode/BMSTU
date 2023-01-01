#include "international_split.h"

int split(const char *string, char **matrix, const char symbol)
{
    int first = 0;
    int count  = 1;
    while(string[first] == symbol)
        first++;
    if (string[first] == '\0')
        return 0;
    int n = first;
    while (string[n] != '\0')
    {
        if (string[n] == symbol && string[n + 1] != symbol
            && string[n + 1] != '\0')
            count++;
        n++;
    }

    for (int i = 0; i < count; i++)
    {
        int index = first;
        while (string[first] != symbol && string[first] != '\0')
            first++;
        int len = first - index;
        for (int k = 0; k < len; k++)
        {
            matrix[i][k] = string[index + k];
        }
        matrix[i][len] = '\0';
        while(string[first]  == symbol)
            first++;
    }
    return count;
}