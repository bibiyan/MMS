#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
int quadEq(double a, double b, double c, double* S, double* P)
{
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        return -1;
    }
    *S = (- b + sqrt(D)) / (2 * a);
    *P = (- b - sqrt(D)) / (2 * a);
    return 0;
}
int main(int argc, char* argv[])
{
    //double a, b, c;
    double S, P;
    //scanf("%lf %lf %lf", &a, &b, &c);
    printf("%d\n",quadEq(argv[0], argv[1], argv[2], &S, &P));
    printf("x1 = %.2lf\nx2 = %.2lf\n", S, P);
    return 0;
}