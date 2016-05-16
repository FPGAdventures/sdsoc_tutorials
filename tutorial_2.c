#include "xgpio.h"

#define GPIO_ID XPAR_AXI_GPIO_LED_DEVICE_ID			/* GPIO device that LEDs are connected to */
#define DELAY 50000000								/* Software delay length */
#define CHANNEL 1									/* GPIO port for LEDs */

int main(void) {

	XGpio Gpio;    									/* GPIO Device driver instance */

	int Status = XGpio_Initialize(&Gpio, GPIO_ID); 	/* Initialize GPIO */
	if (Status != XST_SUCCESS) {					/* Error handling */
		  return XST_FAILURE;
	}

	int i,j;

	while(1) {										/* Blink forever */
		for (j = 0; j < 64; j++) {					/* Binary Count with the LEDs */
			XGpio_DiscreteWrite(&Gpio, CHANNEL, (unsigned char) j);	/* Set GPIO Pins */
			for (i=0; i < DELAY; i++);				/* Dealy-Loop */
		}
	}

	return 0;
}
