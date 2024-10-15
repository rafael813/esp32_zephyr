#include <errno.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#include "bsp_gpio.h"
#include "tcrt5000.h"

#define  TCRT5000_NODE DT_ALIAS(tcrt5000)

static const struct gpio_dt_spec tcrt5000 = GPIO_DT_SPEC_GET(TCRT5000_NODE, gpios);

int configureTCRT5000(void){
	if (!bspGPIOReady(&tcrt5000.port)){
		return -EBUSY;
	}

	return bspGPIOPinConfigure(&tcrt5000,GPIO_INPUT);
}

int readTCRT5000(void){
	int tcrt5000_value = bspGPIOGetLineSensor(&tcrt5000.port,&tcrt5000.pin);

	if (tcrt5000_value == -EIO){
		//handle error (e.g, I/O error)
		return -EIO;
	}
	else if (tcrt5000_value == -EWOULDBLOCK){
		//handle error (e.g , blocking issues)
		return -EWOULDBLOCK;

	}

	return tcrt5000_value; //0 if reflective(white) , 1 is non-reflective(black)

}


