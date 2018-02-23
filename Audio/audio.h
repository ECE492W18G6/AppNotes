/*
*********************************************************************************************************
*
*                                          AUDIO DRIVER CODE
*
*                                            CYCLONE V SOC
*
* Filename      : audio.h
* Version       : V1.00
* Programmer(s) : Michael Wong (mcwong2@ualberta.ca), Adam Narten (anarten@ualberta.ca)
*
*********************************************************************************************************
* Note(s)       : This is a sparse driver for the Altera University IP "Audio" core,
* 				  for use with the DE1-SoC.  This driver only provides functionality to write to the buffer
* 				  and does not allow for any input reading.
* 				  It assumes that the core is acting as a slave to the Cyclone V's HPS, connected via the
* 				  lightweight bridge.
*
*********************************************************************************************************
*/

#include <hps.h>
#include <os_cpu.h>
#include <socal.h>

#define FPGA_TO_HPS_LW_ADDR(base)  ((void *) (((char *)  (ALT_LWFPGASLVS_ADDR))+ (base)))

// NB: Set base address of Audio core here, according to QSYS system configuration
#define AUDIO_ADDR 0x00000400
#define AUDIO_BASE FPGA_TO_HPS_LW_ADDR(AUDIO_ADDR)

#define LEFT_CHANNEL 0
#define RIGHT_CHANNEL 1

#define AUDIO_CONTROL_OFFSET 0
#define AUDIO_CONTROL_RE_MASK 0x00000001
#define AUDIO_CONTROL_WE_MASK 0x00000002
#define AUDIO_CONTROL_CR_MASK 0x00000004
#define AUDIO_CONTROL_CW_MASK 0x00000008
#define AUDIO_CONTROL_RI_MASK 0x00000100
#define AUDIO_CONTROL_WI_MASK 0x00000200

#define AUDIO_FIFOSPACE_OFFSET 4
#define AUDIO_FIFOSPACE_WSLC_MASK 0xFF000000
#define AUDIO_FIFOSPACE_WSRC_MASK 0x00FF0000
#define AUDIO_FIFOSPACE_RALC_MASK 0x0000FF00
#define AUDIO_FIFOSPACE_RARC_MASK 0x000000FF
#define AUDIO_FIFOSPACE_WSLC_BIT_OFFSET 24
#define AUDIO_FIFOSPACE_WSRC_BIT_OFFSET 16
#define AUDIO_FIFOSPACE_RALC_BIT_OFFSET 8
#define AUDIO_FIFOSPACE_RARC_BIT_OFFSET 0

#define AUDIO_LEFTDATA_OFFSET 8
#define AUDIO_RIGHTDATA_OFFSET 12

INT32U write_audio_data(INT32S * buffer, INT32U len);

