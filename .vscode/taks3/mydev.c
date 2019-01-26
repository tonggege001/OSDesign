

int register_chrdev(unsigned int major, const char *name,struct file_operations *fops){
    //向系统的字符设备表登记一个字符设备
    //major:希望获得的设备号,为0时系统选择一个没有被占用的设备号返回。
    //name:设备名
    //fops:登记驱动程序实际执行操作的函数的指针
    //登记成功,返回设备的主设备号,否则,返回一个负值
}

int unregister_chrdev (unsigned int major, const char *name);
//卸载字符设备
//major:要卸载设备的主设备号
//name:设备名


int init_module(){
    printf("hello world!\n");
    printf("I have runing in a kernel mode");
    return 0;
}

void cleanup_module(){ /*卸载模块*/
    printf("I will shut down myself in kernel mode!")
}


