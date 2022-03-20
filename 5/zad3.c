#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rectangle(double w, double h, double* S, double *P)
{
    if (w <= 0 || h <= 0)
    {
        fprintf(stderr, "Invalid sizes!\n");
        return -1;
    }
    *P = 2 * (w + h);
    *S = w * h;
    return 0;
}
int main()
{
    double w, h, S, P;
    int res;
    while (scanf("%lf %lf", &w, &h)!=EOF)
    {
        res = rectangle(w, h, &S, &P);
        printf("%d\n", res);
        if (res == 0)
        {
            printf("P = %.2lf\n", P);
            printf("S = %.2lf\n", S);
        }
    }
    
    return 0;
}
