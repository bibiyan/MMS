#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double squareRoot(double num)
{
    double start,end,mid;

    start = 0;
    end = num;

    while((end - start) > 0.00001){

        mid = (start + end) / 2;

        if((mid * mid) < num){
            start = mid;
        }
        if((mid * mid) >= num){
            end = mid;
        }
    }
    return mid;
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int main()
{
    srand(time(NULL));
    double num = randDouble(0, 100000);
    printf("sqrt(%.3lf) = %.3lf\n", num, squareRoot(num));
    return 0;
}