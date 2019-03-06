#include "../filesystem/models.h"
#include"../filesystem/delete.h"
#include<sys/mman.h>
#include <fcntl.h>


int main(int argc, char * argv[]){
    if(argc == 1 || argc == 0){
        printf("参数错误\n");
        return -1;
    }
    int fd;
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }


    for(int i = 1;i<argc;i++){
        tdelete(fd, argv[i]);
    }
    close(fd);
}