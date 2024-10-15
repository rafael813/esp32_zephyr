#include "bsp_gpio.h"





// Check if the GPIO pin is ready
__weak bool bspGPIOReady(const struct gpio_dt_spec *pin){
	return gpio_is_ready_dt(pin);
}


//Configure the GPIO pin with the specified flags
__weak int bspGPIOPinConfigure(const struct gpio_dt_spec *pin, gpio_flags_t flags){
	return  gpio_pin_configure_dt(pin, flags);
}

//Get the state of GPIO pin(high or low)
__weak int bspGPIOGetLineSensor(const struct  device *port, gpio_pin_t pin){
	return gpio_pin_get_raw(port, pin) == 1;
}
