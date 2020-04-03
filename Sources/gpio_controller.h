/*
 * gpio_controller.h
 *
 *  Created on: Apr 3, 2020
 *  Author: Danny McCardle, Tayler Harvey
 */

#ifndef SOURCES_GPIO_CONTROLLER_H_
#define SOURCES_GPIO_CONTROLLER_H_

/**
 * Enable all of the required ports & pins for:
 * Yellow LEDs
 * RGB LED
 * Push Button
 */
void initializeGPIO();

// Enable Port B pins 3,10,11 for output
void initializeGPIO_LEDs();

// Enable Port B pin 22 for output, and Port E pin 26 for output
void initializeGPIO_RGBLED();

// Enable Port C pin 6 for input
void initializeGPIO_PushButton();

/**
 * Set the colour of the RGB LED based on the
 * input colour provided.
 *
 * char* colour: "red" or "green"
 */
void setRGBColour(char* colour);

/**
 * Wait for one whole press-release cycle of
 * the push button.
 */
void waitForButtonPress();

/**
 * Turn on the output for the first Yellow LED
 */
void turnOnFirstLED();

/**
 * Turn on the output for the second Yellow LED
 */
void turnOnSecondLED();

/**
 * Turn on the output for the third Yellow LED
 */
void turnOnThirdLED();

/**
 * Turn off all of the Yellow LEDs
 */
void turnOffAllLEDs();


#endif /* SOURCES_GPIO_CONTROLLER_H_ */
