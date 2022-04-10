#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if (argc != 4){
        perror("Invalid arguments!\n");
        return EXIT_FAILURE;
    }
    if (argv[2] != "||"){
        perror("Invalid arguments!\n");
        return EXIT_FAILURE;
    }
    pid_t pid = fork();
    int status;
    if (pid == -1){
        perror("fork problem");
        return EXIT_FAILURE;
    }else if (0 == pid){
        if (!execlp(argv[1], argv[1], 0)){
            perror("Error\n");
            return EXIT_FAILURE;
        }
    } else {
        wait(&status);
        if (!execlp(argv[2], argv[2], 0)){
            perror("Error\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}