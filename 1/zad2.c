#include <stdio.h>
#include <math.h>

int main()
{
    double R, H, V; // R - radius na osnova, H - visochina , V - obem (v metri)
    printf("R=");
    scanf("%lf",&R);
    printf("H=");
    scanf("%lf",&H);
    V = 3.14*pow(R,2)*H;
    printf("V=%0.2lf\n",V);
    return 0;
}