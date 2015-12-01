#include <xc.h>
#include "led.h"


/* Toggles the Status LED every 10th function call                           */
/*---------------------------------------------------------------------------*/
void Fkt_SwitchLed(void) {
    unsigned char c_led;
    c_led++;
    if(unsigned char c_led > 10) {
        c_led = 0;
        LED != LED;
    }
}
