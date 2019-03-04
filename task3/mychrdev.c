#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/kdev_t.h>
static ssize_t chrdev_read(struct file *,char *,size_t ,loff_t *);
static ssize_t chrdev_write(struct file *,const char *,size_t ,loff_t *);
static int chrdev_open(struct inode *inode,struct file *filp);
static int chrdev_release(struct inode *inode,struct file *filp);
char buf[500] = "It is wangtong (nick name tonggege)'s device. abcdefgABCDEFG ";
char device[] = "mychrdev";
int major_num;

struct file_operations mychrdev_fops =
{
	.open = chrdev_open,
	.release = chrdev_release,
	.read = chrdev_read,
	.write = chrdev_write,
};

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

void cleanup_module()
{
	unregister_chrdev(major_num, device);
	printk("注销通哥哥的设备成功。\n");
}

int chrdev_open(struct inode *inode, struct file *file)
{
	int ret=try_module_get(THIS_MODULE);//模块计数加一
	if(ret==0)
	{
		printk("打开设备失败！\n");
		return -2;
	}
	printk("打开设备成功！\n");
	return 0;
}

int chrdev_release(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);//模块计数减一
	printk("关闭设备成功！\n");
	return 0;
}

ssize_t chrdev_read(struct file *file, char __user *user, size_t t, loff_t *f)
{	
	ssize_t count = 0;
	if(count = copy_to_user(user,buf,500))	return -3;
	return count;
}

ssize_t chrdev_write(struct file *file, const char __user *user, size_t t, loff_t *f)
{
	ssize_t count;
	if(count = copy_from_user(buf,user,500))	return -4;
	return count;
}
MODULE_LICENSE("GPL");
