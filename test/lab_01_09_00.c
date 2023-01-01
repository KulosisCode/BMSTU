#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MIN 1e-6

double calc(double x, int i, double g)
{
    x = 0.0;
    i = 0;
    g = 0.0;
    while (x >= -MIN)
    {
        if (scanf("%lf", &x) == 1)
        {
            if (x < -MIN)
                break;
            i += 1;
            g += x / i;
        }
        else
            return -1;
    }
    return g;    
}

int main()
{
    double x = 0.0;
    int i = 0;
    double temp, g = 0.0;
    temp = calc(x, i, g);
    if (temp != -1)
        printf("%lf", sqrt(temp));
    else
    {
        printf("Error: Input error");
        return -1;
    }
    return EXIT_SUCCESS;
}
