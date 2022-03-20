#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int triangle (double a, double b, double c, double* S, double *P)
{
    double p;
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
    {
        fprintf(stderr, "Invalid triangle sizes!\n");
        return -1;
    }
    *P = a + b + c;
    p = *P/2;
    *S = sqrt(p * (p - a) * (p - b) * (p - c));
    return 0;
}
int main()
{
    int res;
    double a, b, c, S, P;
    while (scanf("%lf %lf %lf", &a, &b, &c)!=EOF)
    {
        res = triangle(a, b, c, &S, &P);
        printf("%d\n",res);
        if (res == 0)
        {
            printf("P = %.2lf\n", P);
            printf("S = %.2lf\n", S);
        }
    }
    
    return 0;
}
