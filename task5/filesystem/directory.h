
void GetAllDirectory(int fd, struct dirent * dstdir, int * length, int max);


struct dirent GetDirectoryByName(int fd, struct dirent *dir, char * name);