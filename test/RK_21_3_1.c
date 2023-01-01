#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int calc(double a, double b, double c, double *x1, double *x2)
{
    if(!a)
        return 1;
    double delta = b*b-a*c*4;
    if(delta < 0)
        return 1;
    (*x1) = (-b - sqrt(delta))/2/a;
    (*x2) = (-b + sqrt(delta))/2/a;
    return 0;
}

int main(void)
{
    double p, q, z;
    if (scanf("%lf", &p) != 1 || scanf("%lf", &q) != 1 || scanf("%lf", &z) != 1)
    {
        printf("Input error");
        return -1; 
    }
    // scanf("%lf %lf %lf", &p, &q, &z);
    double x1, x2, y1, y2;
    calc(5, 15, 10, &x1, &x2);
    if(calc(p, q, z, &y1, &y2) == 1 || x2 * y2 < 0)
    {
        printf("Input error");
        return -1;
    }
    printf("%lf %lf", (x1 + y1)/2, sqrt(x2 * y2));
    return EXIT_SUCCESS;
}