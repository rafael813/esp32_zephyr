/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include "tcrt5000.h"

int main(void){

	int ret;

	//Configure TCRT5000 sensor pin
	ret = configureTCRT5000();

	if (ret != 0){
		//Handle configuration error
		return ret;
	}

	while(1){
		//Read the TCRT5000 sensor state
		int sensor_value = readTCRT5000();

		if (sensor_value == 0){
			//white surface detected
			printk("WHITE \n");

		} else if {
			//black surface detected
			printk("BLACK\N");
		} else {
			//handle sensor error
			printk("Error reading TCRT5000 sensor \n");
		}

		//Add a delay between reads
		k_msleep(100);
	}

	return 0;
}

