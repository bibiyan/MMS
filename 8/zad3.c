#include <stdio.h>
#include <stdlib.h>

int cmp(const void * num1, const void* num2)
{
    return *(int*)num1 - *(int*)num2;
}

int binarySearch(int* array, size_t n, int key)
{
    int index=0;
    qsort(array, n, sizeof(int), cmp);

    int left = 0, right = n - 1;

    while(left <= right)
    {
        int mid = (left + right)/2;
        if (array[mid] == key)
        {
            return mid;
        }
        if (array[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binarySearch(arr, 10, 13));
    return 0;
}