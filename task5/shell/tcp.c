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
#include "../filesystem/write.h"
#include "../filesystem/create.h"

int main(int argc, char * argv[]){
    if(argc != 3){
        printf("参数错误\n");
        return -1;
    }
    //创建文件
    tcreate(argv[2],"tonggege",REGULAR);

    char * buf = (char *)malloc(1024*1024*1);

    int fd;     //文件描述符
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }

    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);

    int cc = tread(BigBlock, argv[1], buf, 1024 * 1024 * 1);
    twrite(BigBlock,argv[2],buf,cc);

    munmap(BigBlock,BLOCKNUM+BLOCKSIZE*BLOCKNUM);
    close(fd);
    free(buf);
    return 0;

}