#include <stdio.h>
#include <math.h>

int main()
{
    double mass, height;
    double BMI, BMInew;
    printf("Mass="); //kg
    scanf("%lf",&mass);
    printf("Height="); //m
    scanf("%lf",&height);
    BMI = mass/height;
    BMInew = 1.3*(mass/(pow(height,2.5)));
    printf("BMI=%lf\n",BMI);
    printf("BMInew=%lf\n",BMI);
    
    return 0;
}