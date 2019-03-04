CONFIG_MODULE_SIG=n
ifneq ($(KERNELRELEASE),)
	obj-m :=mychrdev.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
install:
	sudo insmod mychrdev.ko
uninstall:
	sudo rmmod mychrdev
clean:rm -rf *.o *.ko *.cmd *.mod.c .tmp_versions
