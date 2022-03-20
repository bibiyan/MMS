#include <stdio.h>
#include <stdlib.h>
//xor (3 numbers)
int main()
{
    double a,b,c;
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    int x;
    x = ((!a && !b && c) || (!a && b && !c) || (a && !b && !c) || (a && b && c));
    printf("%d\n",x);
    return EXIT_SUCCESS;
}
// gcc zad2.1.c -o zad2.1
// ./zad2.1 < numbers.txt