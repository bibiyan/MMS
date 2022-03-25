#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define COUNT 5

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
int randInt(int min, int max){
    return min + rand() % (max - min +1);
}

typedef struct{
    char title[150];
    char author[100];
    size_t pages;
    double price;
}Book;

void printInfo(Book b)
{
    printf("Title: %s, ", b.title); 
    printf("Author: %s, ", b.author);
    printf("Pages: %ld, ", b.pages);
    printf("Price: %.2lf", b.price);
    printf("\n");
}

void swapg(void *a, void* b, size_t size){
    uint8_t temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}
void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*)){
   for (int i = 0; i < n-1; i++){
       for (int j = 0; j < (n-i-1) * size; j += size){
           if (comp(arr + j, arr + j + size) < 0){
              swapg(arr + j, arr + j + size, size);
           }
       }
   }
}

int compTitle(const void* book1, const void* book2){
  
    Book* b1 = (Book*)book1;
    Book* b2 = (Book*)book2;
    return strcmp(b2->title, b1->title);
}
int compAuthor(const void* book1, const void* book2){
    Book* b1 = (Book*)book1;
    Book* b2 = (Book*)book2;
    return strcmp(b1->author, b2->author);
        
}
int compPages(const void* book1, const void* book2){
    Book* b1 = (Book*)book1;
    Book* b2 = (Book*)book2;
    return (b1->pages - b2->pages);
}
int compPrice(const void* book1, const void* book2){
    Book* b1 = (Book*)book1;
    Book* b2 = (Book*)book2;
    return (b1->price - b2->price);
}

Book *linearSearch(const double key, Book* array, size_t n){
    for (int i = 0; i < n; i++){
        if ((array[i].price) == key){
            return (array + i);
        }
    }
return NULL;
}

int main()
{
    srand(time(NULL));
    Book books[COUNT];
    const char titles[][20] = {"The little Prince", "Winnetou", "East of Eden", "The Pianist", "Winnie The Pooh"};
    const char authors[][20] = {"A. de S. Exupery", "Karl May", "J. Steinbeck", "W. Szpilman", "A. A. Milne"};
    for (int i = 0; i < COUNT; i++)
    {
        strcpy(books[i].title, titles[rand() % 5]);
        strcpy(books[i].author, authors[rand() % 5]);
        books[i].pages = randInt(5,2000);
        books[i].price = randDouble(1,1000);
    }

    bubbleSort(books, COUNT, sizeof(Book), compAuthor);
    for (int i = 0; i < COUNT; i++)
    {
        printInfo(books[i]);
    }

    Book *sb = linearSearch(20.50, books, COUNT);
    if (sb == NULL){
        printf("Not found!\n");
    }else{
        printf("%s\n", sb->title);
    }

    return 0;
}