/* Headerfile is main.h due to the single subroutine */

#include <xc.h>
#include "main.h"

interrupt void Fkt_Isr(void) {
    if(TMR3GIF == 1) {
        Fkt_ModeCheck();
    }
}