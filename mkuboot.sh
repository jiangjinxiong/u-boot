#!/bin/sh
	
export BUILD_DIR="tmp/build"
export CROSS_COMPILE=arm-none-linux-gnueabi-
make distclean
make davinci_dm365evm_config
make
echo "cp $BUILD_DIR/u-boot.bin $sd_dm36x_dir/sdcard_flash/u-boot_dm36x_sdmmc.bin"
cp $BUILD_DIR/u-boot.bin $sd_dm36x_dir/sdcard_flash/u-boot_dm36x_sdmmc.bin
