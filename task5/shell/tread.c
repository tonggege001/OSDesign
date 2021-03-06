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
#include "../filesystem/read.h"

int main(int argc, char * argv[]){
    if(argc < 2){
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
    char * buf = (char *)malloc(1024*1024*100);
    int cc = tread(BigBlock, argv[1], buf, 1024*1024*100);
    printf("\n%s\n",buf);

    munmap(BigBlock, BLOCKNUM + BLOCKSIZE * (BLOCKNUM));
    close(fd);
    free(buf);
    //return cc;
    return 0;


}