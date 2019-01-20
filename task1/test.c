
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>


int main()
{
	DIR * dir = opendir("~/ARCHIVE");
	dir == NULL ? printf("dir is NULL") : printf("dir is NOT NULL");

	struct dirent *drt = readdir(dir);
	drt == NULL ? printf("drt is NULL") : printf("drt is NOT NULL");
	printf("aaa的d_name 是:%s\n", drt->d_name);
	return 0;
}







