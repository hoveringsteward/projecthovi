/* 
 * File:   hovi.h
 * Author: Lucas
 *
 * Created on 7. November 2015, 14:27
 */

#ifndef HOVI_V2_H
#define	HOVI_V2_H

#include <xc.h>

//own header files
#include "hovi_SPI_v2.h"
#include "hovi_UART_v2.h"
#include "hovi_LED_v2.h"
#include "hovi_Pixy_v2.h"


/*---------------------------------------------------------------------------*/
/* User defined Variables                                                    */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
/*Constants                                                                  */
/*---------------------------------------------------------------------------*/
#define _XTAL_FREQ      4000000
#define DUMMY           0
#define PIXY_SYNC       0x5A
#define PIXY_SYNC_DATA  0x5B
#define X_MAX           319
#define Y_MAX           199
#define WIDTH_MAX       320
#define HEIGHT_MAX      200
#define PIXY_FRAME_OBJ  0xAA55
#define PIXY_COLOURCODE 0xAA56


unsigned char frame;

/*Global variables                                                           */
/*---------------------------------------------------------------------------*/

// </editor-fold>

/*---------------------------------------------------------------------------*/
/* Namedefinitions of Pinouts                                                */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Pinouts">
#define LEDup       RA2
#define LEDdown     RA3
#define LEDleft     RA4
#define LEDright    RA7
// </editor-fold>

#endif	/* HOVI_H */

