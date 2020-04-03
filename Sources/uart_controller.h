/*
 * uart_controller.h
 *
 *  Created on: Apr 3, 2020
 *  Author: Danny McCardle, Tayler Harvey
 */

#ifndef SOURCES_UART_CONTROLLER_H_
#define SOURCES_UART_CONTROLLER_H_


/**
 * Enable UART0 with PortB: Pins 16+17
 */
void initializeUART();

/**
 * Displays the welcome message to the user on a
 * PuTTY terminal. The welcome message prompts the
 * user for the number of hours until the alarm
 * should be played.
 */
void displayWelcomeMessage();

/**
 * Take in input from the user from the PuTTY
 * terminal. Input is a number of hours.
 *
 * return value: amount of time in seconds
 */
int getAlarmTimeFromUser();

#endif /* SOURCES_UART_CONTROLLER_H_ */
