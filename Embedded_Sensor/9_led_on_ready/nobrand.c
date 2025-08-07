#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <asm/io.h>

#define NOD_MAJOR 100
#define NOD_NAME "nobrand"

MODULE_LICENSE("GPL");

static volatile uint32_t *BASE;
static volatile uint32_t *GPFSEL1;
static volatile uint32_t *GPSET0;
static volatile uint32_t *GPCLR0;

static int nobrand_open(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "welcome\n");
    return 0;
}

static int nobrand_release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "release\n");
    return 0;
}

static void ledon(void)
{
    printk(KERN_INFO "LED ON\n");
    *GPSET0 = (1 << 18);
}

static void ledoff(void)
{
    printk(KERN_INFO "LED OFF\n");
     *GPCLR0 = (1 << 18);
}

static long nobrand_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    switch (cmd)
    {
        case _IO(0, 3):
            ledon();
            break;
        case _IO(0, 4):
            ledoff();
            break;
    }
    return 0;
}

static struct file_operations fops = {
    .open = nobrand_open,
    .release = nobrand_release,
    .unlocked_ioctl = nobrand_ioctl,
};

static int nobrand_init(void)
{
    BASE = (uint32_t *)ioremap(0xFE200000, 256);
    GPFSEL1 = BASE + (0x04 / 4); //자료형 크기 만큼?? 뭔솔
    GPSET0 = BASE + (0x1C / 4);
    GPCLR0 = BASE + (0x28 / 4);

    *GPFSEL1 &= ~(0x7 << 24);
    *GPFSEL1 |= (1 << 24);



    if (register_chrdev(NOD_MAJOR, NOD_NAME, &fops) < 0)
    {
        printk("INIT FALE\n");
    }

    printk(KERN_INFO "hi\n");
    return 0;
}

static void nobrand_exit(void)
{
    *GPCLR0 = (1 << 18);
    iounmap(BASE);

    unregister_chrdev(NOD_MAJOR, NOD_NAME);
    printk(KERN_INFO "bye\n");
}

module_init(nobrand_init);
module_exit(nobrand_exit);
