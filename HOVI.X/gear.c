#include <xc.h>
#include "gear.h"

/* Returns by TMR3 measured time                                             */
/*---------------------------------------------------------------------------*/
unsigned int Fkt_CalcTime(void) {
    unsigned int time_pulse = TMR3H;
    time_pulse <<= 8;
    time_pulse |= TMR3L;
    TMR3H, TMR3L = 0;
    return time_pulse;
}


/* Calls Fkt_CalcTime to get count of TMR3                                   */
/* Compares value of TMR3 with GEAR_TIME to select the mode to use           */
/*      returns 0 for manual mode, gearswitch position 1 or 2                */
/*      returns 1 for automatic mode, gearswitch position 0                  */
bit Fkt_ModeCheck(void) {
    unsigned int time = Fkt_CalcTime();
    if(time < GEAR_TIME){
        return 0;
    }else {
        return 1;
    }
}

