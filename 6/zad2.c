#include <stdio.h>

#define Pi 3.14

int fact(int number)
{
   if (number <= 0){
       return 1;
   }
   return number * fact(number - 1);
}

double power(double n, int p)
{
    if (p == 0){
        return 1;
    }
    return (n * power(n, p - 1));
}

double sinX(double d){
    double r = d * Pi / 180;
    double sin = 0;

    for (int i = 0; i < 7; i++){
        sin += power(-1, i) * power(r, 2 * i + 1) / fact(2 * i + 1);
    }
    return sin;
}

int main()
{
    printf("%0.2lf", sinX(45));
    return 0;
}