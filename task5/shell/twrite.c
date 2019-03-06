#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include<string.h>
#include"../filesystem/models.h"
#include "../filesystem/utils.h"
#include "../filesystem/directory.h"

int main(int argc, char * argv[]){
    if(argc == 0 || argc == 1){
        printf("参数错误\n");
        return -1;
    }
    int fd;     //文件描述符
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }
    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    if(argc == 2){
        twrite(BigBlock, argv[1],"", 1);
        return 0;
    }
    else{
        printf("argv[1] is%s\nargv[2] is %s",argv[1],argv[2]);
        int m = twrite(BigBlock, argv[1],argv[2], strlen(argv[2])+1);
        if(m<0){
            printf("写入错误\n");
            return -1;
        }
    }
    munmap(BigBlock,BLOCKNUM+BLOCKNUM+BLOCKSIZE);
    close(fd);
    return 0;


}
