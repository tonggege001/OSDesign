#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
	syscall(380,"./data", "./data_dst");
	return 0;
}
