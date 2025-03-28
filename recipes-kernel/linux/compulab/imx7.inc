SRC_URI:append = " \
	file://0001-ARM-dts-imx7d-cl-som-imx7-fix-uart1-parent-clock.patch \
	file://0002-ARM-dts-imx7d-cl-som-imx7-fix-pfuze3000-PMIC-regulat.patch \
	file://0003-ARM-dts-imx7d-cl-som-imx7-fix-i2c2-configuration.patch \
	file://0004-ARM-dts-imx7d-cl-som-imx7-add-fec-phy-reset.patch \
	file://0005-ARM-dts-imx7d-cl-som-imx7-add-RTC-support.patch \
	file://0006-ARM-dts-imx7d-cl-som-imx7-add-support-for-gpio-led.patch \
	file://0007-ARM-dts-imx7d-cl-som-imx7-add-support-for-touchscree.patch \
	file://0008-ARM-dts-imx7d-cl-som-imx7-add-support-for-SPI-flash.patch \
	file://0009-ARM-dts-imx7d-cl-som-imx7-add-support-for-USB-host.patch \
	file://0010-ARM-dts-imx7d-cl-som-imx7-add-support-for-USB-hub.patch \
	file://0011-ARM-dts-imx7d-cl-som-imx7-usbotg1-2-disable-low-powe.patch \
	file://0012-ARM-dts-imx7d-cl-som-imx7-add-support-for-watchdog.patch \
	file://0013-ARM-dts-imx7d-cl-som-imx7-add-support-for-NAND-flash.patch \
	file://0014-ARM-dts-imx7d-cl-som-imx7-add-WiLink8-WLAN-support.patch \
	file://0015-ARM-dts-imx7d-cl-som-imx7-add-WiLink-Bluetooth-suppo.patch \
	file://0017-ARM-dts-imx7d-cl-som-imx7-add-analog-audio-support.patch \
	file://0018-ARM-dts-imx7d-sbc-imx7-update-model-string.patch \
	file://0019-ARM-dts-imx7d-sbc-imx7-add-support-for-pwm-backlight.patch \
	file://0020-ARM-dts-imx7d-sbc-imx7-add-gpio-extender-support.patch \
	file://0021-ARM-dts-imx7d-sbc-imx7-add-support-for-baseboard-eep.patch \
	file://0022-ARM-dts-imx7d-sbc-imx7-add-LCD-support.patch \
	file://0023-ARM-dts-imx7d-sbc-imx7-add-DVI-support.patch \
	file://0024-ARM-dts-imx7d-sbc-imx7-add-CAN-bus-support.patch \
	file://0027-ARM-dts-imx7d-sbc-imx7-enable-PCIe.patch \
	file://0028-ARM-dts-imx7d-sbc-imx7-enable-SB-SOM-peripheral.patch \
	file://0029-ARM-dts-imx7d-add-support-for-high-speed-modes-on-SD.patch \
	file://0030-ARM-dts-imx7d-sbc-imx7-add-support-for-high-speed-mo.patch \
	file://0031-ARM-dts-imx7d-sbc-imx7-add-support-for-m4.patch \
	file://0036-MLK-13605-ARM-dts-imx7d.dtsi-configure-USB-burst-pro.patch \
	file://0037-mtd-tests-nandecctest-add-dummy-module-parameter.patch \
	file://0038-ARM-configs-add-defconfig-for-compulab-imx7-based-de.patch \
	file://0039-cl-som-imx7-defconfig-Disable-CONFIG_FW_LOADER_USER_.patch \
	file://0040-cl-som-imx7-dts-phy-Fix-for-rev-1.4.patch \
	file://0041-video-mipi-panel-ti-sn65dsi83-add-MIPI-LVDS-bridge-d.patch \
	file://0042-compulab_imx7-defconfig-Enable-FB_MXC_SN65DSI8X.patch \
	file://0044-mipi_dsi-platform-Merge-the-4.14.98-code.patch \
	file://defconfig \
"

SRC_URI:append = " https://github.com/compulab-yokneam/bin/raw/linux-firmware/imx-sdma-20230404.tar.bz2;name=imx-sdma-firmware "
SRC_URI[imx-sdma-firmware.md5sum] = "a1169448bf2f020a3f48f51c4961022a"
SRC_URI[imx-sdma-firmware.sha256sum] = "004ad1f9cf5b1176e71765794a5bfdcffdf44b9a5c1545188a171554bf4439a1"

do_configure:append() {
    if [ ! -d ${S}/lib/firmware/imx ];then
        mkdir -p ${S}/lib/firmware
        cp -a ${WORKDIR}/imx ${S}/lib/firmware
    fi
}


#	file://0016-ASoC-fsl-add-analog-audio-support-switch-for-imx-boa.patch
#	file://0018-ARM-dts-imx7d-sbc-imx7-update-model-string.patch
#	file://0019-ARM-dts-imx7d-sbc-imx7-add-support-for-pwm-backlight.patch
#	file://0020-ARM-dts-imx7d-sbc-imx7-add-gpio-extender-support.patch
#	file://0021-ARM-dts-imx7d-sbc-imx7-add-support-for-baseboard-eep.patch
#	file://0022-ARM-dts-imx7d-sbc-imx7-add-LCD-support.patch
#	file://0023-ARM-dts-imx7d-sbc-imx7-add-DVI-support.patch
#	file://0024-ARM-dts-imx7d-sbc-imx7-add-CAN-bus-support.patch
#	file://0025-PCIe-imx6-release-phy-reset-before-toggling-reset-gp.patch
#	file://0026-PCIe-imx6-imx7d-add-support-for-phy-refclk-source-co.patch
#	file://0027-ARM-dts-imx7d-sbc-imx7-enable-PCIe.patch
#	file://0028-ARM-dts-imx7d-sbc-imx7-enable-SB-SOM-peripheral.patch
#	file://0029-ARM-dts-imx7d-add-support-for-high-speed-modes-on-SD.patch
#	file://0030-ARM-dts-imx7d-sbc-imx7-add-support-for-high-speed-mo.patch
#	file://0031-ARM-dts-imx7d-sbc-imx7-add-support-for-m4.patch
#	file://0032-ARM-dts-imx7d-sbc-iot-imx7-add-basic-board-support.patch
#	file://0033-ARM-dts-imx7d-sbc-iot-imx7-add-support-for-high-spee.patch
#	file://0034-ARM-dts-imx7d-sbc-iot-imx7-add-support-for-CAN-bus.patch
#	file://0035-ARM-dts-imx7d-sbc-iot-imx7-add-support-for-RS485-in-.patch
#	file://0043-ARM-dts-imx7d-sbc-iot-imx7-add-LVDS-panel-support.patch
#	file://0045-compulab_imx7_defconfig-Add-sdma-imx7d.bin.patch