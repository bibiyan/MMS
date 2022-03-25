#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {   
        int helper = arr[i];
        while(helper)
        {
            sum += helper%10;
            helper /= 10;
        }
    }
    return sum;
}

int main()
{
    int arr[] = {12, 34, 5, 70};
    printf("Sum = %d\n", sumArrayDigits(arr, 4));
    return 0;
}