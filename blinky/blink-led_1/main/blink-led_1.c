#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h" // To get task name

#include "driver/gpio.h"
#include "esp_log.h" // For ESP_LOGI()

/* Settings */

/* This enum is defined at components/esp_hal_gpio/esp32/include/soc/gpio_num.h */
static const gpio_num_t led_pin = GPIO_NUM_13;

void toggle_LED0(void *parameter) {

	/* Let's define the time for delay */
	const uint32_t sleep_time_ms = 1000;
	uint8_t led_state = 0;
	char *ourTaskName = pcTaskGetName(NULL);

	while (1) {
		// Toggle the LED
		led_state = !led_state;

		gpio_set_level(led_pin, led_state);
		ESP_LOGI(ourTaskName, "Hello, toggle state is: %d\n", led_state);

		/*
		 * This API accepts value in number of system ticks. Thus we
		 * need to convert it to ms
		 */
		vTaskDelay(sleep_time_ms / portTICK_PERIOD_MS);
	}
}

void toggle_LED1(void *parameter) {

	const uint32_t sleep_time_ms = 1200;
	uint8_t led_state = 0;
	char *ourTaskName = pcTaskGetName(NULL);

	while (1) {
		led_state = !led_state;

		gpio_set_level(led_pin, led_state);
		ESP_LOGI(ourTaskName, "Hello, toggle state is: %d\n", led_state);
		vTaskDelay(sleep_time_ms / portTICK_PERIOD_MS);
	}
}

void app_main(void)
{

	// Configure the GPIO
	gpio_reset_pin(led_pin);
	gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);

	xTaskCreate(toggle_LED0,  // Function to be called
		    "Toggle 1",  // Name of task
		    1024,        // Stack size (bytes in ESP32, words in FreeRTOS)
		    NULL,        // Parameter to pass to function
		    1,           // Task priority (0 to configMAX_PRIORITIES - 1)
		    NULL);       // Task handle

	xTaskCreate(toggle_LED1,
		    "Toggle 2",
		    1024,
		    NULL,
		    1,
		    NULL);
}
