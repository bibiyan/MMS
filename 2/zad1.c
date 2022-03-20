#include <stdio.h>
#include <stdlib.h>
// max number of three numbers
int main()
{
    double a,b,c;
    //printf("a=");
    scanf("%lf",&a);
    //printf("b=");
    scanf("%lf",&b);
    //printf("c=");
    scanf("%lf",&c);
    if (a>=b && a>=c)
    {
        printf("%.2lf\n",a);
    }
    else if(b>=a && b>=c)
    {
        printf("%.2lf\n",b);
    }
    else
    {
        printf("%.2lf\n",c);
    }
    return EXIT_SUCCESS;
}
// gcc zad1.c -o zad1
// ./zad1 < numbers.txt