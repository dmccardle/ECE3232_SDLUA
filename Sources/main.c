/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// Authors: Danny McCardle, Tayler Harvey

#include "fsl_device_registers.h"
#include "MK64F12.h"

#define GREEN "green"
#define RED "red"
#define MAX_THRESHOLD 10

int alarmTime;
int currentTime;
int startTime;

// Enable Port B pins 3,10,11 for output
void initializeGPIO_LEDs() {

}

// Enable Port B pin 22 for output, and Port E pin 26 for output
void initializeGPIO_RGBLED() {

}

// Enable Port C pin 6 for input
void initializeGPIO_PushButton() {

}

// Enable multiple ports + pins
void initializeGPIO() {
	initializeGPIO_LEDs();
	initializeGPIO_RGBLED();
	initializeGPIO_PushButton();
}

// Enable UART0 with PortB: Pins 16+17
void initializeUART() {

}

// Enable DAC0 with header pin DAC0_OUT
void initializeDAC() {

}

// Enable ADC0 with header pin ADC0_DP1
void initializeADC() {

}

void initializeFlexTimer() {

}

void initializeModules() {
	initializeGPIO();
	initializeUART();
	initializeDAC();
	initializeADC();
	initializeFlexTimer();
}

void playAlarm() {
	// turn on all LEDs
	turnOnFirstLED();
	turnOnSecondLED();
	turnOnThirdLED();

	// starts playing alarm sound through the speaker
	turnOnSpeaker();

	// turn alarm off
	waitForButtonPress();
}

void startAlarmSequence() {
	turnOnFirstLED();
	turnOnMic();

	int soundInput;

	while(currentTime < startTime + 10) {
		soundInput = getMicInput();
		if (soundInput < MAX_THRESHOLD) {
			// set the currentTime so the alarm will play
			currentTime = alarmTime;
		}
		waitOneSecond();
		currentTime++;
	}

	turnOnSecondLED();

	while(currentTime < startTime + 20) {
		soundInput = getMicInput();
		if (soundInput < MAX_THRESHOLD) {
			// set the currentTime so the alarm will play
			currentTime = alarmTime;
		}
		waitOneSecond();
		currentTime++;
	}

	turnOnThirdLED();

	while (currentTime < alarmTime) {
		soundInput = getMicInput();
		if (soundInput < MAX_THRESHOLD) {
			// set the currentTime so the alarm will play
			currentTime = alarmTime;
		}
		waitOneSecond();
		currentTime++;
	}

	playAlarm();
}

void stopAlarmSequence() {
	turnOffSpeaker();
	turnOffAllLEDs();
	turnOffMic();
	setRGBColour(GREEN);
	startTime = currentTime = alarmTime = 0;
}

int main(void) {
	initializeModules();
	// repeat loop forever
	while(1) {
		setRGBColour(GREEN); // update status light

		displayWelcomeMessage();

		alarmTime = getAlarmTimeFromUser();
		startTime = calculateStartTime(alarmTime)

		waitForButtonPress(); // turn alarm on
		setRGBColour(RED); // update status light

		waitUntilStartTime(startTime);

		startAlarmSequence();
		stopAlarmSequence();
    }
}
