#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>

sem_t sem;

void* msg(void *arg){
    sem_wait(&sem);
    sleep(1);
    printf("%s\n", (char*)arg );
    sem_post(&sem);
    free(arg);
}

int main(int argc, char*argv[]){
    if (argc != 4){
        perror("invalid arguments!\n");
        return EXIT_FAILURE;
    }
    sem_init(&sem, 0, 1);
    int P = atoi(argv[1]);
    int T = atoi(argv[2]);
    char* MSG = malloc(sizeof(char)*strlen(argv[3]));
    strcpy(MSG, argv[3]);

    for (int i = 0; i < P; i++){
        pid_t pid = fork();
        if (0 == pid){
            printf("Process #%d \n", i);
             
            pthread_t th[T];

            for (int j = 0; j < T; j++){
                if (pthread_create(th + j, NULL, &msg, MSG)){
                    perror("create error");
                    return EXIT_FAILURE;
                }
                printf("Thread #%d of procces #%d\n", j, i);
            }

            for (int k = 0; k < T; k++){
                if (pthread_join(th[k], NULL) != 0 ){
                    perror("join error");
                    return EXIT_FAILURE;
                }
            }
            
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < P; i++){
        wait(NULL);
    }
    free(MSG);
    sem_destroy(&sem);
    return EXIT_SUCCESS;
}