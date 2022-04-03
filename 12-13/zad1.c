#include <stdio.h>
#include <stdint.h>

unsigned CheckBit(unsigned int uValue){
    return (uValue && !(uValue & (uValue - 1)));
}

int main(){
    printf("%x", CheckBit(0x0600));
    return 0;
}