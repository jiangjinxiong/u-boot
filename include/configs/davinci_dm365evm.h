/*
 * Copyright (C) 2009 Texas Instruments Incorporated
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_HOSTNAME		TFC_IPNC

/* Spectrum Digital TMS320DM365 EVM board */
#define DAVINCI_DM365EVM

#define CONFIG_SKIP_LOWLEVEL_INIT	/* U-Boot is a 3rd stage loader */
#define CONFIG_SYS_NO_FLASH		/* that is, no *NOR* flash */
#define CONFIG_SYS_CONSOLE_INFO_QUIET

/* SoC Configuration */
#define CONFIG_ARM926EJS				/* arm926ejs CPU */
#define CONFIG_SYS_TIMERBASE		0x01c21400	/* use timer 0 */
#define CONFIG_SYS_HZ_CLOCK		24000000	/* timer0 freq */
#define CONFIG_SYS_HZ			1000
#define CONFIG_SOC_DM365
#define CONFIG_DISPLAY_CPUINFO

/* Memory Info */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM_1			0x80000000
#define PHYS_SDRAM_1_SIZE		(128 << 20)	/* 128 MiB */

/* Serial Driver info: UART0 for console  */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	-4
#define CONFIG_SYS_NS16550_COM1		0x01c20000
#define CONFIG_SYS_NS16550_CLK		CONFIG_SYS_HZ_CLOCK
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200

/* EEPROM definitions for EEPROM on DM365 EVM */
//#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN		2
//#define CONFIG_SYS_I2C_EEPROM_ADDR		0x50
//#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS	6
//#define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS	20

/* Network Configuration */
#define CONFIG_DRIVER_TI_EMAC
#define CONFIG_MII
#define CONFIG_BOOTP_DEFAULT
#define CONFIG_BOOTP_DNS
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_NET_RETRY_COUNT	10

#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		192.168.3.168
#define CONFIG_GATEWAYIP    192.168.3.1
#define CONFIG_SERVERIP		192.168.3.29
#define CONFIG_ETHADDR      00:01:02:03:04:05

/* I2C */
#undef CONFIG_HARD_I2C
#undef CONFIG_DRIVER_DAVINCI_I2C
#define CONFIG_SYS_I2C_SPEED		400000
#define CONFIG_SYS_I2C_SLAVE		0x10	/* SMBus host address */

/* NAND: socketed, two chipselects, normally 2 GBytes */
#define CONFIG_NAND_DAVINCI
#define CONFIG_SYS_NAND_CS		2
#define CONFIG_SYS_NAND_USE_FLASH_BBT
#define CONFIG_SYS_NAND_4BIT_HW_ECC_OOBFIRST
#undef CONFIG_SYS_NAND_HW_ECC
#define CONFIG_SYS_NAND_PAGE_2K

#define CONFIG_SYS_NAND_LARGEPAGE
#define CONFIG_SYS_NAND_BASE_LIST	{ 0x02000000, }
/* socket has two chipselects, nCE0 gated by address BIT(14) */
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_MAX_CHIPS	1

/* SD/MMC */
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_DAVINCI_MMC
#define CONFIG_DAVINCI_MMC_SD1
#define CONFIG_MMC_MBLOCK

#define PINMUX4_USBDRVBUS_BITCLEAR       0x3000
#define PINMUX4_USBDRVBUS_BITSET         0x2000

/* USB Configuration */
#undef CONFIG_USB_DAVINCI
#undef CONFIG_MUSB_HCD

#ifdef CONFIG_USB_DAVINCI
#define CONFIG_CMD_USB         /* include support for usb      */
#define CONFIG_CMD_STORAGE     /* include support for usb      */
#define CONFIG_CMD_FAT         /* include support for FAT/storage*/
#define CONFIG_DOS_PARTITION   /* include support for FAT/storage*/
#endif

#ifdef CONFIG_MUSB_HCD         /* include support for usb host */
#define CONFIG_CMD_USB         /* include support for usb cmd */
#define CONFIG_USB_STORAGE     /* MSC class support */
#define CONFIG_CMD_STORAGE     /* inclue support for usb-storage cmd */
#define CONFIG_CMD_FAT         /* inclue support for FAT/storage */
#define CONFIG_DOS_PARTITION   /* inclue support for FAT/storage */

