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
    struct dirent * dir = (struct dirent *)mmap(NULL, BLOCKSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, BLOCKNUM);
    if(dir == NULL || dir == (void *)(-1)){
        printf("GetAllDirectory, 内存映射/目录失败");
        close(fd);
    }

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
    memset(d.name,0,siezof(d.name));
    for(int i = 0;i<BLOCKSIZE/sizeof(struct dirent);i++){
        if(strcmp(name,dir[i].name)==0){
            memcpy(&d,&dir[i],siezof(d));
            break;
        }
    }
    return d;
}




