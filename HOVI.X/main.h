/* 
 * File:   mainheader.h
 * Author: Lucas
 *
 * Created on 25. November 2015, 16:56
 */

#ifndef MAIN_H
#define	MAIN_H

#include <stdlib.h>
#include "actors.h"
#include "failure.h"
#include "gear.h"
#include "init.h"
#include "pixy.h"
#include "safety.h"
#include "ultrasonic.h"
   
/*---------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                               */ 
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userrroutines">
interrupt void Fkt_Isr(void);
// </editor-fold>



/*---------------------------------------------------------------------------*/
/* User defined Variables                                                    */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
#define _XTAL_FREQ 16000000
#define GEAR_TIME  6800         /* 1700 µs / 0.25 µs = 6800 pulses on TMR3*/
// </editor-fold>

/*---------------------------------------------------------------------------*/
/* Namedefinitions of Pinouts                                                */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Pinouts">
#define LED PORTBbits.RB2
// </editor-fold>


#endif	/* MAINHEADER_H */

