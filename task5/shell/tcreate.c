#include "../filesystem/create.h"
#include "models.h"
int main(int argc, char * argv[]){
    if(argc == 0 || argc == 1){
        printf("参数错误\n");
        return -1;
    }

    if(argc == 2){
        tcreate(argv[1], "default", REGULAR);
    }
    else if(argc == 3){
        tcreate(argv[1],argv[2],REGULAR);
    }
    else{
        tcreate(argv[1],argv[2],argv[3]);
    }


}