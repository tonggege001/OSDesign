#include"models.h"
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include<string.h>
#include"directory.h"
#include"utils.h"


/**
 * 删除文件或目录
 * 首先判断删除的是文件还是目录（目前只能是文件，因为文件系统是一级目录，而不是树形目录）
 * 如果是文件则首先释放所有占用的i节点（使用的是链式）
 * 然后删除/下对应的目录项，需要依次移动，因为是连续的
 * 
 */

void delete(char * name){
    int fd;
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);

    struct dirent * dir = (struct dirent *)mmap(NULL, BLOCKSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, BLOCKNUM);
    if(dir == NULL || dir == (void *)(-1)){
        printf("GetAllDirectory, 内存映射/目录失败");
        close(fd);
    }

    char * usageTable = (char * )mmap(NULL,BLOCKNUM, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    if(usageTable == NULL || usageTable == (void *)(-1)){
        printf("内存映射使用表失败");
        close(fd);
        return -2;
    }

    struct block * mem = (struct block *)mmap(NULL, BLOCKSIZE * (BLOCKNUM-1),PROT_READ|PROT_WRITE,MAP_SHARED,fd,BLOCKNUM);
    if(mem == NULL || mem == (void *)(-1)){
        printf("内存映射使用表失败");
        close(fd);
        return -2;
    }

    int dirpos;
    //查找目录项
    for(int i = 0;i<BLOCKSIZE/sizeof(struct dirent);i++){
        if(strcmp(dir[i].name,name) == 0){
            dirpos = i;
        }
    }
    int inode = dir[dirpos].inode;  //获得首节点
    //移动目录项
    int latter = dirpos+1;
    for(latter = dirpos+1;latter<BLOCKSIZE/sizeof(struct dirent);latter++,dirpos++){
        dir[dirpos] = dir[latter];
    }
    memset(dir[latter].name,0,32);
    
    //释放相应的i节点
    do{
        updateBlock(usageTable,inode,UNUSED);
        inode = mem[inode].next;
    }while(inode!=0);

    munmap(usageTable,BLOCKNUM);
    munmap(dir,BLOCKSIZE);
    munmap(mem,BLOCKSIZE * (BLOCKNUM-1));
    close(fd);

}





