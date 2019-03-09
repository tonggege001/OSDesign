#include "../filesystem/models.h"
#include "../filesystem/directory.h"
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>

void sysGetAllDirectory(struct dirent * dstdir, int * length){

    int fd;     //文件描述符
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return ;
    }
    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    GetAllDirectory(BigBlock, dstdir, length, 32);
}

int main(){
    return 0;
}


