#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char buff[BUFSIZ];
    size_t bytes;
    int fd;
    if (argc == 1){
        while((bytes = read(STDIN_FILENO, buff, BUFSIZ)) > 0){
            write(STDOUT_FILENO, buff, bytes);
        }
    }
    else{
        for (int i = 1; i < argc; i++){
            fd = open(argv[i], O_RDONLY);
            if (fd == -1){
                perror("error\n ");
                return EXIT_FAILURE;
            }
            while((bytes = read(fd, buff, BUFSIZ)) > 0){
                write(STDOUT_FILENO, buff, bytes);
            }
            write(STDOUT_FILENO, "\n",1);
            close(fd);
        }
    }
    return EXIT_SUCCESS;

}