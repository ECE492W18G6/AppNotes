/*
*********************************************************************************************************
*
*                                          AUDIO_CFG DRIVER CODE
*
*                                            CYCLONE V SOC
*
* Filename      : audio_cfg.h
* Version       : V1.00
* Programmer(s) : Michael Wong (mcwong2@ualberta.ca)
*
*********************************************************************************************************
* Note(s)       : This is a sparse driver for the Altera University IP "Audio and Video Config" core,
* 				  for use with the DE1-SoC.  This driver was written for ECE 492, and assumes that the
* 				  core is acting as a slave to the Cyclone V's HPS, connected via the lightweight bridge.
*
*********************************************************************************************************
*/

#include <hps.h>
#include <os_cpu.h>
#include <socal.h>

#define FPGA_TO_HPS_LW_ADDR(base)  ((void *) (((char *)  (ALT_LWFPGASLVS_ADDR))+ (base)))

// NB: Set base address of Audio and Video Config core here, according to QSYS system configuration
#define AUDIOCFG_ADDR 0x00000500
#define AUDIOCFG_BASE (ALT_LWFPGASLVS_ADDR + AUDIOCFG_ADDR)

#define AUDIOCFG_CONTROL (AUDIOCFG_BASE)
#define AUDIOCFG_DEVICE (AUDIOCFG_BASE + 0x2)
#define AUDIOCFG_STATUS (AUDIOCFG_BASE + 0x4)
#define AUDIOCFG_CFG (AUDIOCFG_BASE + 0x6)
#define AUDIOCFG_ADDRESS (AUDIOCFG_BASE + 0x8)
#define AUDIOCFG_DATA (AUDIOCFG_BASE + 0xC)

#define AUDIO_DEVICE_AUDIO 0x00

void write_audio_cfg_register(INT8U address, INT16U data);
