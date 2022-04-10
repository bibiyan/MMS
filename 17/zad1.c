#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int randInt(int min, int max){
    return min + rand() % (max - min +1);
}

char* randStr(){
    srand(time(NULL) ^ (getpid()<<16));
    char *str = malloc(sizeof(char)*10);
    char string[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 10; i++){
        str[i] = string[rand()%(strlen(string))];
    }
    return str;
}

int main(int argc, char*argv[]){
    
    if (argc != 2){
        perror("Invalid arguments!\n");
        return EXIT_FAILURE;
    }
    int N = atoi(argv[1]);
    for (int i = 0; i < N; i++){
        pid_t pid = fork();
        if (0 == pid){
            srand(time(NULL) ^ (getpid()<<16));
            printf("%s\n", randStr());
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < N; i++){
        wait(NULL);
    }
    
    return EXIT_SUCCESS;
}