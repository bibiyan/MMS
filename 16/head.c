#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *f;
    f = fopen(argv[1], "r");
    if(!f || argc!=2){
        perror("error");
        return EXIT_FAILURE;
    }
    int n = 10;
    char line[100];
    while(fgets(line, sizeof(line), f)){
        if (n == 0){
            break;
        }
        printf("%s", line);
        n--;
    }
    fclose(f);
    return EXIT_SUCCESS;
}