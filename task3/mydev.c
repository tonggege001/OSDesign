#include<linux/fs.h>
#include<linux/uaccess.h>   //copy_to_user
#include<linux/module.h>    //try_module_put/get
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
//#include <linux/fs.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/errno.h>
//#include <linux/uaccess.h>
#include <linux/kdev_t.h>


#define MY_DEVIC_MAJOR 240 //定义设备号

char BUF[16] = {'H','E','L','L','O',',','M','D','E','V','I','C','E','!','\n','\0'};

int mydev_open(struct inode *inode,struct file * filp){
    int ret = try_module_get(THIS_MODULE);  //模块计数加一
    if(ret<=0){
        printk("ERROR:mydevice opend failed!\n");
        return -1;
    }
    printk("INFO:mydevice opened OK\n");
    return 0;
}

ssize_t mydev_read(struct file * filp,char __user * buf,size_t size,loff_t * ppos){
    printk("INFO:mydev_read is called!\n");
    if(size>16){
        copy_to_user(buf,BUF,16);
        printk("WARN:MAX CHARS LIMIT\n");
        return 16;
    }
    else{
        copy_to_user(buf,BUF,size);
        printk("INFO:mydev_read ok, number of copied chars is %ld\n",size);
    }
    return size;
}

ssize_t mydev_write(struct file *filp, const char __user * buf,size_t count, loff_t * ppos){
    printk("INFO:mydev_write is called\n");
    if(count >15){
        copy_from_user(BUF,buf,16);
        printk("WARN:MAX CHARS LIMIT\n");
        return 16;
    }
    else{
        copy_from_user(BUF,buf,count+1);
        printk("INFO:mydev_write ok, number of copied is %ld\n",count+1);
        return count+1;
    }
}

int mydev_release(struct inode * inode, struct file * filp){
    module_put(THIS_MODULE);//模块计数减一
    printk("INFO:mydevice release OK!\n");
    return 0;
}



struct file_operations mydevice_fops = {
    //.owner = THIS_MODULE,
    .open=mydev_open,
    .read = mydev_read,
    .write = mydev_write,
    .release = mydev_release
};


int init_module()/*模块初始化*/
{
    int rc = register_chrdev(MY_DEVIC_MAJOR,"mydev",&mydevice_fops);
    if(rc<0){
        printk("ERROR:init_module() error, register_chrdev failed\n");
        return -1;
    }
    printk("INFO:init_modle() OK\n");
    return 0;
}

void cleanup_module() /*退出模块*/
{
    unregister_chrdev(MY_DEVIC_MAJOR,"mydev");
    printk("INFO:cleanup_module() OK\n");
}



MODULE_LICENSE("GPL");

