#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mux;

void* message(){
    srand(time(NULL));
    sleep(1);
    char *msg = malloc(sizeof(char)*10);
    char string[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    for (int i = 0; i < 10; i++){
        pthread_mutex_lock(&mux);
        msg[i] = string[rand()%(strlen(string))];
        pthread_mutex_unlock(&mux);
    }
    printf("%s\n", msg);
    free(msg);
}

int main(int argc, char* argv[]){
    pthread_mutex_init(&mux, NULL);
    int N = atoi(argv[1]);
    pthread_t th[N];
    for (int i = 0; i < N; i++){
        if (pthread_create(th + i, NULL, &message, NULL)){
            perror("create error");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < N; i++){
        if (pthread_join(th[i], NULL) != 0 ){
            perror("join error");
            return EXIT_FAILURE;
        }
    }
    
    pthread_mutex_destroy(&mux);
    return EXIT_SUCCESS;
}