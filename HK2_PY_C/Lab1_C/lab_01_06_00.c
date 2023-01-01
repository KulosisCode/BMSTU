#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MIN 1e-6

double square(double a, double b, double c, double d)
{
    return (a - c) * (a - c) + (b - d) * (b - d);
}

int check(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double a, b, c;
    a = square(xa, ya, xb, yb);
    b = square(xb, yb, xc, yc);
    c = square(xc, yc, xa, ya);
    if (fabs(a + b - c) <= MIN || fabs(a + c - b) <= MIN || fabs(b + c - a) <= MIN)
        return 1;
    else if (a > b + c || b > a + c || c > a + b) 
        return 2;
    else
        return 0;
}


int main()
{
    double xa, ya, xb, yb, xc, yc;
    double a, b, c;
    int el = scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);
    if (el == 6)
    {
        a = sqrt(square(xa, ya, xb, yb));
        b = sqrt(square(xb, yb, xc, yc));
        c = sqrt(square(xc, yc, xa, ya));
        if (fabs(a + b - c) <= MIN || fabs(a + c - b) <= MIN || fabs(b + c - a) <= MIN)
            return -1;
        else
        {
            printf("%d", check(xa, ya, xb, yb, xc, yc));
        }
    }
    else
    {
        printf("Input error");
        return -1;
    }
    return EXIT_SUCCESS;
} 