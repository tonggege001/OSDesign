#include <stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>


void copy(char * src, char * dst);

void recurse_copy(char * src, char * dst);

int main(int argc, char	* argv[]) {
	if (argc != 3) {
		printf("������������");
		return 0;
	}
	recurse_copy(argv[1], argv[2]);
	return 0;
}


//�ݹ鸴��
void recurse_copy(char * src, char * dst) {
	//�����ж����ļ�����Ŀ¼
	struct stat filestat;
	stat(src, &filestat);
	//����Ŀ���ļ���
	char dstPath[256];
	char * pos = strrchr(src, '/');
	if (dst[strlen(dst) - 1] == '/')
		sprintf(dstPath, "%s%s", dst, pos + 1);
	else
		sprintf(dstPath, "%s/%s", dst, pos + 1);
	printf("dst is %s", dstPath);

	if (S_ISDIR(filestat.st_mode)) {	//�����Ŀ¼����

		//������Ӧ��Ŀ¼
		mkdir(dstPath, filestat.st_mode);

		DIR * dir = opendir(src);
		struct dirent *drt;
		while ((drt = readdir(dir))!=NULL) {
			//�ж�Ӳ����.��..�����ܶ�����еݹ�
			if (strcmp(drt->d_name, ".") != 0 && strcmp(drt->d_name, "..") != 0) {
				char * subsrc = drt->d_name;//���ļ��е�����
				recurse_copy(subsrc, dstPath);
			}
		}
		closedir(dir);
	}
	else if (S_ISREG(filestat.st_mode)) {	//����ǳ����ļ���ֱ�Ӹ���
		copy(src, dstPath,filestat.st_mode);
	}
}


/**
 * �򵥵�ԭ�ӿ���������src: xxx/xxx/xx.abc
	st_mode��ʾȨ��
 */
void copy(char * src, char * dst,int st_mode) {
	FILE * fpr = fopen(src, "rb");
	FILE * fpw = fopen(dst, "wb");

	if (fpr == NULL) {
		printf("Դ�ļ��ļ��򿪴���");
		return;
	}
	if (fpw == NULL) {
		printf("Ŀ���ļ���ʧ��");
		fclose(fpr);
		return;
	}
	char buffer[1024];
	int num;    //fread������Ŀ�ĸ���
	while ((num = fread(buffer, sizeof(char), 1024, fpr)) != 0) {
		printf("num is %d", num);
		fwrite(fpw, sizeof(char), num * sizeof(char), fpw);
	}
	fclose(fpr);
	fclose(fpw);
	//�޸�Ȩ��
	chmod(dst, st_mode);
	return;
}

int getLastNamePos(char * filename) {

}