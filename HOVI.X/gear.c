/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext für eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses benötigt wird.             */

#include <xc.h>
#include "gear.h"

/* Returns by TMR3 measured time                                             */
/*---------------------------------------------------------------------------*/
unsigned int CalcTime(void) {
    unsigned int time_pulse = TMR3H;
    time_pulse <<= 8;
    time_pulse |= TMR3L;
    TMR3H = 0;
    TMR3L = 0;
    NOP();
    return time_pulse;
}

/* Calls Fkt_CalcTime to get count of TMR3                                   */
/* Compares value of TMR3 with GEAR_TIME to select the mode to use           */
/*      returns 0 for manual mode, gearswitch position 1 or 2                */
/*      returns 1 for automatic mode, gearswitch position 0                  */
bit ModeCheck(void) {
    unsigned int time = CalcTime();
    if(time < GEAR_TIME){
        LED = 0;
        return 0;
    }else if(time >= GEAR_TIME) {
        LED = 1;
        return 1;
    }
    NOP();
}
