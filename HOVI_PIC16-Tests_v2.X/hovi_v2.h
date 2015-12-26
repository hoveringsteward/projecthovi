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
#include "hovi_LED_v2.h"


/*---------------------------------------------------------------------------*/
/* User defined Variables                                                    */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
/*Constants                                                                  */
/*---------------------------------------------------------------------------*/
#define _XTAL_FREQ      4000000
#define DUMMY           0
#define PIXY_SYNC       0x5a
#define PIXY_SYNC_DATA  0x5b
#define X_MAX           319
#define Y_MAX           199
#define WIDTH_MAX       320
#define HEIGHT_MAX      200
#define PIXY_FRAME_OBJ  0xaa55
#define PIXY_COLORCODE  0xaa56


unsigned char frame;
unsigned int w = 0, lw = 0;
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

