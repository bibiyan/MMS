#include <stdio.h>

#define COUNT 10

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue){

    int l = 0;
    int r = uArraySize - 1;

    while(l <= r){
        int mid = (l + r)/2;
        if (pArray[mid] < uValue){
            l = mid + 1;
        }else if(pArray[mid] == uValue){
            return mid;
        }else{
            r = mid - 1;
        }
    }
    return 0xFFFF;
}


int main(){
    int arr[COUNT] = {1, 2, 5, 7, 8, 12, 13, 14, 49, 53};
    int res = BinSearch(arr, COUNT, 5);
    if ()
    printf("%x\n", 0xFFFF);
    return 0;
}