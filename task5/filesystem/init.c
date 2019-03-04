#include<stdio.h>
#include<stdlib.h>
#include "models.h"
#include<string.h>

/**
 * 创建整个文件系统
 * 前50KB存放块的使用情况，所以一共有50 * 1024 个块
 * 第0号块存放/的目录项，一共存放最多32个目录，其中全零代表结尾
*/

int main(){
    FILE * f = fopen(STORAGEPATH,"wb");
    fwrite(&USED,1,sizeof(char),f);     //第一个块已使用，用于保存/的目录项
    for(int i = 1;i<BLOCKNUM;i++){
        fwrite(&UNUSED,1,sizeof(char),f);
    }

    char zeros[1024];
    memset(zeros,0,1024);

    //初始化块, 块大小是2048
    for(int i = 0;i<BLOCKNUM;i++){
        fwrite(zeros,sizeof(char),1024,f);
        fwrite(zeros,sizeof(char),1024,f);
    }
}










