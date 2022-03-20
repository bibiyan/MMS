#include <stdio.h>
#include <stdlib.h>
//xor (2 numbers)
int main()
{
    double a,b;
    scanf("%lf",&a);
    scanf("%lf",&b);
    int x;
    x = ((a && !b) || (!a && b));
    printf("%d\n",x);
    return EXIT_SUCCESS;
}
// gcc zad2.c -o zad2
// ./zad2 < numbers.txt