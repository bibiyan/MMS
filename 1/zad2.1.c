#include <stdio.h>
#include <math.h>

int main()
{
    double R, L, H, V, A; // R - radius na osnova, L - visochina na cilindur, H - nivo na vodata, V - obem (v metri)
    printf("R=");
    scanf("%lf",&R);
    printf("L=");
    scanf("%lf",&L);
    printf("H=");
    scanf("%lf",&H);
    double c;
    c=(R-H)/R;
    A=(1/(cos(c)))*pow(R,2)-(R-H)*sqrt(2*R*H-pow(H,2));
    printf("%lf\n",A);
    V = A * L;
    printf("V=%.2lf\n",V);
    return 0;
}