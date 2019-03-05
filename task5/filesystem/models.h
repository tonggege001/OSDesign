/**
 * 定义公共的数据结构和变量
 * 
 * 
*/
#ifndef MODELS_H
#define MODELS_H

extern const int BLOCKSIZE;
extern const char * STORAGEPATH;     //存储地址
extern const int BLOCKNUM;             //块数
#define CONTENTSIZE  2040                   //内容的大小

//文件类型
extern const int REGULAR;      //常规文件
extern const int DIRECTORY;    //目录文件
//文件状态
extern const char USED;
extern const char UNUSED;


//目录项结构
struct dirent{
    long    size;       //文件大小(单位为字节)
    long    ctime;      //创建时间
    long    utime;      //更新时间
    long    inode;      //inode的号，也即块号
    long    type;       //文件类型，可以是文件或者是目录
    long    blockcount; //所占用的块数
    char    name[32];   //文件名
    char    owner[8];   //文件所有者
};

//数据块的结构
struct block{
    long    next;                       //下一个数据块的i节点号
    long    length;                     //在本块中占用的字节数
    char    content[CONTENTSIZE];       //数据块的内容
};

#endif