#ifdef CONFIG_USB_KEYBOARD     /* HID class support */
#define CONFIG_SYS_USB_EVENT_POLL

#define CONFIG_PREBOOT "usb start"
#endif /* CONFIG_USB_KEYBOARD */
#endif /* CONFIG_MUSB_HCD */

#ifdef CONFIG_MUSB_UDC
#define CONFIG_USB_DEVICE              1
#define CONFIG_USB_TTY                 1
#define CONFIG_SYS_CONSOLE_IS_IN_ENV   1
#define CONFIG_USBD_VENDORID           0x0451
#define CONFIG_USBD_PRODUCTID          0x5678
#define CONFIG_USBD_MANUFACTURER       "Texas Instruments"
#define CONFIG_USBD_PRODUCT_NAME       "DM365VM"
#endif /* CONFIG_MUSB_UDC */

/* U-Boot command configuration */
#include <config_cmd_default.h>

#define CONFIG_CMD_BDI
#undef CONFIG_CMD_FLASH
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_SETGETDCR

#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_DHCP
#undef CONFIG_CMD_I2C
#define CONFIG_CMD_PING
#define CONFIG_CMD_SAVES

#ifdef CONFIG_CMD_BDI
#define CONFIG_CLOCKS
#endif

#ifdef CONFIG_MMC
#define CONFIG_DOS_PARTITION
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_CMD_MMC
#endif

#ifdef CONFIG_NAND_DAVINCI
#define CONFIG_CMD_NAND
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_PARTITIONS
#define CONFIG_MTD_DEVICE
#define CONFIG_CMD_UBI
#define CONFIG_RBTREE
#endif

#define CONFIG_CRC32_VERIFY
#define CONFIG_MX_CYCLIC

/* U-Boot general configuration */
#undef CONFIG_USE_IRQ				/* No IRQ/FIQ in U-Boot */
#define CONFIG_BOOTFILE		"uImage"	/* Boot file name */
#define CONFIG_SYS_PROMPT	"DM36x SD-Boot# "	/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE	1024		/* Console I/O Buffer Size  */
#define CONFIG_SYS_PBSIZE			/* Print buffer size */ \
		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	16		/* max number of command args */
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_LONGHELP

#ifdef CONFIG_NAND_DAVINCI
//#define CONFIG_ENV_SIZE		(128 << 10)	/* 128 KiB */
//#define CONFIG_ENV_IS_IN_NAND
//#define CONFIG_ENV_OFFSET	0x4e0000
#undef CONFIG_ENV_IS_IN_FLASH
#endif

#if defined(CONFIG_MMC) && !defined(CONFIG_ENV_IS_IN_NAND)
#define CONFIG_CMD_ENV
#define CONFIG_SYS_MMC_ENV_DEV	0
#define CONFIG_ENV_SIZE		(16 << 10)	/* 16 KiB */
#define CONFIG_ENV_OFFSET	(51 << 9)	/* Sector 51 */
#define CONFIG_ENV_IS_IN_MMC
#undef CONFIG_ENV_IS_IN_FLASH
#endif
      
#define CONFIG_CMDLINE_EDITING
#define CONFIG_VERSION_VARIABLE
#define CONFIG_TIMESTAMP

/* U-Boot memory configuration */
#define CONFIG_STACKSIZE		    (256 << 10)	/* 256 KiB */
#define CONFIG_SYS_MALLOC_LEN		(1 << 20)	/* 1 MiB */
#define CONFIG_SYS_MEMTEST_START	0x87000000	/* physical address */
#define CONFIG_SYS_MEMTEST_END		0x88000000	/* test 16MB RAM */

/* Linux interfacing */
#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_SYS_BARGSIZE	1024			/* bootarg Size */
#define CONFIG_SYS_LOAD_ADDR	0x82000000		/* kernel address */

/* NAND configuration issocketed with two chipselects just like the DM355 EVM.
 * It normally comes with a 2GByte SLC part with 2KB pages
 * (and 128KB erase blocks); other
 * 2GByte parts may have 4KB pages, 256KB erase blocks, and use MLC.  (MLC
 * pretty much demands the 4-bit ECC support.)  You can of course swap in
 * other parts, including small page ones.
 */
