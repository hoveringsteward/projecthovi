/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext für eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses benötigt wird.             */

#ifndef MAIN_H
#define	MAIN_H

// <editor-fold defaultstate="collapsed" desc="Included Files">
#include <stdlib.h>
#include "actors.h"
#include "failure.h"
#include "gear.h"
#include "init.h"
#include "pixy.h"
#include "safety.h"
#include "ultrasonic.h"
#include "communication.h"
// </editor-fold>

   
/*---------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                               */ 
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userrroutines">
interrupt void Isr(void);
// </editor-fold>



/*---------------------------------------------------------------------------*/
/* User defined Variables                                                    */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
#define _XTAL_FREQ      16000000
#define GEAR_TIME       6800        /* 1700 µs / 0.25 µs = 6800 pulses on TMR3*/
#define DUMMY           0
#define PIXY_SYNC       0x5a
#define PIXY_SYNC_DATA  0x5b
#define X_MAX           319
#define Y_MAX           199
#define WIDTH_MAX       320
#define HEIGHT_MAX      200
#define PIXY_FRAME_OBJ  0xaa55
#define PIXY_COLORCODE  0xaa56
// </editor-fold>

/*---------------------------------------------------------------------------*/
/* Definitions of Pinouts                                                */
/*---------------------------------------------------------------------------*/
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


/*---------------------------------------------------------------------------*/
/* Definitions of Pinins                                                 */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Pinins">
#define Connected   PORTDbits.RD4
#define Associated  PORTDbits.RD6
// </editor-fold>


#endif	/* MAINHEADER_H */

