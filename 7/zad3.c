#include <stdio.h>
#include <string.h>

int sum(int *arr, size_t n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int))
{
   // memmove(arr, f(arr, n), n);
}

int main()
{
    int arr[]={1, 2, 3};
    arrayEvaluate(arr, 3, sum);
    return 0;
}