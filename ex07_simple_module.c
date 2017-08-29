#include<linux/init.h>
#include<linux/module.h>

#include <linux/fs.h> // for the character devvice support

/*Get these signatures from the header files then change them according to your requirements
	ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
	ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
	int (*open) (struct inode *, struct file *);
	int (*release) (struct inode *, struct file *);
*/
ssize_t ex07_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{

}

ssize_t ex07_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{

}
int ex07_open(struct inode *pinode, struct file *pfile)
{

}

int ex07_close(struct inode *pinode, struct file *pfile)
{

}

/*To hold the file operations performed on the device*/
struct file_operations ex07_file_operations = {
	.owner   = THIS_MODULE,
	.open    = ex07_open,
	.read    = ex07_read,
	.write   = ex07_write,
	.release = ex07_close,
};
int ex07_simple_module_init(void)
{
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);

	/* Register the driver and indicate that we are registering the driver*/
	register_chardev(240/*Major number*/,
			"Simple chat Dev"/*Name of the driver*/,
			ex07_fie_operations/*file operations*/)	
	return 0;
}

void ex07_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

	/*unregster the character device driver*/
	unregister_chrdev(240,"Simple chat Dev")
}

module_init(ex07_simple_module_init);
module_exit(ex07_simple_module_exit);
