#include <stdio.h>
#include <stdint.h>

void showBits(uint32_t n){
    for (uint32_t i = 1 << 31; i > 0; i/=2){
        if (n & i){
            printf("1");
        }else{
            printf("0");
        }
    }
}

int main(){
    uint32_t n;
    scanf("%u", &n);
    showBits(n);
    return 0;
}