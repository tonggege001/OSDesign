#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
        int mychrdev = 0;
        int i;
        char buf[500];
        mychrdev = open("/dev/mychrdev",O_RDWR);
        if(mychrdev == -1){
                printf("Can't open file \n");
		return -1;
        }
        read(mychrdev, buf, 500);
        for(int i = 0;i<20;i++){
                printf("%c\n",buf[i]);
        }
        close(mychrdev);
}


