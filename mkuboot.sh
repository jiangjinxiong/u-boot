#!/bin/sh
	
export BUILD_DIR="tmp/build"
export CROSS_COMPILE=arm-none-linux-gnueabi-
#make distclean
make davinci_dm365evm_config
make all
echo "cp $BUILD_DIR/u-boot.bin $sdboot_dir/original/u-boot_dm36x_nand.bin"
cp $BUILD_DIR/u-boot.bin $sdboot_dir/original/u-boot_dm36x_nand.bin
