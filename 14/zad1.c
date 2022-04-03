#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1);
}

typedef struct{
    char title[150];
    char author[100];
    size_t pages;
    double price;
}Book;

typedef struct node {
    Book b;
    struct node* next;
} node_t;

void push(node_t** head, Book book){
    node_t* newBook = malloc(sizeof(node_t));
    strcpy(newBook->b.author, book.author);
    strcpy(newBook->b.title, book.title);
    newBook->b.price = book.price;
    newBook->b.pages = book.pages;
    newBook->next = *head;
    *head = newBook;
}
void FrontBackSplit(node_t* source,
                    node_t** frontRef, node_t** backRef)
{
    node_t* fast;
    node_t* slow;
    slow = source;
    fast = source->next;
 
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
node_t* SortedMerge(node_t* a, node_t* b)
{
    node_t* result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (strcmp(a->b.title, b->b.title) < 0) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void MergeSort(node_t** head)
{
    node_t* curr = *head;
    node_t* a;
    node_t* b;
 
    if ((curr == NULL) || (curr->next == NULL)) {
        return;
    }
 
    FrontBackSplit(curr, &a, &b);
 
    MergeSort(&a);
    MergeSort(&b);
 
    *head = SortedMerge(a, b);
}

void printInfo(Book b){
    printf("Title: %s, ", b.title); 
    printf("Author: %s, ", b.author);
    printf("Pages: %ld, ", b.pages);
    printf("Price: %.2lf", b.price);
    printf("\n");
}

void print(node_t* head) {
    node_t* curr = head;
    while(curr != NULL){
        printInfo(curr->b);
        curr = curr -> next;
    }
    putchar('\n');
}

Book makeRndBook(){
    
    Book b;
    b.pages = randInt(5,2000);
    b.price = randDouble(1,1000);
    b.title[0] = randInt('A', 'Z');
    b.author[0] = randInt('A', 'Z');
    for (int j = 1; j < randInt(10, 20); j++){
        b.author[j] = randInt('a', 'z');
    }for (int j = 1; j < randInt(10, 20); j++){
            b.title[j] = randInt('a', 'z');
    }
    return b;
}

int main(){
    srand(time(NULL));
    node_t* book = NULL;
    
    for (int i = 0; i < 10; i++)
    {
        Book b = makeRndBook();
        push(&book, b);
    }
   
    print(book);
    MergeSort(&book);
    print(book);
    return 0;
}