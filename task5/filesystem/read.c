#include"models.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include <fcntl.h>
#include"utils.h"
#include<string.h>


long tread(void * BigBlock, char * filename, char * buf, int length){
    int count = 0;
    long dirindex = GetDirectoryIndexByName(BigBlock, filename);

    char * usageTable = (char *)BigBlock;
    struct dirent * dir = (struct dirent *)(BigBlock + BLOCKNUM);
    struct block * blo = (struct block *)(BigBlock+BLOCKNUM);

    if(dir[dirindex].size<length)   length = dir[dirindex].size;

    int bIndex = dir[dirindex].inode;

    while(length != 0 && bIndex!= 0){
        if(length<=CONTENTSIZE){
            memcpy(buf,blo[bIndex].content,length);
            buf += length;
            count += length;
            length -= length;
        }
        else{
            memcpy(buf,blo[bIndex].content,CONTENTSIZE);
            buf += CONTENTSIZE;
            count += CONTENTSIZE;
            length -= CONTENTSIZE;
            bIndex = blo[bIndex].next;
        }
    }
    return count;
}

int main(){
    int fd = -1;
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }
    void * BigBlock = mmap(NULL,BLOCKNUM+BLOCKNUM*BLOCKSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    if(BigBlock == MAP_FAILED){
        printf("tdelete, 内存映射");
        return -1;
    }
    char buf[100];
    //char * cc = "a b c d e f g h i j k l m n o p q r s t u";
    int num = tread(BigBlock,"tonggege",buf,100);
    printf("num = %d, len(cc) = %d\n",num,100);
    printf("buf is %s\n",buf);
    munmap(BigBlock,BLOCKNUM+BLOCKNUM*BLOCKSIZE);
    close(fd);
    return 0;
}








