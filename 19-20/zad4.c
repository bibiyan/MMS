#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>

pthread_mutex_t mBuff;

sem_t semEmpty;
sem_t semFull;

int randInt(int min, int max){
    return min + rand() % (max - min +1);
}
double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

enum products { coke, fanta, sprite, icetea, beer, rakia };

typedef struct {
    size_t barcode;
    enum products productName;
    double price;
} strProduct;

typedef struct node{
    strProduct* pr;
    struct node* next;
}node_t;


node_t *list = NULL;


void push(node_t** head, strProduct p){
    node_t* element = malloc(sizeof(node_t));
    element->pr->barcode = p.barcode;
    element->pr->productName = p.productName;
    element->pr->price = p.price;
    element->next = *head;
    *head = element;
}

void deleteNth(node_t** head, size_t n){
    if (*head == NULL){
        return;
    }
    if (n == 0){
        node_t* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    node_t* current = *head;
    node_t* prev = current;
    while (current && n--) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
}

strProduct* getNth(node_t* head, size_t n){
    node_t* current = head;
    while (n--){
        current = current->next;
    }
    return current->pr;
}

int listSize(node_t* head){
    int cnt = 0;
    node_t* current = head;
    while (current){
        cnt++;
        current = current->next;
    }
    return cnt++;
}

void* supplier(void *arg){
    while(1){
        size_t rndBarcode = randInt(10000, 100000);
        enum products rndProductName = randInt(0, 5);
        double rndPrice = randDouble(1, 20);
       
        strProduct addProduct;
        addProduct.barcode = rndBarcode;
        addProduct.productName = rndProductName;
        addProduct.price = rndPrice;

        // sleep(1);

        sem_wait(&semEmpty);
        pthread_mutex_lock(&mBuff);
        
        push(&list, addProduct);
        
        pthread_mutex_unlock(&mBuff);
        sem_post(&semFull);
        
        printf("Added - barcode: %ld, name: %d, price: %.2lf/n", addProduct.barcode, addProduct.productName , addProduct.price);
    }
}

void* purchaser(void *arg){
    while(1){
        int del = randInt(0, listSize(list));

        strProduct delProduct;
        delProduct.barcode = getNth(list, del)->barcode;
        delProduct.price = getNth(list, del)->price;
        delProduct.productName = getNth(list, del)->productName;

        sem_wait(&semFull);
        pthread_mutex_lock(&mBuff);

        deleteNth(&list, del);

        pthread_mutex_unlock(&mBuff);
        sem_post(&semEmpty);
        
        printf("Deleted - barcode: %ld, name: %d, price: %.2lf/n", delProduct.barcode, delProduct.productName , delProduct.price);
    
    }
}

int main(int argc, char** argv){

    int s, p;
    if (argc < 3 && argc > 4){
        s = 5;
        p = 6;
    }
    /*else if(argc == 4){
        FILE *fp = fopen(argv[4], "rb");
    }*/
    else{
        s = atoi(argv[1]);
        p = atoi(argv[2]);
    }


    srand(time(NULL));
    pthread_t thS[s];
    pthread_t thP[p];
    pthread_mutex_init(&mBuff, NULL);
    sem_init(&semEmpty, 0, 10);
    sem_init(&semFull, 0, 0);

    for (int i = 0; i < s; i++){
        if (pthread_create(thS + i, NULL, supplier, NULL)){
            perror("create error");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < p; i++){
        if (pthread_create(thP + i, NULL, purchaser, NULL)){
            perror("create error");
            return EXIT_FAILURE;
        }
    }


    for (int i = 0; i < p; i++){
        if (pthread_join(thP[i], NULL) != 0 ){
            perror("join error");
        return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < s; i++){
        if (pthread_join(thS[i], NULL) != 0 ){
            perror("join error");
        return EXIT_FAILURE;
        }
    }


    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mBuff);



    return EXIT_FAILURE;
}