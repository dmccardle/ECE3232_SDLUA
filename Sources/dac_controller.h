/*
 * dac_controller.h
 *
 *  Created on: Apr 3, 2020
 *  Author: Danny McCardle, Tayler Harvey
 */

#ifndef SOURCES_DAC_CONTROLLER_H_
#define SOURCES_DAC_CONTROLLER_H_

/**
 * Enable DAC0 with header pin DAC0_OUT
 */
void initializeDAC();

/**
 * Start outputting the alarm sound through
 * the speaker.
 */
void turnOnSpeaker();


/**
 * Stop outputting the alarm sound through
 * the speaker.
 */
void turnOffSpeaker();

#endif /* SOURCES_DAC_CONTROLLER_H_ */
