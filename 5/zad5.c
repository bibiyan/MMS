#include <stdio.h>
#include <stdarg.h>

/*unsigned onesCount(unsigned count, size_t size, ...)
Като първи параметър се подава броя на маските, 
а като втори размера в байтове на маската. 
(Размерът може да бъде между 1 и sizeof(int)). 
Функцията да връща общия брой на всички 1-ци в подадените маски.
*/
unsigned int count1(int mask)
{
    int cnt = 0;
    for (int i = 0; i < sizeof(int)*8; i++)
    {
        cnt += !! (mask & (1 << i));
    }
    return cnt;
}

unsigned onesCount(unsigned count, size_t size, ...)
{
    va_list masks;
    va_start(masks, size);
    int n = 0;

    unsigned setBits = 0;
    while (n < count)
    {
        int mask = va_arg(masks, int);
        setBits += count1(mask) - 1;
        printf("bits=%d\n", setBits);
        n++;
    }
    
    va_end(masks);
    
    return setBits;
}
int main()
{
    unsigned num = onesCount(4, 4, 1100, 0101, 00011101, 1101);
    printf("%d\n",num);
    
    return 0;
}