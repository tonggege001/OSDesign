#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/kdev_t.h>

#define BUFFERSIZE 32;


static ssize_t chrdev_read(struct file *,char *,size_t ,loff_t *);
static ssize_t chrdev_write(struct file *,const char *,size_t ,loff_t *);
static int chrdev_open(struct inode *inode,struct file *filp);
static int chrdev_release(struct inode *inode,struct file *filp);
char buf[BUFFERSIZE+1] = "It is wangtong (nick name tonggege)'s device.";
char device[] = "mychrdev";

int major_num;

int pos = 0;

/**
	设备定义的一系列操作

*/
struct file_operations mychrdev_fops =
{
	.open = chrdev_open,
	.release = chrdev_release,
	.read = chrdev_read,
	.write = chrdev_write,
};


//初始化设备，在insmod时进行调用
int init_module()
{
	printk("注册通哥哥的设备%s",device);
	if ((major_num = register_chrdev(0, device, &mychrdev_fops)) < 0)
	{
		printk("失败。\n");
		return -1;
	}
	printk("成功！\n设备号 = %d\n",major_num);
	return 0;
}

//设别写在，在rmmod时调用
void cleanup_module()
{
	unregister_chrdev(major_num, device);
	printk("注销通哥哥的设备成功。\n");
}

//设备打开，调用open("/dev/mychrdev",O_RDW)时调用
//注意初始化消息
int chrdev_open(struct inode *inode, struct file *file)
{
	int ret=try_module_get(THIS_MODULE);//模块计数加一
	pos = 0;	//当前的位移为0,先写再读
	if(ret==0)
	{
		printk("打开设备失败！\n");
		return -2;
	}
	printk("打开设备成功！\n");
	return 0;
}

/**
	释放设备，调用close时执行
*/
int chrdev_release(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);//模块计数减一
	pos = 0;	//位移归为
	printk("关闭设备成功！\n");
	return 0;
}

ssize_t chrdev_read(struct file *file, char __user *user, size_t t, loff_t *f)
{	
	ssize_t count = 0;
	/*
	if(pos == 0){
		printk("设备无内容可读\n");
		*f = pos;
		return -3;
	}
	if(pos<t){
		printk("设备读取资源过多，进行截断\n");
		int ch = 0;
		count = 0;
		for(int i = pos;i>=0 && ch >= 0;i--){
			ch = copy_to_user(user+count,buf+i,1);
			if(ch >= 0){
				count += ch;
			}
			else{
				printk("读写发生截断");
				break;
			}
		}
		pos -= count;
	}
	else{	//pos可读超过t
		int ch = 0;
		count = 0;
		for(int i = 0;i<t;i++){
			ch = copy_to_user(user+i,buf+pos-i,t);
			count += ch;
		}
		pos -= count;
	}
	*f = pos;
	*/
	if(t <= pos){
		count = t;
	}
	else{
		count = pos;
	}
	int num = copy_to_user(user,buf+(pos-t),count);
	pos -= t;
	return num;
}

ssize_t chrdev_write(struct file *file, const char __user *user, size_t t, loff_t *f)
{
	ssize_t count;

	if(BUFFERSIZE-pos <= t){
		count = BUFFERSIZE-pos;
	}
	else{
		count = t;
	}
	int num = copy_from_user(buf+pos,user,count)
	return num;
}

MODULE_LICENSE("GPL");
