#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

const char message[] = "Hello, I am being printed";

/*
 * ESP32 is dual-core.
 *	- Core 0 - PRO_CPU
 *	- Core 1 - APP_CPU
 * We will use APP_CPU
 */
static const uint8_t core = 1;


/*
 * By default, the 'printf()' will write to UART Serial
 */
void high_task(void *parameter) {
	const uint32_t sleep_time_ms = 1200;
	const size_t len = strlen(message);

	while (1) {
		printf("\nHigh Task: ");
		for (size_t i = 0; i < len; i++) {
			printf("%c", message[i]);
			vTaskDelay(10 / portTICK_PERIOD_MS);
		}
		printf("\n");
		vTaskDelay(sleep_time_ms / portTICK_PERIOD_MS);
	}
}

void low_task(void *parameter) {
	const uint32_t sleep_time_ms = 900;
	const size_t len = strlen(message);

	while (1) {
		printf("\nLow Task: ");
		for (size_t i = 0; i < len; i++) {
			printf("%c", message[i]);
			vTaskDelay(10 / portTICK_PERIOD_MS);
		}
		printf("\n");
		vTaskDelay(sleep_time_ms / portTICK_PERIOD_MS);
	}
}

void app_main(void)
{

	/*
	 * "xTaskCreatePinnedToCore()" will invoke FreeRTOS's "xTaskCreate()"
	 */
	xTaskCreatePinnedToCore (low_task,  // Function to be called
		"Low Priority Task",  // Name of task
		1024,        // Stack size (bytes in ESP32, words in FreeRTOS)
		NULL,        // Parameter to pass to function
		0,           // Task priority (0 to configMAX_PRIORITIES - 1)
		NULL,        // Task handle
		core);       // Pin the task to APP_CPU / Core1

	xTaskCreatePinnedToCore (high_task,  // Function to be called
		"High Priority Task",  // Name of task
		1024,        // Stack size (bytes in ESP32, words in FreeRTOS)
		NULL,        // Parameter to pass to function
		10,          // Task priority (0 to configMAX_PRIORITIES - 1)
		NULL,         // Task handle
		core);       // Pin the task to APP_CPU / Core1
}


/*
 * Just going to paste the output here:
 * ====================================
High Task: Hello, I am being print
Low Task: Hede
llo, I am being printed

High Task: Hello, I am being p
Low Task: Hrientledl
o, I am being printed

High Task: Hello, I am bei
Low Task: Hnge plrilntoed,
 I am being printed

High Task: Hello, I am
Low Task: H beeilngl pori,nt edI
 am being printed

High Task: Hello,
Low Task: HI eaml bleiong, p riInt eda
m being printed

High Task: Hel
Low Task: Hloe, lI lamo b,ei ngI p riantmed
being printed

Low Task: H
High Task: Heelllol, oI ,am  bIei nga pmri ntbede
ing printed

Low Task: Hel
High Task: Hlelolo,,  I Iam  baeimng  pbrientiedn
g printed

Low Task: Hello
High Task: H,el loI,  I aamm b eibnge pirinntged
printed

Low Task: Hello,
High Task: HIel loa, mI  amb beeiingn pgri ntpedr
inted

Low Task: Hello, I
High Task: Haelmlo , bI eami bneigng  pprirntiedn
ted

Low Task: Hello, I am
High Task: H elbloe, iI namg b eipngr pirinnttede
d

Low Task: Hello, I am b
High Task: Heelilon, gI  amp breiingn ptrientded


Low Task: Hello, I am bei
High Task: Hnelglo , pI rami bneitnge pdri
nted

Low Task: Hello, I am being
High Task: H elplor, iI namt beeidng
 printed

Low Task: Hello, I am being p
High Task: Hrelilon, tI eamd b
eing printed

Low Task: Hello, I am being pri
High Task: Hneltloe, dI
am being printed

Low Task: Hello, I am being print
High Task: Heeldlo
, I am being printed

Low Task: Hello, I am being printed
High Task: H
ello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printed

Low Task: Hello, I am being printed

High Task: Hello, I am being printe
Low Task: Hd
ello, I am being printed

High Task: Hello, I am being pr
Low Task: Hineteld
lo, I am being printed

High Task: Hello, I am bein
Low Task: Hg eprlinlteod
, I am being printed

High Task: Hello, I am
Low Task: Hbeeinlg lproin,te d

 */
