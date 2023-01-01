#include "international_split.h"

int split(const char *string, char **matrix, const char symbol)
{
    int number = 0, num = 0;
    char ch;
    for (int i = 0; string[i] != '\0'; i++)
    {
        ch = string[i];
        if (ch == symbol)
        {
            if (num != 0)
            {
                matrix[number][num] = '\0';
                number++;
                num = 0;
            }
        }
        else
        {
            matrix[number][num] = ch;
            num++;
        }     
    }
    if (num > 0)
    {
        matrix[number][num] = '\0';
        number++;
    }
    return number;
}