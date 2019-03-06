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

void tdelete(int fd, char * name){

    void * BigBlock = mmap(NULL,BLOCKNUM+BLOCKNUM*BLOCKSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    if(BigBlock == MAP_FAILED){
        printf("tdelete, 内存映射");
        return;
    }

    void * dir_v = BigBlock+BLOCKNUM;
    struct dirent * dir = (struct dirent *)(dir_v);
    char * usageTable = (char *)BigBlock;

    struct block * mem = (struct block *)(dir_v);


    int dirpos = -1;
    //查找目录项
    for(int i = 0;i<BLOCKSIZE/sizeof(struct dirent);i++){
        if(strcmp(dir[i].name,name) == 0){
            dirpos = i; 
        }
    }
    if(dirpos==-1){
        printf("没有 %s 的目录项\n", name);
        return;
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

    munmap(BigBlock,BLOCKNUM);
}

int main_delete(){
    int fd = -1;
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }
    tdelete(fd,"tonggege");
    return 0;

}




