#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble(int *pArray, unsigned int uLen){
   for (int i = 0; i < uLen - 1; i++){    
       for (int j = 0; j < uLen - i - 1; j++)
           if (pArray[j] > pArray[j + 1])
              swap(&pArray[j], &pArray[j + 1]);
   }
}

void print(int *pArray, unsigned int uLen){
    for (int i = 0; i < uLen; i++)
        printf("%d ", pArray[i]);
    printf("\n");
}

int main(){
    int arr[10] = {12, 76, 3, 24, 6, 32, 23, 4, 231, 230};
    Bubble(arr, sizeof(arr)/ sizeof(arr[0]));
    print(arr, sizeof(arr)/ sizeof(arr[0]));
    return 0;
}