#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main( int argc,char *argv[] )
{
    int r, fd1, fd2;
    char *file1, *file2, buf[2];
    if (argc < 3){
        perror("Invalid arguments\n");
        return EXIT_FAILURE;
    }
    file1 = argv[1];
    file2 = argv[2];

    printf("file1=%s file2=%s" , file1, file2);

    fd1 = open(file1, O_RDONLY, 0777);
    if(fd1 == -1){
        perror("Cannot open the file.\n");
        return EXIT_FAILURE;
    }
    fd2 = creat(file2, 0777);

    if(fd == -1){
        perror("Cannot create the file.\n");
        return EXIT_FAILURE;
    }

    while(r = read(fd1, buf, 1) > 0){
        write(fd2 ,buf, 1);
    }
    remove(file1);
    close(fd1);
    close(fd2);
    return 
}