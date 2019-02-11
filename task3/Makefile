ifneq ($(KERNELRELEASE),)
	obj-m :=mydev.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
install:
	sudo insmod mydev.ko
uninstall:
	sudo rmmod mydev
clean:rm -rf *.o *.ko *.cmd *.mod.c .tmp_versions