#define CONFIG_CMD_NAND_YAFFS		
#define CONFIG_JFFS2_CMDLINE		
#define CONFIG_JFFS2_NAND		
#define CONFIG_JFFS2_DEV		"nand0" /* NAND dev jffs2 lives on */
#define CONFIG_JFFS2_PART_OFFSET 	0	/* start of jffs2 partition */
#define CONFIG_JFFS2_PART_SIZE		(256 * 1024 * 1024) /* partition */

#define CONFIG_MAX_RAM_BANK_SIZE	(256 << 20)	/* 256 MB */

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_INIT_SP_ADDR		\
	(CONFIG_SYS_SDRAM_BASE + 0x1000 - GENERATED_GBL_DATA_SIZE)


#define CONFIG_BOOTDELAY	1

#define CONFIG_BOOTCOMMAND  \
"run led_off;run update_all;run led_on;"\
"echo ���ںˡ��ļ�ϵͳ��д��ɡ�;\n"\
"echo  �밴�����²�����SD����д�����ļ���NAND...;\n"\
"echo  1��������ϵ�1��������;\n"\
"echo  2�����ò��뿪��ΪNAND����ģʽ;\n"\
"echo  3�������ϵ磬�ں��������SD���������嵽NAND;\n"\
"echo  4���ϵ��ȴ�20�����ϣ����ɰγ�SD��\n\n;"
			
#define CONFIG_BOOTARGS   \
"mem=48M console=ttyS0,115200n8 "   \
"root=/dev/mtdblock3 rootfstype=cramfs rw init=/init "  \
"ip=$ipaddr:$serverip:$gatewayip:$netmask:$hostname:eth0:off eth=$ethaddr " \
"cmemk.phys_start=0x83000000 cmemk.phys_end=0x88000000 cmemk.phys_start_1=0x00001000 cmemk.phys_end_1=0x00008000 cmemk.pools_1=1x28672 cmemk.allowOverlap=1"

#define CONFIG_BOOTARGS_NAND     \
"setenv bootargs mem=48M console=ttyS0,115200n8 " \
"root=/dev/mtdblock3 rootfstype=cramfs rw init=/init "  \
"ip=$ipaddr:$serverip:$gatewayip:$netmask::eth0:off eth=$ethaddr " \
"cmemk.phys_start=0x83000000 cmemk.phys_end=0x88000000 cmemk.phys_start_1=0x00001000 cmemk.phys_end_1=0x00008000 cmemk.pools_1=1x28672 cmemk.allowOverlap=1;"\
"saveenv"

#define CONFIG_BOOTARGS_MMC     \
"setenv bootargs mem=48M console=ttyS0,115200n8 " \
"root=/dev/mmcblk0p1 rootfstype=cramfs rw init=/init "  \
"ip=$ipaddr:$serverip:$gatewayip:$netmask::eth0:off eth=$ethaddr " \
"cmemk.phys_start=0x83000000 cmemk.phys_end=0x88000000 cmemk.phys_start_1=0x00001000 cmemk.phys_end_1=0x00008000 cmemk.pools_1=1x28672 cmemk.allowOverlap=1;"\
"saveenv"

#define CONFIG_BOOTARGS_NFS     \
"setenv bootargs mem=48M console=ttyS0,115200n8 " \
"root=/dev/nfs rw nfsroot=$serverip:/home/jiangjx/UbuntuShare/filesys nolock " \
"ip=$ipaddr:$serverip:$gatewayip:$netmask::eth0:off eth=$ethaddr " \
"cmemk.phys_start=0x83000000 cmemk.phys_end=0x88000000 cmemk.phys_start_1=0x00001000 cmemk.phys_end_1=0x00008000 cmemk.pools_1=1x28672 cmemk.allowOverlap=1;"\
"saveenv"
  
