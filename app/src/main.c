/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

#include <app/drivers/blink.h>

#include <app_version.h>

const struct device*tcrt5000 = device_get_binding("TCRT5000");



if (tcrt5000 = NULL){
	printk("Falied to get TCRT5000 device\n");
}else{
	int sensor_value = tcrt5000_read(tcrt5000);
	printk("TCRT5000 sensor value : /%\n", sensor_value);
}
