#!/bin/sh
	
export BUILD_DIR="tmp/build"
export CROSS_COMPILE=arm-none-linux-gnueabi-
make distclean
make davinci_dm365evm_config
make all
echo "cp $BUILD_DIR/u-boot.bin $sdboot_dir/sdcard_flash/u-boot_dm36x_sdmmc_v1.01.bin"
cp $BUILD_DIR/u-boot.bin $sdboot_dir/sdcard_flash/u-boot_dm36x_sdmmc_v1.01.bin
