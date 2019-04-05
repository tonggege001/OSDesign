#include "../filesystem/models.h"
#include "../filesystem/utils.h"
#include "../filesystem/directory.h"
#include "../filesystem/create.h"
#include "../filesystem/delete.h"
#include "../filesystem/read.h"
#include "../filesystem/write.h"
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include<string.h>


void sysGetAllDirectory(struct dirent * dstdir, int * length){

    int fd;     //文件描述符
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return ;
    }
    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    GetAllDirectory(BigBlock, dstdir, length, 32);

    close(fd);

}


void sysCreateFile(char * filename, char * owner){
	tcreate(filename, owner, REGULAR);
}



void sysDeleteFile(char * filename){
    int fd;
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return ;
    }


    tdelete(fd, filename);
    close(fd);
}


void sysReadFile(char * filename, char * buf, long maxLen){
    int fd;     //文件描述符
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return ;
    }
    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    tread(BigBlock, filename, buf, maxLen);

    munmap(BigBlock, BLOCKNUM + BLOCKSIZE * (BLOCKNUM));
    close(fd);

}



void sysWriteFile(char * filename, char * buf){
    int fd;     //文件描述符
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return ;
    }
    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    twrite(BigBlock, filename,buf, strlen(buf)+1);
    munmap(BigBlock,BLOCKNUM+BLOCKNUM+BLOCKSIZE);
    close(fd);

}


void sysRename(char * filename, char * newname){
    int fd;     //文件描述符
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return;
    }
    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);

    int ret = ChangeName(BigBlock,filename, newname);
    if(ret == -1){
        printf("修改名称错误\n");
        return;
    }
    return 0;

}











