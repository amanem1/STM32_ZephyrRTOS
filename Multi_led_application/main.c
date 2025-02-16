
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define GPIO_NODE DT_ALIAS(led0)
#define GPIO_NODE1 DT_ALIAS(led1)
#define GPIO_NODE2 DT_ALIAS(led2)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led[] =
{ GPIO_DT_SPEC_GET(GPIO_NODE, gpios),
 GPIO_DT_SPEC_GET(GPIO_NODE1, gpios),
GPIO_DT_SPEC_GET(GPIO_NODE2, gpios)
};

#define num_leds ARRAY_SIZE(led)


int main(void)
{
	int ret;
	bool led_state = true;
    /*make sure system doesnt fail or unsupported*/

	for(int i = 0 ; i < num_leds ; i++)
    {
        if(!gpio_is_ready_dt(&led[i]))
        {
            return 0  ;
        }


        ret = gpio_pin_configure_dt(&led[i], GPIO_OUTPUT_ACTIVE);
	    if (ret < 0) 
        {
		    return 0;
	    }
    }


	while (1) {

        for(int i = 0 ; i < num_leds ; i++)
        {
            ret = gpio_pin_toggle_dt(&led[i]);
        }
		printf("LED state: %s\n", led_state ? "ON" : "OFF");
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}