SOC_FAMILY = "mx7:mx7d"
MACHINEOVERRIDES =. "mx7:mx7d:"

require conf/machine/include/imx-base.inc
require conf/machine/include/arm/armv7a/tune-cortexa7.inc

MACHINE_FEATURES:remove:mx7-nxp-bsp = "nxp8987"
PACKAGECONFIG:remove:imx-nxp-bsp = " cryptodev-linux"

IMX_DEFAULT_BSP = "nxp"

UBOOT_CONFIG ??= "sd"
UBOOT_CONFIG[sd] = "cl-som-imx7_defconfig,sdcard"

KERNEL_DEVICETREE += " \
	nxp/imx/imx7d-cl-som-imx7.dtb \
"

IMAGE_BOOT_FILES = "zImage "
IMAGE_BOOT_FILES += " imx7d-cl-som-imx7.dtb "

MACHINE_FEATURES += " alsa bluetooth serial usbhost wifi pci "

MACHINE_FIRMWARE = "linux-firmware-wl18xx \
			linux-firmware-iwlwifi-6000g2a-5 linux-firmware-iwlwifi-6000g2a-6 \
			linux-firmware-iwlwifi-6000g2b-5 linux-firmware-iwlwifi-6000g2b-6"


# Set Serial console
SERIAL_CONSOLE = "115200 ttymxc0"

IMAGE_INSTALL:append = " \
	kernel-image \
	kernel-modules \
	kernel-devicetree \
"
