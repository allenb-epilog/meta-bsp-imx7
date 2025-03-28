FILESEXTRAPATHS:prepend := "${THISDIR}/compulab/imx7:"

include compulab/imx7.inc

DEFAULT_DEFCONFIG:cl-som-imx7 = "compulab_imx7"

do_configure:append () {
    oe_runmake ${DEFAULT_DEFCONFIG}_defconfig
}

do_compile:prepend() {
    if [ ${BUILD_REPRODUCIBLE_BINARIES} -eq 1 ];then
        export SOURCE_DATE_EPOCH=$(date +%s)
    fi
}

do_install:prepend() {
    mkdir -p "${D}${nonarch_base_libdir}/modules/${KERNEL_VERSION}/"
    touch "${D}${nonarch_base_libdir}/modules/${KERNEL_VERSION}/source"
}

COMPATIBLE_MACHINE = "cl-som-imx7"
DEPENDS += "firmware-imx"
