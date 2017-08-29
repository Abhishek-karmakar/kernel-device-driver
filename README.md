Block device driver
- Any device driver which can host a filesystem. 
- 
How to write basic character device driver.
 -Stream of bytes.
 - Data gets generated. You access as it gets generated.

Linux kernel has provision of loading a module in a running kernel. 
 - 

Write a simple program
	ex01_simple_module.c
load the program
	using insmod

TO compile the Simple Kernel module you need the running Kernel directory for the building the kernel module. 
- The directory which containts of the binaries of this particular version of linux. 

Write a test C program using GCC. 

Now to make a module you need the running linux kernel. 
make -C /lib/modules/$(uname -r)/build M=$PWD modules

 
// M=$PWD M is the notification that its a make file. 

 .ko is the driver or the module that will be inserted into the kernel using insmod

insmod ex01_simple_module to 

insmod is a prgram which picks the ko file from the hdd. Copies into the kernel space. Does necessary linking nd eventually calls module init function. 

rmmod - to remove the module. 
lsmod - list the modules present in the kernel. 


we have written two function.
	module_init - When the module is inserted inide the kernel space. When the module is loaded and initialize. 
	module_exit - When you remove the module from the kernel space.

You can give any name to your module. 
	module_init, module_exit - are macros. 

printk - Is the same as printf but for kernel. 
KERN_ALERT - the priority. 

Makefile. 

It generates .o from a a .c file and then generates a .ko from a .O file. 
 




