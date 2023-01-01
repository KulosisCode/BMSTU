#include "func.c"

int main(void)
{
    char str[STR_LEN];
    char delims[10] = ",;:-!?";
    FILE *file = fopen("a.txt", "r");
    if (file == NULL)
    {
        printf("NO FILE FINDED!");
        return NOFILE;
    }
    ;
    char *f = fgets(str, STR_LEN, file);
    if (f == NULL)
    {
        printf("NO INPUT DATA!");
        return NO_INPUT_DATA;
    }
    else
    {
        int  n = read(str);
        if (n == 0)
        {
            printf("NO WORD !");
            return NO_WORD;
        }
        n = check(str, delims);
        if (n != 0)
        {
            printf("ERROR INPUT");
            return ERR_INPUT;
        }
        printf("%s", str);
        return EXIT_SUCCESS;
    }
}