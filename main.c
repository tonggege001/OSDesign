#include <stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>


void copy(char * src, char * dst);

void recurse_copy(char * src, char * dst);

int main(int argc, char	* argv[]) {
	if (argc != 3) {
		printf("命令输入有误！");
		return 0;
	}
	recurse_copy(argv[1], argv[2]);
	return 0;
}


//递归复制
void recurse_copy(char * src, char * dst) {
	//首先判断是文件还是目录
	struct stat filestat;
	stat(src, &filestat);
	//设置目标文件名
	char dstPath[256];
	char * pos = strrchr(src, '/');
	if (dst[strlen(dst) - 1] == '/')
		sprintf(dstPath, "%s%s", dst, pos + 1);
	else
		sprintf(dstPath, "%s/%s", dst, pos + 1);
	printf("dst is %s", dstPath);

	if (S_ISDIR(filestat.st_mode)) {	//如果是目录类型

		//创建对应的目录
		mkdir(dstPath, filestat.st_mode);

		DIR * dir = opendir(src);
		struct dirent *drt;
		while ((drt = readdir(dir))!=NULL) {
			//判断硬链接.和..，不能对其进行递归
			if (strcmp(drt->d_name, ".") != 0 && strcmp(drt->d_name, "..") != 0) {
				char * subsrc = drt->d_name;//子文件夹的类型
				recurse_copy(subsrc, dstPath);
			}
		}
		closedir(dir);
	}
	else if (S_ISREG(filestat.st_mode)) {	//如果是常规文件则直接复制
		copy(src, dstPath,filestat.st_mode);
	}
}


/**
 * 简单的原子拷贝，其中src: xxx/xxx/xx.abc
	st_mode表示权限
 */
void copy(char * src, char * dst,int st_mode) {
	FILE * fpr = fopen(src, "rb");
	FILE * fpw = fopen(dst, "wb");

	if (fpr == NULL) {
		printf("源文件文件打开错误！");
		return;
	}
	if (fpw == NULL) {
		printf("目标文件打开失败");
		fclose(fpr);
		return;
	}
	char buffer[1024];
	int num;    //fread返回项目的个数
	while ((num = fread(buffer, sizeof(char), 1024, fpr)) != 0) {
		printf("num is %d", num);
		fwrite(fpw, sizeof(char), num * sizeof(char), fpw);
	}
	fclose(fpr);
	fclose(fpw);
	//修改权限
	chmod(dst, st_mode);
	return;
}

int getLastNamePos(char * filename) {

}
