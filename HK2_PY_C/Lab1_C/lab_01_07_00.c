#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fun_s(double x, double s, double eps, double el, int i)
{
    s = 0.0;
    el = 1.0;
    i = 0;
    while (fabs(el) > eps)
    {
        s += el;
        i += 1;
        el = el * x / i;
    }
    return s;
}

int main(void)
{
    double x, eps;
    double f, s = 0.0;
    double el = 1.0;
    int i = 0;
    double delta, beta;
    int rc = scanf("%lf %lf", &x, &eps);
    if ((rc == 2) && (eps < 1) && (eps > 0))
    {
        f = exp(x);
        s = fun_s(x, s, eps, el, i);
        delta = fabs(f - s);
        beta = fabs(f - s) / f;
        printf("%lf\n", f);
        printf("%lf\n", s);
        printf("%lf\n", delta);
        printf("%lf", beta);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Input error");
        return -1;
    }
}
