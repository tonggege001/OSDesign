#include"models.h"

//extern void GetAllDirectory(void * BigBlock, struct dirent * dstdir, int * length, int max);
void GetAllDirectory(void * BigBlock, struct dirent * dstdir, int * length, int max);

extern int GetDirectoryIndexByName(void * BigBlock, char * name);