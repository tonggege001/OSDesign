#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
        int mychrdev = 0;
        int i;
        char buf[500] = "1 2 3 4 5 6 7 8 9 6 5 4 1 2 3 6 5 8";
        mychrdev = open("/dev/mychrdev",O_RDWR);
        if(mychrdev == -1){
                printf("Can't open file \n");
		return -1;
        }
        write(mychrdev, buf, 30);
        
	char buf2[100];
	read(mychrdev,buf2,10);
        close(mychrdev);
	for(int i = 0;i<10;i++){
		printf("%c\n",buf2[i]);
	}
	return 0;
}


