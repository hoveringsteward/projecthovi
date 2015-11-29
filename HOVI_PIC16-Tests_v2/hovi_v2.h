/* 
 * File:   hovi.h
 * Author: Lucas
 *
 * Created on 7. November 2015, 14:27
 */

#ifndef HOVI_H
#define	HOVI_H

#include <xc.h>

//eigene Header files
#include "hovi_SPI_v2.h"
#include "hovi_UART_v2.h"
#include "hovi_LED_v2.h"


#define DUMMY 0
#define PIXY_SYNC 0x5A
#define PIXY_SYNC_DATA 0x5B
#define X_MAX 319
#define Y_MAX 199
#define WIDTH_MAX 320
#define HEIGHT_MAX 200

#define LEDup
#define LEDdown
#define LEDleft
#define LEDright



#endif	/* HOVI_H */

