#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "myfuncstr.c"

int main(void)
{
    shortstring_t str;
    if (!my_fgets(str, stdin))
    {
        printf("Input error!");
        return 1; 
    }
    if (isaddress(str))
        printf("YES");
    else
        printf("NO");
    return EXIT_SUCCESS;
}
