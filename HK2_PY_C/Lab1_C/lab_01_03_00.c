#include <stdio.h>
#include <stdlib.h>

int main()
{
    double h, t, m;
    double m_normal, bmi;
    scanf("%lf%lf%lf", &h, &t, &m);
    m_normal = (h * t) / 240;
    h /= 100;
    bmi = m / (h * h);
    printf("%lf %lf", m_normal, bmi);
    return EXIT_SUCCESS;
}