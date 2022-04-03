#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COUNT 10

typedef struct node {
    char* book;
    struct node* next;
} node_t;

void FrontBackSplit(node_t* source, node_t** frontRef, node_t** backRef)
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

node_t* SortedMerge(node_t* a, node_t* b){
    node_t* result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    if (strcmp(a->book, b->book) < 0){
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void MergeSort(node_t** head){
    node_t* curr = *head;
    node_t* a;
    node_t* b;
 
    if ((curr == NULL) || (curr->next == NULL)){
        return;
    }
 
    FrontBackSplit(curr, &a, &b);
 
    MergeSort(&a);
    MergeSort(&b);
 
    *head = SortedMerge(a, b);
}


void push(node_t** head, char* val){
    node_t* element = malloc(sizeof(node_t));
    strcpy(element->book, val); 
    element->next = *head;
    *head = element;
}

void print(node_t* head){
    node_t* curr = head;
    while(curr != NULL){
        printf("%s\n", curr->book);
        curr = curr -> next;
    }
    putchar('\n');
}

int main(int argc, char *argv[]){

    node_t *books = NULL;

    FILE * file1 = fopen(argv[1], "rb");
    if (NULL == file1){
        perror("Cannot open file.\n");
        return EXIT_FAILURE;
    };
    FILE * file2 = fopen(argv[2], "wb");
    if (NULL == file2){
        perror("Cannot open file.\n");
        return EXIT_FAILURE;
    };

    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

    char *l;

    while (fgets(buffer, MAX_LENGTH, file1)){
        //push(&books, buffer);
        printf("%s", buffer);
      //  l = malloc(sizeof(buffer));
      //  push(&books, l);
      //  free(l);
    }

    print(books);

    MergeSort(books);
    for (int i = 0; i < sizeof(books); i++){
        fputs(books[i].book, file2);    
    }
    
    fclose(file1);
    fclose(file2);

    return 0;
}