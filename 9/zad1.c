#include <stdlib.h>
#include <stdio.h>

#define COUNT 10

void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int start, int end){
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (i <= j){
        while(arr[i] < pivot){
           i++;
        }
        while(pivot < arr[j]){
           j--;
        }
        if (i <= j){
            swap2(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(int *arr, int start, int end)
{
    if(start < end)
    {
        int middle = partition(arr, start, end) - 1;
        quickSort(arr, start, middle);
        quickSort(arr, middle + 1, end);
    }
}

void print(int *arr, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[10] = {3, 6, 87, 2, 3, 1, 111, 323, 43, 5};
    quickSort(arr, 0, 10);
    print(arr, 10);

    return 0;
}