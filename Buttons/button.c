#include "button.h"

/*
*********************************************************************************************************
*
*                                         PERIPHERAL BUTTON / KEY DRIVER CODE
*
*                                            CYCLONE V SOC
*
* Filename      : button.c
* Version       : V1.00
* Programmer(s) : Adam Narten (anarten@ualberta.ca)
*
*********************************************************************************************************
* Note(s)       : This is a sparse driver for Peripheral Buttons/Keys on the DE1-SoC board
* 				  It assumes that the core is acting as a slave to the Cyclone V's HPS, connected via the
* 				  lightweight bridge.
*
*********************************************************************************************************
*/

long _ButtonReleases;

bool key_pressed() {
	_ButtonReleases = alt_read_word(BUTTON_BASE);
    alt_write_word(LEDR_BASE, _ButtonReleases);
	if (_ButtonReleases != 0xf) {
		OSTimeDlyHMSM(0,0,0,200); // Delay, so that we can observe the change on the LEDs (feel free to change to preference)
		return true;
	} else {
		return false;
	}
}

bool key_0_pressed() {
	if ((_ButtonReleases & KEY_0_MASK) != KEY_0_MASK) {
		return true;
	} else {
		return false;
	}
}

bool key_1_pressed() {
	if ((_ButtonReleases & KEY_1_MASK) != KEY_1_MASK) {
		return true;
	} else {
		return false;
	}
}

bool key_2_pressed() {
	if ((_ButtonReleases & KEY_2_MASK) != KEY_2_MASK) {
		return true;
	} else {
		return false;
	}
}

bool key_3_pressed() {
	if ((_ButtonReleases & KEY_3_MASK) != KEY_3_MASK) {
		return true;
	} else {
		return false;
	}
}
