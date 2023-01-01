#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double a, b, h;
    double next;
    scanf("%lf%lf%lf", &a, &b, &h);
    next = sqrt((fabs(a - b) / 2) * (fabs(a - b) / 2) + h * h);
    printf("%lf", a + b + 2 * next);
    return EXIT_SUCCESS;
}