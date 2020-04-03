/*
 * adc_controller.h
 *
 *  Created on: Apr 3, 2020
 *  Author: Danny McCardle, Tayler Harvey
 */

#ifndef SOURCES_ADC_CONTROLLER_H_
#define SOURCES_ADC_CONTROLLER_H_

/**
 * Enable ADC0 with header pin ADC0_DP1
 */
void initializeADC();

/**
 * Enable the microphone to start listening for
 * sound.
 */
void turnOnMic();

/**
 * Disable the microphone listening.
 */
void turnOffMic();

/**
 * Get the current sound reading of the microphone
 *
 * return: the volume level
 */
int getMicInput();

#endif /* SOURCES_ADC_CONTROLLER_H_ */
