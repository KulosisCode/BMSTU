#include "my_string.c"

int main()
{
    char st[] = "howareyou";
    printf("1.1 - %d\n", (strrchr(st, 'o') == my_strrchr(st, 'o')));
    printf("1.2 - %d\n", (strrchr(st, 't') == my_strrchr(st, 't')));
    printf("1.3 - %d\n", (strrchr(st, '\0') == my_strrchr(st, '\0')));
    printf("2.1 - %d\n", (strpbrk(st, "abc") == my_strpbrk(st, "abc")));
    printf("2.2 - %d\n", (strpbrk(st, "gsw") == my_strpbrk(st, "gsw")));
    printf("2.3 - %d\n", (strpbrk(st, "") == my_strpbrk(st, "")));
    return 0;
}