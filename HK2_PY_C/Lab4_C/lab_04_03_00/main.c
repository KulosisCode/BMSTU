#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfuncstr.h"

#define OK 0
#define ERRORLOGIC 1
#define ERRORINPUT 2

int main(void)
{
    shortstring_t str, new_str = "";
    shortstring_t delims = " ,;:-.!?\n";
    shortstrings_t words_arr;
    size_t n;
    printf("Input string: \n");
    char *p = fgets(str, STR_LEN, stdin);
    if ((p == NULL) || (str[strlen(str) - 1] != '\n'))
    {
        printf("Input error!");
        return ERRORINPUT;
    }
    else
    {
        n = split(str, words_arr, delims);
        if (n == 0)
        {
            printf("Input error!");
            return ERRORINPUT;
        }
        else
        {
            size_t index = 0; 
            index = revers_word(words_arr, new_str, n);
            if (index)
            {   
                new_str[strlen(new_str) - 1] = '\0';
                printf("Result: %s\n", new_str);
            }
            return EXIT_SUCCESS;
        }
    }
}