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
void GetAllDirectory(int fd, struct dirent * dstdir, int * length, int max){
    //   /的目录项
    void * BigBlock = mmap(NULL, BLOCKNUM+BLOCKSIZE*BLOCKNUM, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    printf("GetAllDirectory BigBlock is %d\n",BigBlock);
    void * nn = BigBlock+BLOCKNUM;
    printf("nn is %d\n",nn);


    struct dirent * dir = (struct dirent *)(nn);
    printf("dir is %d",dir);
    //if(dir == NULL || dir == -1){
        //printf("GetAllDirectory, 内存映射/目录失败");
   // }
    //printf('GetAllDirectory dir map is %d',dir);
    int i = 0;
    while(strlen(dir[i].name)!=0 && i<BLOCKSIZE/sizeof(struct dirent)){
        memcpy(&dstdir[i],&dir[i], sizeof(struct dirent));
        i++;
    }
    *length = i;
    
    munmap(dir,BLOCKSIZE);
    
    return;
}



struct dirent GetDirectoryByName(int fd, struct dirent *dir, char * name){
    if(dir == NULL || dir == (void *)(-1)){
        printf("GetDirectory, 内存映射/目录失败");
        close(fd);
    }
    struct dirent d;
    memset(d.name,0,sizeof(d.name));
    for(int i = 0;i<BLOCKSIZE/sizeof(struct dirent);i++){
        if(strcmp(name,dir[i].name)==0){
            memcpy(&d,&dir[i],sizeof(d));
            break;
        }
    }
    return d;
}



int main(){
    struct dirent dir[32];
    int length = 0;

    int fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    printf("open ok, fd is %d\n",fd);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }
    //void *BigBlock = mmap(NULL,BLOCKNUM + BLOCKSIZE * (BLOCKNUM), PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    //printf("BigBlock mapped ok!\n");


    GetAllDirectory(fd, dir, &length, 32);
    printf("length is %d",length);
    for(int i = 0;i<length;i++){
        printf("%s  %s  %d",dir[i].name, dir[i].owner, dir[i].ctime);
    }
    
    close(fd);

}

