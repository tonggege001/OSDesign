#include<stdio.h>
#include"models.h"
#include"directory.h"
#include"utils.h"
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include <fcntl.h>


long _twrite(void * BigBlock, char * filename, int off, char * buf, int length){
    int count = 0;
    long dirindex = GetDirectoryIndexByName(BigBlock, filename);

    char * usageTable = (char *)BigBlock;
    struct dirent * dir = (struct dirent *)(BigBlock + BLOCKNUM);
    struct block * blo = (struct block *)(BigBlock+BLOCKNUM);

    struct dirent d = dir[dirindex];
    if(off>d.size){
        printf("twrite off is larger than filesize, off=%d, filesize=%d\n",off,d.size);
        return 0;
    }

    int bIndex = dir[dirindex].inode;
    
    while(off>CONTENTSIZE){
        off -= CONTENTSIZE;
        bIndex = blo[bIndex].next;
    }
    //处理等于的情况
    if(blo[bIndex].length==CONTENTSIZE){
        int newBlo = getNewBlockIndex(usageTable);
        updateBlock(usageTable,newBlo,USED);    //更新块的状态为已用
        blo[newBlo].next = 0;
        blo[newBlo].length = 0;
        blo[bIndex].next = newBlo;
        bIndex = newBlo;

        dir[dirindex].blockcount += 1;  //更新块数量
    }

    //从off处开始增加
    if(CONTENTSIZE-off>length){
        memcpy(blo[bIndex].content+off,buf,length);
        blo[bIndex].length += length;
        dir[dirindex].size += length;
    }else{
        memcpy(blo[bIndex].content+off, buf, CONTENTSIZE-off);
        blo[bIndex].length = CONTENTSIZE;
        length -= (CONTENTSIZE-off);
        buf += (CONTENTSIZE-off);
        dir[dirindex].size += (CONTENTSIZE-off);
        do{
            //产生新的块
            if(blo[bIndex].length == CONTENTSIZE){
                int newBlo = getNewBlockIndex(usageTable);
                updateBlock(usageTable,newBlo,USED);
                bIndex = newBlo;
                blo[bIndex].length = 0;
                blo[bIndex].next = 0;
                dir[dirindex].blockcount += 1;
            }
            if(length <= CONTENTSIZE){
                memcpy(blo[bIndex].content,buf,length);
                buf += length;
                blo[bIndex].length = length;
                dir[dirindex].size += length;
                length -= length;

            }
            else{
                memcpy(blo[bIndex].content,buf,CONTENTSIZE);
                buf += CONTENTSIZE;
                length -=CONTENTSIZE;
                dir[dirindex].size += CONTENTSIZE;
                blo[bIndex].length = CONTENTSIZE;
            }
        }while(length!=0);
    }
    return length;

}

long twrite(void * BigBlock, char * filename,char * buf, int length){
    int count = 0;
    long dirindex = GetDirectoryIndexByName(BigBlock, filename);
    printf("dirindex = %d\n",dirindex);


    void * _usageTable = BigBlock;
    void * _dir = BigBlock+BLOCKNUM;

    char * usageTable = (char *)_usageTable;
    struct dirent * dir = (struct dirent *)(_dir);
    struct block * blo = (struct block *)(_dir);

    //释放除第一个i节点的所有数据块
    int p = blo[dir[dirindex].inode].next;
    printf("p = %d\n",p);
    blo[dirindex].next = 0;
    while(p){
        int q = p;
        p = blo[p].next;
        updateBlock(usageTable, q,UNUSED);
    }

    //初始化并写入
    dir[dirindex].blockcount = 1;
    dir[dirindex].size = 0;
    dir[dirindex].utime = getNowTime();
    int bIndex = dir[dirindex].inode;
    while(length != 0){
        if(length <= CONTENTSIZE){
            memcpy(blo[bIndex].content,buf,length);
            dir[dirindex].size += length;
            blo[bIndex].length = length;
            buf += length;
            count += length;
            length -= length;
            
        }else{
            memcpy(blo[bIndex].content,buf,CONTENTSIZE);
            blo[bIndex].length = CONTENTSIZE;
            dir[dirindex].size += CONTENTSIZE;
            buf += CONTENTSIZE;
            length -= CONTENTSIZE;
            count += CONTENTSIZE;

            //产生新的块
            long newBlo = getNewBlockIndex(usageTable);
            updateBlock(usageTable, newBlo,USED);
            blo[newBlo].length = 0;
            blo[newBlo].next = 0;
            dir[dirindex].blockcount += 1;


            blo[bIndex].next = newBlo;
            bIndex = newBlo;
        }
    }
    return count;
}

int main_write(){
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
    char * cc = "哈哈哈";
    int num = twrite(BigBlock,"tonggege2",cc,strlen(cc)+1);
    printf("num = %d, len(cc) = %d",num,strlen(cc)+1);
    munmap(BigBlock,BLOCKNUM+BLOCKNUM*BLOCKSIZE);
    close(fd);
    return 0;
}













