#include"models.h"
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include<string.h>


/**
 * 目录操作：
 * 显示目录
 * 
 */


//目前只能获得/的所有目录项
//输出为dstdir和length
void GetAllDirectory(void * BigBlock, struct dirent * dstdir, int * length, int max){
    //   /的目录项
    void * dir_v = BigBlock+BLOCKNUM;
    struct dirent * dir = (struct dirent *)(dir_v);

    int i = 0;
    while(strlen(dir[i].name)!=0 && i<BLOCKSIZE/sizeof(struct dirent)){
        memcpy(&dstdir[i],&dir[i], sizeof(struct dirent));
        i++;
    }
    *length = i;
    
    return;
}



int GetDirectoryIndexByName(void * BigBlock, char * name){
    //   /的目录项
    void * dir_v = BigBlock+BLOCKNUM;
    struct dirent * dir = (struct dirent *)(dir_v);
    int index = -1;
    for(int i = 0;i<BLOCKSIZE/sizeof(struct dirent);i++){
        if(strcmp(name,dir[i].name)==0){
            index = i;
            break;
        }
    }
    return index;
}

int ChangeName(void * BigBlock, char * srcName, char * destName){
    if(strlen(srcName)==0) return -1;
    if(strlen(destName)==0)return -1;
    void * dir_v = BigBlock+BLOCKNUM;
    struct dirent * dir = (struct dirent *)(dir_v);

    int srcindex = -1;
    srcindex = GetDirectoryIndexByName(BigBlock,srcName);
    if(srcindex < 0){  //查找到源文件
        printf("srcindex is -1\n");
        return -1;
    }

    int destindex = GetDirectoryIndexByName(BigBlock, destName);
    if(destindex > 0 ){   //查找到目标文件，说明命名重复
        printf("destindex is not -1\n");
        return -1;
    }
    memcpy(dir[srcindex].name, destName,strlen(destName)+1);

}





int main_directory(){
    struct dirent dir[32];
    int length = 0;

    int fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    printf("open ok, fd is %d\n",fd);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }
    //获得映射
    void * BigBlock = mmap(NULL, BLOCKNUM+BLOCKSIZE*BLOCKNUM, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);


    /*测试获得所有目录项函数*/
    GetAllDirectory(BigBlock, dir, &length, 32);
    printf("***   Testing GetAllDirectory Function   ***\ndir_length is %d\n",length);
    for(int i = 0;i<length;i++){
        printf("%s  %s  %ld\n",dir[i].name, dir[i].owner, dir[i].ctime);
    }
    
    /*测试按照文件名获得目录项*/
    printf("***   测试GetDirectoryByName   ***");
    int index = GetDirectoryIndexByName(BigBlock,"tonggege");
    if(index==-1){
        printf("不存在该文件，name=%s\n","tonggege");
    }
    else{
        printf("tonggege 查找到， dir index is %d\n",index);
    }
    close(fd);
}

