asmlinkage long sys_mycopy(const char* src, const char* dst){
	const int BUFSIZE = 512;
	int fin,fout;
	char buf[BUFSIZE];
	int copy_count;
	mm_segment_t fs;	//段操作初始化
	fs = get_fs();
	set_fs(get_ds());
	/*系统调用打开源文件*/
	if((fin = sys_open(src,O_RDONLY,S_IRUSR))==-1){
		return -1;
		printk("Error in open src file");
	}
	if((fout = sys_open(dst,O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR))== -1){
		return -2;
		printk("Error in open target file");
	}
	
	while(copy_count = sys_read(fin,buf,BUFSIZE)){
		if(copy_count == -1 || sys_write(fout,buf,copy_count)==-1){
			return -3;
			printk("Error in copy file");

		}

	}
	set_fs(fs);	/*段操作结束*/
	return 0;

}
