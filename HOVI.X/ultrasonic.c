/*-----------------------------------------------------------------*/
/* Author: Lucas                                                  */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* This file is for the ultrasonic sensor(s)                       */
/*                                                                 
/* -> da darf dein Text noch rein :b
 * Something with measurements :D
 * 
 * summary: check, ignore and smooth
/* after getting data from the sensor(s), the programm has
/* to check if the value has no special characters and is 
/* incorrect measurement (= irgendwelche Sonderzeichen oder 
/* Fehler, die nicht aus Zahlen bestehen)
/* The second assignment is, to ignore runaways (Ausrei�er entfernen)
/* and the third is, to smooth the measurements               
 * 
 * The increase / velocity will be calculated in this file as well
 */

#include <xc.h>
#include "main.h"


void StartHeightMeasure(void) {
    TMR5L = 0;
    TMR5H = 0;
    Trigger = 0;
}

void ReadHeight(void) {
    while(TMR5IF == 0);
    TMR5IF = 0;
    time_height = TMR5H;
    time_height <<= 8;
    time_height |= TMR5L;
    a_frame[0].height = time_height;
}

// <editor-fold defaultstate="collapsed" desc="not used: Filter">
/* 
/*------------------------------------------------------------*/
unsigned int Filter(unsigned int entry){
    
    float outgoing;
    float changerate = 0.2; // 20 percent
    bit highpassallowed = 1; // should be used in position.c -> check throttle
    
    if(highpassallowed){
        // i don't know
    }else{
        outgoing = outgoing + (entry - outgoing) * changerate;
    }
    return (int) outgoing;  
}
// </editor-fold>

