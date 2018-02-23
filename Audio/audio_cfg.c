#include "audio_cfg.h"

/*
*********************************************************************************************************
*                                    write_audio_cfg_register()
*
* Description : Groups all the writes needed to write to the DE1 SoC WM8731 Audio Codec using
* 				Altera's University IP Audio and Video Config Core.
*
* Arguments   : address       	The 8-bit address of the codec register to which to write
* 				data			The 16-bit data to be written to the register
*
* Returns     : none.
*
* Note(s)     : Consult datasheet for the WM8731 for meaning of each register bit.
*********************************************************************************************************
*/
void write_audio_cfg_register(INT8U address, INT16U data) {

	// indicate to IP core that we are configuring audio device (0x00 correspond to AUDIO_DEVICE)
	alt_write_byte(AUDIOCFG_DEVICE, AUDIO_DEVICE_AUDIO);

	// set the address to which we wish to write
	alt_write_byte(AUDIOCFG_ADDRESS, address);

	// set the data to send
	alt_write_hword(AUDIOCFG_DATA, data);
}
