Following this tutorial : https://www.youtube.com/watch?v=E_xrzGlHbac&list=PL2GL6HVUQAuksbptmKC7X4zruZlIl59is&index=6

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
 
NOTE :
IN a kernel module if you write a init function and dont write a exit function : insmod will work .but rmmod will not work. Need to reboot to remove the module from the kernel. 
In a kernel module if you write the exit function but no init function. : insmod will load the function but will not call any init function. or the module will not be initialized. however if you write the exit function then the kernel will properly exit the kernel module

----------- 
How to create a KO file using multiple source file. 

-----------
To export a Symbol use the macro 
EXPORT_SYMBOL(<name of the function that you want to export or a global variable>)

to call it . 
1.> IN the calling file. 
	just add the prototype of the method
	add the function just like you are calling the function. 

-----------
How to write a Simle Character driver 
 - YOu get a stream of bytes. 
 - you consume the data as it comes in. 

Quick program 
Everything is treated as a file. 
ls -l (will show all the files and )
ls -la /dev | head // will how the drivers present in the file. 
crw-------  1 root root        5,   1 Aug 29 10:21 console

//5,1 shows the version number of the driver. Major number and the minor number of the device. 
- Major number is the unique way of identifying it with the device. 
- minor number is the number of instances of the device. 
brw-rw----  1 root disk        8,   0 Aug 29 10:20 sda
// here 8 is major number. 
// 1.2.3.4... indecates different partitions. 

8 indicates that that there is only one driver which is doing all the work . 1,2,3,4 .. 8 says that these are the instances of the same driver. 

What we do typically with a driver is open a file. write  read something . Close a file. 

define that in a stuct , The struct file_operations is defined in <linux/fs.h>
Since we are interested in the following functions we'll do the following things.

struct file_operations ex07_file_operations = {
	.owner = THIS_MODULE,
	.open = ex07_open,
	.read = ex07_read,
	.write = ex07_write,
	.release = ex07_close,
};


Copy the prototype from these functions from <linux/fs.h>
	ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
	ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
	int (*open) (struct inode *, struct file *);
	int (*release) (struct inode *, struct file *);



