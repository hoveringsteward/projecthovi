/* Headerfile is main.h due to the single subroutine */

#include <xc.h>
#include "main.h"

interrupt void Fkt_Isr() {
    if(TMR3GIF == 1) {
        TMR3GIF = 0;
        Fkt_ModeCheck();
    }
}