#include <stdio.h>
int add(int a, int b)
    return a + b;
int mul(int a, int b)
    return a*b;

typedef int (*ptr_action_t)(int, int);

int apply(int a, int b, ptr_action_t action)
    return action(a, b)
int main(void)
{
    ptr_action_t p_action = add;
    int a =5, b =4;
    printf("%dd +%d=%d\n", a,b , apply(a,b,p_action));
    printf("%d * %d = %d", a, b, apply(a, b, mul));
    return 0;
}