#include "audio.h"

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

/*
 *********************************************************************************************************
 *                                    write_audio_data()
 *
 * Description : Writes audio data to both channels on the Altera University IP core from a buffer
 *
 * Arguments   : buffer	       	A buffer allocated to hold the audio data
 * 				len				The number of samples to be read
 *
 * Returns     : The number of audio samples read into the buffer
 *
 *********************************************************************************************************
 */
INT32U write_audio_data(INT32S * buffer, INT32U len) {

	INT32U fifospace;
	INT32U count = 0;
	INT8U num_words_left, num_words_right;

	while (count < len)
	{
		// determine the number of available space for words in the channel
		fifospace = alt_read_word(AUDIO_BASE + AUDIO_FIFOSPACE_OFFSET);
		num_words_left = (fifospace & AUDIO_FIFOSPACE_WSLC_MASK) >> AUDIO_FIFOSPACE_WSLC_BIT_OFFSET;
		num_words_right = (fifospace & AUDIO_FIFOSPACE_WSRC_MASK) >> AUDIO_FIFOSPACE_WSRC_BIT_OFFSET;

		// write word if available space
		if (num_words_left > 0 && num_words_right > 0)
		{
			alt_write_word(AUDIO_BASE + AUDIO_LEFTDATA_OFFSET, buffer[count]);
			alt_write_word(AUDIO_BASE + AUDIO_RIGHTDATA_OFFSET, buffer[count]);

			count = count + 1;
		}
	}

	return count;

}
