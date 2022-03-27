#include <stdio.h>
#include <stdint.h>
void setBit(uint16_t* mask, unsigned bit){
    *mask |= (1 << bit);
}
void swapBytes(uint16_t* word)
{
    uint16_t helper[16];
    int index = 0;
    for (unsigned i = 1 << 16; i >= 8; i/=2){
        if (*word & i){
            helper[index] = 1;
            index++;
        }else{
            helper[index] = 0;
            index++;
        }
    }
    *word <<= 8;
    for (unsigned i = 0; i < 8; i++){
        if (helper[i] > 0){
            setBit(word, i); 
        }
    }
    showBits(*word);
}
void showBits(uint16_t n){
    for (uint16_t i = 1 << 15; i > 0; i/=2){
        if (n & i){
            printf("1");
        }else{
            printf("0");
        }
    }
}
int main()
{
    uint16_t n;
    scanf("%u", &n);
    showBits(n);
    printf("\n");
    uint16_t *a;
    *a = n;
    swapBytes(a);
    return 0;
}