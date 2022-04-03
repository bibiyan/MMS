#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Add(const char* p1, const char* p2, char* result){

    long long num1 = atoi(p1);
    long long num2 = atoi(p2);
    long long sum = num1 + num2;
    char buffer[sizeof(long long)];
    sprintf(buffer, "%lld", sum);
    strcpy(result, buffer);
}

int main(){
    char* res = malloc(sizeof(long long));
    Add("123", "12", res);
    printf("%s/n", res);
    free(res);
    return 0;
}