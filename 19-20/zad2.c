#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void* sortNum(void* arg){
    int num[4];
    {
        FILE* f1 = fopen((char*)arg, "rb");
        if (NULL == f1){
            perror("error");
            exit(-1);
        }
        int n;
        int i = 0;

        fscanf(f1, "%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
    
        qsort(&num, 4, sizeof(int), cmp);
        fclose(f1);
    }
    {
        FILE* f2 = fopen((char*)arg, "wb");
        if (NULL == f2){
            perror("error");
            exit(-1);
        }
        for (int i = 0; i < 4; i++){
            fprintf(f2, "%d\n", num[i]);
        }
        
        fclose(f2);
    }
}

int main(int argc, char* argv[]){

    pthread_t th[argc - 1]; 

    for (int i = 0; i < argc - 1; i++){
        
        if (pthread_create(th + i, NULL, &sortNum, argv[i + 1])){
            perror("create error");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < argc - 1; i++){
        if (pthread_join(th[i], NULL) != 0 ){
            perror("join error");
            return EXIT_FAILURE;
        }
    }

    //free (files);
    return EXIT_SUCCESS;
}