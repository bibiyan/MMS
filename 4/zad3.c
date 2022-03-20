#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getChar(char c)
{
    return (c < 10) ? c + '0' : c + 'A' - 10;
}

void reverse(char *chs)
{
    char *end;
    end = chs + strlen(chs) - 1;
    while(chs < end)
    {
        char c = *chs;
        *chs = *end;
        *end = c;
        chs++;
        end--;
    }
}

void convertFromDec(char *res, unsigned long n, unsigned int base)
{
    char *res2 = res;
    while (n > 0)
    {
        *res++ = getChar((char)(n % base));
        n /= base;
    }
    res = '\0';
    reverse(res2);
}

int getValue(char c)
{
    return (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
}

unsigned long convertToDec(char *numb, unsigned int base)
{
    unsigned long res = 0;
    while (*numb != '\0')
    {
        res = res * base + getValue(*numb);
        numb++;
    }
    return res;
}

void convert(char *number, unsigned int sys1, unsigned int sys2)
{
    unsigned long h = convertToDec(number, sys1);
    char *result = NULL;
    convertFromDec(&result, h, sys2);
    printf("%s\n", &result);
}

int main()
{
    char *number;
    unsigned int numSys1;
    unsigned int numSys2;

    scanf("%s", &number);
    
    do
    {
        scanf("%d", &numSys1);
    }while(numSys1 < 2 || numSys1 > 36);
    do
    {
        scanf("%d", &numSys2);
    }while(numSys2 < 2 || numSys2 > 36);
    
    convert(&number,numSys1,numSys2);

    return 0;

}