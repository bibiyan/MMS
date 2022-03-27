#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define s 8 
int sumDigits(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int steps(int *arr, size_t n, int i, int *check)
{
    if (i < 0 || i > n - 1){
        printf("Out of array\n");
        return 0;
    }else if(check[i] == 1){
        printf("Looping...\n");
        return 0;
    }
    check[i] = 1;
    if (sumDigits(arr[i]) % 2 == 0){
        i += 3;
    } else{
        i -= 2;
    }
    return 1 + steps(arr, n, i, check);
}

int main()
{
    int ch[s];
    for (int i = 0; i < s; i++){
        ch[s] = 0;
    }
    int arr[s]={5, 23, 77, 123, 681, 9, 772, 16};
    printf("%d\n", steps(arr, s, 4, ch));
    for (int i = 0; i < s; i++){
        ch[s] = 0;
    }
    int arr2[8]={72, 14, 90, 27, 11, 63, 81, 52};
    printf("%d\n", steps(arr2, s, 0, ch));
    return 0;
}