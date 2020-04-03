/*
 * clock_controller.h
 *
 *  Created on: Apr 3, 2020
 *      Author: danny
 */

#ifndef SOURCES_CLOCK_CONTROLLER_H_
#define SOURCES_CLOCK_CONTROLLER_H_

/**
 * Initialize the RTC Module
 */
void initializeRTC();

/**
 * Wait <startTime> amount of seconds. Essentially
 * acts as a "sleep" function.
 *
 * Inputs:
 * startTime: the number of seconds to wait
 */
void waitUntilStartTime(int startTime);

/**
 * Introduce a one second pause.
 */
void waitOneSecond();


#endif /* SOURCES_CLOCK_CONTROLLER_H_ */
