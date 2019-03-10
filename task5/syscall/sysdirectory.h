#include"../filesystem/models.h"

extern "C"{
	void sysGetAllDirectory(struct dirent * dstdir, int * length);
	void sysCreateFile(char * filename, char * owner);
	void sysDeleteFile(char * filename);
	void sysReadFile(char * filename, char * buf, long maxLen);
	void sysWriteFile(char * filename, char * buf);
	void sysRename(char * filename, char * newname);

};
