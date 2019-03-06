#include<time.h>
#include<stdio.h>
#include"models.h"
#include<time.h>
#include<string.h>

long getNowTime(){
    time_t now;
    time(&now);
    return now;
}

char * Time2String(time_t ts){
    struct tm * lt = localtime (&ts);
    char * ttt = asctime(lt);
    //memcpy(timestr,ttt ,strlen(ttt)+1);
    return ttt;
}



//设置数据块的state状态(USED、UNUSED)
int updateBlock(char * usageTable, long inode, long state){
    if(inode <0 && inode >=BLOCKNUM){
        printf("updateBlock error, inode out of range, inode = %ld",inode);
        return -1;
    }
    usageTable[inode] = state;
    return 0;
}

//获取一个新的块号
long getNewBlockIndex(char * usageTable){
    for(long i = 0;i<BLOCKNUM;i++){
        if(usageTable[i]==UNUSED){
            return i;
        }
    }
    return -1;
}


