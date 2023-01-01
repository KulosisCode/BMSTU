#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = (char *)malloc (6);
    scanf("%s", s);
    s[5]= '\0';
    printf("%s", s);
    printf("\n%c", s[5]);
    free(s);
    return 0;
}