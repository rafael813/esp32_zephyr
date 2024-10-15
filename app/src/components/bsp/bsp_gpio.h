

#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__

#include <zephyr/drivers/gpio.h>

bool bspGPIOReady(const struct gpio_dt_spec *pin);
int bspGPIOPinConfigure(const struct gpio_dt_spec *pin, gpio_flags_t flags);
bool bspGPIOGetLineSensor(const struct device *port, gpio_pin_t pin);

#endif /*__BSP_GPIO_H__*/
