/*-----------------------------------------------------------------*/
/* Author: Lucas                                                  */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/* summary: check, ignore and smooth
/* after getting data from the sensor(s), the programm has
/* to check if the value has no special characters and is 
/* incorrect measurement (= irgendwelche Sonderzeichen oder 
/* Fehler, die nicht aus Zahlen bestehen)
/* The second assignment is, to ignore runaways (Ausreiﬂer entfernen)
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
    while(TMR5GIF == 0);
    TMR5GIF = 0;
    time_height = 0;
    time_height = TMR5H;
    time_height <<= 8;
    time_height |= TMR5L;
    TMR5L = 0;
    TMR5H = 0;
    a_frame[0].height = time_height;
#ifdef DEBUG
    SendDebugInfo(time_height);
#endif
    a_frame_dif[0].dif_height = a_frame[1].height - a_frame[0].height;
    Trigger = 1;
}

// <editor-fold defaultstate="collapsed" desc="not used: Filter">
/* 
/*------------------------------------------------------------*/
unsigned int Filter(unsigned int entry){
    changerate = 0.2;
    if(highpassallowed){
        // i don't know
    }else{
        outgoing = outgoing + (entry - outgoing) * changerate;
    }
    return (int) outgoing;  
}
// </editor-fold>

