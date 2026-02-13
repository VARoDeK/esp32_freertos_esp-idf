#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"

/* Settings */

/* This enum is defined at components/esp_hal_gpio/esp32/include/soc/gpio_num.h */
static const gpio_num_t led_pin = GPIO_NUM_13;

/* Let's define the time for delay */
static const uint32_t sleep_time_ms = 1000;

void app_main(void)
{
	uint8_t led_state = 0;

	// Configure the GPIO
	gpio_reset_pin(led_pin);
	gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);

	// Superloop
	while (1) {
		// Toggle the LED
		led_state = !led_state;

		gpio_set_level(led_pin, led_state);
		printf("LED state: %d\n", led_state);

		/*
		 * This API accepts value in number of system ticks. Thus we
		 * need to convert it to ms
		 */
		vTaskDelay(sleep_time_ms / portTICK_PERIOD_MS);
	}
}
