#include"../filesystem/directory.h"
#include "../filesystem/models.h"
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include<string.h>
#include "../filesystem/utils.h"


int main(int argc, char * argv[]){
    if(argc != 3){
        printf("参数错误");
        return -1;
    }
    int fd;     //文件描述符

    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }
    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);

    int ret = ChangeName(BigBlock,argv[1], argv[2]);
    if(ret == -1){
        printf("修改名称错误\n");
        return -1;
    }
    return 0;
}
