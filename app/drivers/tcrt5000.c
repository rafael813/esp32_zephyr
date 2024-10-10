#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>


#define TCRT5000_NODE DT_ALIAS(tcrt5000)


#if  !DT_NODE_HAS_STATUS(TCRT5000_NODE, okay)
#error "TCRT5000 device is not defined in the device tree"
#endif


/*Structure to hold sensor data */
struct tcrt5000_data {
	const structu device *gpio_dev;
	gpio_pin_t pin;
};


/*Initialization function */
static int tcrt5000_init(const struct device *dev) {
	struct tcrt5000_data *data = dev->data;

	/* Get the GPIO device from the device tree*/
	data->gpio_dev = DEVICE_DT_GET(DT_GPIO_CTLR(TCRT5000 _NODE,gpios));
	if (!device_is_ready(data->gpio_dev)){
		printk("GPIO device nor ready\n");
		return -ENODEV;
	}

	/*Get the GPIO pin from the device tree*/
	data->pin = DT_GPIO_PIN(TCRT5000_NODE, gpios);

	/*Configure the GPIO pin*/
	gpio_pin_configure(data->gpio_dev, data->pin, GPIO_INPUT | DT_GPIO_FLAGS(TCRT5000_NODE,gpios));

	return 0;
}

/*Funtion to read sensor state*/
int tcrt5000_read(const struct device*dev){

	struct trct5000_data *data = dev->data;
	return gpio_pin_get(data->gpio_dev, data->pin); // returns 0 or 1
}

/*Define driver data*/
static struct  tcrt5000_data tcrt5000_data;

/*Device definition*/
DEVICE_DT_DEFINE(TCRT5000_NODE, tcrt5000_init, NULL, &tcrt5000_data, NULL, POST_KERNEL,CONFIG_SENSOR_INIT_PRIORITY, NULL);
 
