#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}node_dq;

node_dq *head = NULL, *tail = NULL;

node_dq * createNode(int data){
    node_dq *newnode = (node_dq *)malloc(sizeof (node_dq));

    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    return (newnode);
}
void createSentinels() {

    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->prev = head;
}

void enqueueAtFront(int data){
    node_dq *newnode, *temp;
    newnode = createNode(data);
    temp = head->next;
    head->next = newnode;
    newnode->prev = head;

    newnode->next = temp;
    temp->prev = newnode;
}

void enqueueAtRear(int data){
    node_dq *newnode, *temp;
    newnode = createNode(data);

    temp = tail->prev;
    tail->prev = newnode;
    newnode->next = tail;
    newnode->prev = temp;
    temp->next = newnode;

}

void dequeueAtFront(){

    node_dq *temp;
    if (head->next == tail){
        printf("Queue is empty\n");
    }else
    {
    temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;

    free(temp);
    }
    return;
}

void dequeueAtRear(){
    node_dq *temp;
    if (tail->prev == head){
        printf("Queue is empty\n");
    }
    else{
        temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        free(temp);
    }
    return;
}

void print(){
    node_dq *temp;
    if (head->next == tail){
        printf("Queue is empty\n");
        return;
    }
    temp = head->next;
    while (temp != tail){
        printf("%-3d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int data, ch;
    createSentinels();
    while (1){
        printf("1. Enqueue at front\n2. Enqueue at rear\n");
        printf("3. Dequeue at front\n4. Dequeue at rear\n");
        printf("5. Print\n6. Exit\n");
        scanf("%d", &ch);
        switch (ch){

            case 1:{
                printf("Enter the data: ");
                scanf("%d", &data);
                enqueueAtFront(data);
                break;
            }
            case 2:{
                printf("Enter the data:");
                scanf("%d", &data);
                enqueueAtRear(data);
                break;
            }
            case 3:{
                dequeueAtFront();
                break;
            }
            case 4:{
                dequeueAtRear();
                break;
            }
            case 5:{
                print();
                break;
            }
            case 6:{
            exit(0);
            }
            default:{
                printf(" enter correct option\n");
                break;
            }
        }
    }
    return 0;
}