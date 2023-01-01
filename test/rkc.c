#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int read_(double a[])
{
    double s;
    int i = 0;
    while (scanf("%lf", &s) == 1)
    {
        a[i] = s;
        i++;
    }
    return i;
}

int cacl_g(double a[], int n)
{
    double g = 1.0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            g *= a[i] - a[i-1];
        else
            g *= a[i];
    }
    return g;
}
int main()
{
    int n = 0;
    double a[5000];
    double temp;
    n = read_(a);
    if (n >= 1)
    {
        temp = cacl_g(a,n);
        printf("%lf", sqrt(temp));    
    }
    else
    {
        printf("Error: Empty array!");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS; 
}