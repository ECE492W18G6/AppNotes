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
#include <hps.h>
#include <os_cpu.h>
#include <socal.h>
#include <os.h>

#define FPGA_TO_HPS_LW_ADDR(base)  ((void *) (((char *)  (ALT_LWFPGASLVS_ADDR))+ (base)))

// NB: Set base address of PIO corresponding to the buttons here, according to QSYS system configuration
#define BUTTON_ADD 0x00000200
#define BUTTON_BASE FPGA_TO_HPS_LW_ADDR(BUTTON_ADD)
// NB: Set base address of PIO corresponding to the Red LEDs here, according to QSYS system configuration
#define LEDR_ADD 0x00000000
#define LEDR_BASE FPGA_TO_HPS_LW_ADDR(LEDR_ADD)

#define KEY_0_MASK 1
#define KEY_1_MASK 2
#define KEY_2_MASK 4
#define KEY_3_MASK 8

bool key_pressed(void);
bool key_0_pressed(void);
bool key_1_pressed(void);
bool key_2_pressed(void);
bool key_3_pressed(void);
