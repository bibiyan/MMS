#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int arr[MAX_SIZE];
int top = 0;
int bottom = 0;
int IsEmpty() {// functions returns 0 if queue is empty and > 0 if not
    return (top == 0 && bottom == 0);
}
int IsFull(){// function return 0 if the queue is full and new element cannot be added, otherwise > 0
    return (bottom == MAX_SIZE - 1);
}

void Push(int nNewValue){ // Functions adds new element to the queue. We assume, that previously
                         //“IsFull()” was called to check whether is possible to insert element, i.e. it is always possible to insert
                         //element
    if (IsFull()){
        fprintf(stderr, "Queue is full.\n");
        return;
    }
    bottom++;
    arr[bottom] = nNewValue;
}

int Pop(){
    if (top > bottom){
        fprintf(stderr, "Error!\n");
        return (-1);
    }
    top++;
}

void print(){
    for (int i = top + 1; i <= bottom; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main(){
    Push(5);
    Push(6);
    Push(12);
    Push(53);
    print();
    Push(64);
    Push(12);
    Push(59);
    Push(68);
    Push(155);
    print();
    Push(5);
    print();
    printf("Is empty? %d\n", IsEmpty());
    printf("Is full? %d\n", IsFull());

    return 0;
}