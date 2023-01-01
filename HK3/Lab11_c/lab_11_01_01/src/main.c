#include "header.h"

int main(void)
{
    int buf_size = 30;
    int x = -123;
    char st[10] = "abc";
    char buf01[200] = {'\0'};
    char buf02[200] = {'\0'};
    char buf03[200] = {'\0'};

    int rc = snprintf(buf01, buf_size, "Toi rat la %hx dang cap", x);
    if (rc != 0)
        printf("%s\n", buf01);

    rc = my_snprintf(buf02, buf_size, "Toi rat la %hx dang cap", x);
    printf("%s\n", buf02);
    printf("%d\n", rc);

    rc = my_snprintf(buf03, buf_size, "ABC%sEF", st);
    printf("%s\n", buf03);
    printf("%d\n", rc);
    return 0;
}