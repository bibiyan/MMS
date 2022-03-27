#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int comp(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

void swapg(void *a, void *b, size_t size){
    char temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}

void bubbleSort(void* arr, int n, size_t size, int (*comp)(const void*,const void*)){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < (n - i - 1) * size; j += size)
        {
            if (comp(arr + j, arr + j + size) < 0){
               swapg(arr + j, arr + j + size, size);
            }
        }
    }
}

void (*getSorting(char* fname))(void*, size_t, size_t, int(*)(const void*, const void*)){
    if (strcmp(fname, "qsort") == 0){
        return qsort;
    } else if(strcmp(fname, "bubble Sort") == 0){
        return bubbleSort;
    }
}

int main(){
    int arr[5]={1,5,3,2,3};
    char* sort = "bubble Sort";
    getSorting(sort)(arr, 5, sizeof(int), comp);
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}


