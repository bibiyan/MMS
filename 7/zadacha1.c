#include <stdio.h>
#include <stdlib.h>

int cmp(const void * num1, const void* num2)
{
    return *(int*)num1 - *(int*)num2;
}

int secondMax(const int* arr, size_t n, int* secondMax)
{
    if (!n)
    {
        fprintf(stderr, "Empty array!\n");
        *secondMax = 0;
        return *secondMax;
    }

    if (n == 1)
    {
        fprintf(stderr, "There is only one element!\n");
        *secondMax = 0;
        return *secondMax;
    }

    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
    qsort(arr2, n, sizeof(arr2[0]), cmp);
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr2[i]);
    }
    printf("\n");
    int j = 1;
    while (arr2[0] == arr2[j] && j<n)
    {
        j++;
    }
    if ( j == n)
    {
        fprintf(stderr, "There is no a second max number!\n");
        *secondMax = 0;
        return *secondMax;
    }

    *secondMax = arr2[j];
    return *secondMax;
}


int main()
{
    int nums[]={1,1,1};
    size_t count = sizeof(nums)/sizeof(int);
    int second;
    int res;
    res = secondMax(nums, count, &second);
    printf("%d\n", second);
    return 0;
}