#define CONFIG_EXTRA_ENV_SETTINGS     \	
"loadaddr=82000000\0"\
"kernel1addr=500000\0"\
"kernel1erasesize=400000\0"\
"rootfs1addr=900000\0"\
"rootfs1erasesize=2000000\0"\
"kernel2addr=2900000\0"\
"kernel2erasesize=400000\0"\
"rootfs2addr=2D00000\0"\
"rootfs2erasesize=2000000\0"\
"led_on=mw 01C4000C E15AFFFF;mw 01C67010 0;mw 01C6701C FFFFFFFF\0"\
"led_off=mw 01C4000C E15AFFFF;mw 01C67010 0;mw 01C67018 FFFFFFFF\0"\
"update_ubl=mmc rescan;nand erase 20000 A0000;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk01;nand write $loadaddr 20000 20000;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk02;nand write $loadaddr 40000 20000;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk03;nand write $loadaddr 60000 20000;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk04;nand write $loadaddr 80000 20000;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk05;nand write $loadaddr A0000 20000\0"\  
"update_uboot=mmc rescan;nand erase 220000 280000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk17;nand write $loadaddr 220000 80000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk21;nand write $loadaddr 2A0000 80000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk25;nand write $loadaddr 320000 80000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk29;nand write $loadaddr 3A0000 80000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk33;nand write $loadaddr 420000 80000\0"\
"update_kernel=mmc rescan;fatload mmc 0 $loadaddr sd/uImage;"\
    "nand erase $kernel1addr $kernel1erasesize;"\
	"nand write $loadaddr $kernel1addr $filesize;"\
	"nand erase $kernel2addr $kernel2erasesize;"\
	"nand write $loadaddr $kernel2addr $filesize\0"\
"update_rootfs=mmc rescan;fatload mmc 0 $loadaddr sd/rootfs.cramfs;"\
    "nand erase $rootfs1addr $rootfs1erasesize;"\
	"nand write $loadaddr $rootfs1addr $filesize;" \
	"nand erase $rootfs2addr $rootfs2erasesize;"\
	"nand write $loadaddr $rootfs2addr $filesize\0"\                
"update_all=mmc rescan;nand scrub.chip;nand erase.chip;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk01;nand write $loadaddr 20000 20000;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk02;nand write $loadaddr 40000 20000;"\
 	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk03;nand write $loadaddr 60000 20000;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk04;nand write $loadaddr 80000 20000;"\
	"fatload mmc 0 $loadaddr sd/ubl_nand/ubl_blk05;nand write $loadaddr A0000 20000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk17;nand write $loadaddr 220000 80000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk21;nand write $loadaddr 2A0000 80000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk25;nand write $loadaddr 320000 80000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk29;nand write $loadaddr 3A0000 80000;"\
	"fatload mmc 0 $loadaddr sd/uboot_nand/uboot_blk33;nand write $loadaddr 420000 80000;"\
	"fatload mmc 0 $loadaddr sd/uImage;nand write $loadaddr $kernel1addr $filesize;"\                                
	"fatload mmc 0 $loadaddr sd/rootfs.cramfs;nand write $loadaddr $rootfs1addr $filesize\0"
	                                  //"nand write $loadaddr $rootfs2addr $filesize\0"
                    
//mw 01C4000C e15affff  PINMUX3
//mw 01C67010 0       ����GPIO���
//mw 01C67018 ffffffff  ����
//mw 01C6701C ffffffff   ����


#define MTDIDS_DEFAULT	"nand0=davinci_nand.0"

//#ifdef CONFIG_SYS_NAND_LARGEPAGE
/*  Use same layout for 128K/256K blocks; allow some bad blocks */
#define PART_UBL		"3m(ubl)ro,"
//#else
/* Assume 16K erase blocks; allow a few bad ones. */
//#define PART_BOOT		"512k(bootloader)ro,"
//#endif

#define PART_UBOOT   	"2m(uboot),"	
#define PART_KERNEL1	"4m(kernel1),"	
#define PART_ROOTFS1	"32m(rootfs1),"	
#define PART_KERNEL2	"4m(kernel2),"	
#define PART_ROOTFS2	"32m(rootfs2),"	
#define PART_REST		"-(paraapp)"

#define MTDPARTS_DEFAULT	\
"mtdparts=davinci_nand.0:" PART_UBL PART_UBOOT PART_KERNEL1 PART_ROOTFS1 PART_KERNEL2 PART_ROOTFS2 PART_REST


#endif /* __CONFIG_H */
