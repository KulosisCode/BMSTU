#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int read_(int a[], int *n)
{
    printf("Enter size of array ");
    int check = 1;
    if (scanf("%d", n) == 1)
    {
        if (n > 0)
        {
            check = 1;
            for (int i = 0; i < *n; i++)
            {
                if (scanf("%d", &a[i]) != 1)
                    check = 0;
            }
        }
        else
            check = 0;
    }
    else
        check = 0;
    return check;
}


void print(int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}

int main()
{
    int a[5000], b[5000];
    int n, check;
    int xs = 0;
    int nb = 0;
    check = read_(a,&n);
    if (check != 0)
    {   
        xs = 0;
        for (int i = 0;i < n; i++)
        {
            if (a[i] > xs)
                {
                    b[nb] = a[i];
                    nb++;  
                }
            xs += a[i];
        }
        if (nb)
            print(b, nb);      
        else
        {
            printf("Input Error");
            return -1;
        }
    }
    else
    {
        printf("Input Error");
        return -1;
    }
    return EXIT_SUCCESS;
}
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>

// float cacl(double a, double b, double c)
// {
//     float x1, x2;
//     float delta;
//     if (a =! 0)
//     {
//     delta = b*b - 4*a*c;
//     if (delta < 0)
//     {
//         printf("Input error");
//         return -1;
//     }
//     x1 = (-b + sqrt(delta)) / (2 * a);
//     x2 = (-b - sqrt(delta)) / (2 * a);
//     }
//     else
//     {
//         printf("Input error!");
//         return -1;
//     }
//     return x1, x2;   
// }

// int main()
// {
//     double p, q, z;
//     double x1, x2, y1, y2;
//     printf("Enter values p, q, z : ");
//     if (scanf("%f", &p) == 1 && scanf("%f", &q) == 1 && scanf("%f", &z) == 1)
//     {
//         if (p != 0)
//         {
//             x1, x2 = cacl(5, 15, 10);
//             y1, y2 = cacl(p, q, z);
//             if ((x2 * y2) < 0)
//             {
//                 printf("Input error!");
//                 return -1;
//             }
//             printf("%lf", (x1 + y1) / 2);
//             printf("%lf", sqrt(x2 * y2));
//         }
//         else
//         {
//             printf("Input error!");
//             return -1;
//         }
//     }
//     else
//     {
//         printf("Input error!");
//             return -1;
//     }
//     return EXIT_SUCCESS;
// }
