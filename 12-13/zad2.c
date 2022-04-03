#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myStrlen(char* ptr){
    int cnt = -1;
    while(ptr[++cnt]); 
    return cnt;
}

char* Reverse(char* ptr){
    if (ptr == NULL){
        return NULL;
    }
    int i = 0;
    char* helper = malloc(myStrlen(ptr)*8);
    int index = 0;
    for (i = myStrlen(ptr) - 1; i >= 0; i--){
        helper[index] = ptr[i];
        index++;
    }
    helper[index] = '\0';
    return helper;
}

void print(char *str){
    for (int i = 0; i < myStrlen(str); i++){
        printf("%c", str[i]);
    }
    putchar('\n');
}

int main(){
    char* str = "Hello world! How are you?\n";
    str = Reverse(str); 
    print(str);
    return 0;
}