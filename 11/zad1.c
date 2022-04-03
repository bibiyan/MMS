#include <stdio.h>


#define MIN(num1,num2,num3) ((num1)<(num2))?  ((num1)<(num3)?(num1):(num3)) : ((num2)<(num3)?(num2):(num3))
#define MAX(num1,num2,num3) ((num1)>(num2))?  ((num1)>(num3)?(num1):(num3)) : ((num2)>(num3)?(num2):(num3))

#define SETBIT(m,bit) (m|=(1<<(bit)))
#define CLEARBIT(m,bit) (m&=~(1 <(bit)))
#define INVERSEBIT(m,bit) (m^=(1<<(bit)))
#define CHECKBIT(m,bit) (!!(m &=(1<<(bit))))
#define SWAP(a,b,type) {type temp=a; a=b; b=temp;}

int main(){
    
    int min = MIN(3,4,2);
    printf("min = %d\n", min);

    int max = MAX(3,4,2);
    printf("max = %d\n", max);

    /*int mask = 0x11;
    SETBIT(mask, 5);
    SETBIT(mask, 3);
    INVERSEBIT(mask, 4);
    for (int i=sizeof(int)*8-1; i >=1; i--)
    {
         printf("%d", CHECKBIT(mask, i));
    }
    CLEARBIT(mask, 3);
    INVERSEBIT(mask, 5);
    INVERSEBIT(mask, 6);
    INVERSEBIT(mask, 8);
    for (int i=sizeof(int)-1; i >=1; i--)
    {
         printf("%d", CHECKBIT(mask, i));
    }
    printf("\n");*/
    return 0;
}