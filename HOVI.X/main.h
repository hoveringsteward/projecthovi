/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* 
 * In this file is the mainroutine. The routine waits for an
 * interrupt an reacts to it in the interrupt subroutine.
 */

#ifndef MAIN_H
#define	MAIN_H

// <editor-fold defaultstate="collapsed" desc="Included Files">
#include <stdlib.h>
#include "actors.h"
#include "communication.h"
#include "failure.h"
#include "gear.h"
#include "init.h"
#include "pixy.h"
#include "position.h"
#include "safety.h"
#include "ultrasonic.h"
// </editor-fold>


/*------------------------------------------------------------------*/
/* Prototypes of userroutines.                                      */ 
/*------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userrroutines">
interrupt void Isr(void);
// </editor-fold>

/*------------------------------------------------------------------*/
/* User defined Variables                                           */
/*------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
#define _XTAL_FREQ      16000000
#define GEAR_TIME       6800        /* 1700 µs / 0.25 µs = 6800 pulses on TMR3*/
#define DUMMY           0           /* Dummydata for Pixy */
#define PIXY_SYNC       0x5a        /* Syncbyte, dummy data followed */
#define PIXY_SYNC_DATA  0x5b        /* Syncbyte followed by meaningful data */
#define X_MAX           319         /* Maximum X-position */
#define Y_MAX           199         /* Maximum Y-position */
#define WIDTH_MAX       320         /* Maximum size ob obj, (size of screen)*/
#define HEIGHT_MAX      200         /* Maximum size ob obj, (size of screen)*/
#define DES_X_MIN       150         /* Desired minimum X-coordinate of obj */
#define DES_X_MAX       170         /* Desired maximum X-coordinate of obj */
#define X_MID           160         /* Center in X-direction */
#define DES_Y_MIN       90          /* Desired minimum Y-coordinate of obj */
#define Y_MID           100         /* Center in Y-direction */
#define DES_Y_MAX       110         /* Desired maximum Y-coordinate of obj */
#define PIXY_FRAME_OBJ  0xaa55      /* Pixycode for an object */
#define PIXY_COLORCODE  0xaa56      /* Pixycode for a colorcode */
// </editor-fold>

/*------------------------------------------------------------------*/
/* Definitions of Pinouts                                           */
/*------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Pinouts">
#define LED     PORTBbits.RB2
#define A       PORTAbits.RA0
#define E       PORTAbits.RA1
#define T       PORTAbits.RA3
#define R       PORTAbits.RA2
#define Gate    PORTAbits.RA4
#define Trigger PORTBbits.RB3
#define Connect PORTDbits.RD5
// </editor-fold>


/*------------------------------------------------------------------*/
/* Definitions of Pinins                                            */
/*------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Pinins">
#define Connected   PORTDbits.RD4
#define Associated  PORTDbits.RD6
// </editor-fold>


#endif	/* MAINHEADER_H */

