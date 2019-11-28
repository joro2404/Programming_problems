#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv){
    char filename[100];
    int count = 0;
    int status;
    char buff[256];

    if(argc == 2){
        int fd = open(argv[1], O_RDONLY);

        while((status = read(fd, buff, 256)) != 0){
            int written = 0;
            while(written < status){
                if(count == 10)break;
                written += write(STDOUT_FILENO, buff + written, 1);
                if(buff[written-1] == '\n'){
                    count ++;
                }
            }
        }
    }

    else {
        for(int i=1;i<argc;i++){
            strcpy(argv[i], filename);
            strcpy(filename, (i > 1) ? "\n==> " : "==> ");
            strcat(filename, argv[i]);
            strcat(filename, " <==\n");
            write(STDOUT_FILENO, filename, strlen(filename));
            int fd = open(argv[i], O_RDONLY);

            while((status = read(fd, buff, 256)) != 0){
            int written = 0;
            while(written < status){
                if(count == 10)break;
                written += write(STDOUT_FILENO, buff + written, 1);
                if(buff[written-1] == '\n'){
                    count ++;
                }
            }
        }
        }
    }

}