#include "international_strtok.h"

char *strtok(char *string, char const *delim)
{
    static char *input = NULL;
    if (string != NULL)
    {
        input = string;
    }
    if (input == NULL)
        return NULL;
    char *output = input;
    int i = 0;
    int flag = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        bool check = false;
        for (int j = 0; delim[j] != '\0'; j++)
        {
            if (delim[j] == input[i])
            {
                check = true;
                break;
            }
        }
        if (!check)
        {
            flag++;
        }
        else
        {
            if (flag != 0)
            {
                output[i] = '\0';
                input += i + 1;
                return output;
            }
            else
            {
                input[i] = '\0';
                input++;
                output++;
                i--;
            }
        }
    }
    if (flag == 0)
        return NULL;
    output[i] = '\0';
    input = NULL;
    return output;
}