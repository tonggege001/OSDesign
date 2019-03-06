#include "models.h"
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include<string.h>
#include "utils.h"
/**
 * 创建文件或目录
 * 首先需要在/中找到一个空的位置存放目录项文件，然后在空闲块中找到一个空闲块，
 * 最后将目录项写到第0块的相应位置(一个文件至少占用一个空闲块)
 * 
 * 采用内存映射技术修改文件
*/


int getNewBlockInode(char * usageTable);
int getNewDirentIndex(struct dirent * dir);


long tcreate(char * name, char * owner, long type){
    int fd;     //文件描述符

    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }
    void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);

    
    char * usageTable = (char * )BigBlock;  //使用内存映射解决大文件读写
    struct dirent * dir = (struct dirent *)(BigBlock+BLOCKNUM);     //   /的目录项
    int pos = getNewDirentIndex((struct dirent *)(dir));

    //创建目录项
    long inode = getNewBlockInode(usageTable);
    updateBlock(usageTable,inode,USED);
    dir[pos].size = 0;
    dir[pos].ctime = getNowTime();
    dir[pos].utime = dir[pos].ctime;
    dir[pos].inode = inode;
    dir[pos].type = type;
    dir[pos].blockcount = 1;
    strcpy(dir[pos].name,name);
    strcpy(dir[pos].owner, owner);
    munmap(BigBlock,BLOCKNUM + BLOCKSIZE * (BLOCKNUM));
    close(fd);
    return 0;

}

//拷贝文件
long tcp(void * BigBlock, char * srcname, char * dstname){

}




//获得一个插入新的目录项的位置
int getNewDirentIndex(struct dirent * dir){
    for(int i = 0;i<BLOCKSIZE/sizeof(struct dirent);i++){
        if(strlen(dir[i].name)==0){     //名称为空的被视为空的位置
            return i;
        }
    }
    return -1;
}


//获得一个新的块号
int getNewBlockInode(char * usageTable){
    for(int i = 1;i<BLOCKNUM;i++){
        if(usageTable[i] == UNUSED){
            return i;
        }
    }
    return -1;
}


//测试创建文件
int main_create(){
    tcreate("tonggege","tonggege",REGULAR);
}





