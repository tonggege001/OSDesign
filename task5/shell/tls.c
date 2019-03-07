#include<stdio.h>
#include"../filesystem/models.h"
#include<sys/mman.h>
#include <fcntl.h>
#include"../filesystem/utils.h"
#include"../filesystem/directory.h"


int main(){
    int fd;
    fd = open(STORAGEPATH, O_RDWR|O_CREAT, 0666);
    if(fd == -1){
        printf("open filesystem error\n");
        return -1;
    }
    void * BigBlock = mmap(NULL,BLOCKNUM+BLOCKNUM*BLOCKSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
    if(BigBlock == MAP_FAILED){
        printf("tdelete, 内存映射\n");
        return -1;
    }

    struct dirent dir[32];
    int length = 0;
    GetAllDirectory(BigBlock, dir, &length, 32);

    char ctime[40];
    char utime[40];
    printf("\n%-15s%-15s%-10s%-30s%-30s%-10s\n","filename","owner","size","create_time", "update_time","type");
    for(int i = 0;i<length;i++){
        
        sprintf(ctime,"%s",Time2String(dir[i].ctime));
        sprintf(utime,"%s",Time2String(dir[i].utime));
        char *c1 = strchr(ctime,'\n');
        if(c1 != NULL) *c1 = '\0';
        char *u1 = strchr(utime,'\n');
        if(u1 != NULL) *u1 = '\0';


        printf("%-15s%-15s%-10d%-30s%-30s%-10d\n",dir[i].name, dir[i].owner, dir[i].size,ctime,utime,dir[i].type);
            
        /*printf("%s\t\t%s\t\t%d\t\t%s\t\t\t\t%s\t\t\t\t%d\t\t\n",dir[i].name, dir[i].owner,dir[i].size,
            ctime, utime,dir[i].type);
            */
    }

    munmap(BigBlock,BLOCKNUM+BLOCKNUM*BLOCKSIZE);
    close(fd);
}

