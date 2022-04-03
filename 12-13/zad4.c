#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -DDDDDD 
int countDig(int n){
    int c = 0;
    while(n){
        c++;
        n/=10;
    }
    return c;
}

void Conv(int sValue, char *pBuffer){
    pBuffer = malloc(sizeof(char*));
    while (sValue > 999999){
        sValue/=10;
    }
    for (int i = 0; i < 7; i++){
        pBuffer[i] = ' ';
    }
    if (sValue < 0){
        pBuffer[0] = '-';
        sValue*=-1;
    }
    int digits = countDig(sValue);
    int index = 6;
    while(sValue){
        pBuffer[index] = sValue % 10 + '0';
        sValue/=10;
        index --;
    }
    printf("%s\n", pBuffer);
    free(pBuffer);
}


int main(){
    char* pb = malloc(sizeof(char *));
    Conv(-12345, pb);
    printf("%s", pb);
    free(pb);
    
return 0;
}