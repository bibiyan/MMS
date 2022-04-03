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


void printInfo(Book b){
    printf("Title: %s, Author: %s, Pages: %ld, Price: %.2lf", b.title, b.author, b.pages, b.price);
    printf("\n");
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    Book books[COUNT];
    for (int i = 0; i < COUNT; i++){
        books[i] = makeRndBook();
    }
    for (int i = 0; i < COUNT; i++){
        printInfo(books[i]);
    }
    
    FILE * file = fopen(argv[1], "wb");
    if (NULL == file){
        perror("Cannot open file.\n");
        return EXIT_FAILURE;
    };

    for (int i = 0; i < COUNT; i++){
        fputs("Title: ", file);
        fputs(books[i].title, file);
        fputs(", Author: ", file);
        fputs(books[i].author, file);
        char* price = malloc(sizeof(char*));
        char* pages = malloc(sizeof(char*));
        sprintf(price, "%.2f", books[i].price);
        sprintf(pages, "%ld", books[i].pages);
        fputs(", Pages: ", file);
        fputs(pages, file);
        fputs(", Price: ", file);
        fputs(price, file);
        fputs("\n", file);
        free(price);
        free(pages);
    
    //    fprintf(file, printInfo(books[i]));
    
    }
    
    fclose(file);

    return EXIT_SUCCESS;
}