/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext für eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses benötigt wird.             */

/* Headerfile is main.h due to the single subroutine */

/*-----------------------------------------------------------------*/
/* Author: Lucas                                                  */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* The function declared in this file reacts to the occouring
 * interrupts. For an interrupt the peripheral interrupt must be
 * enabled.
 * The function declared here should only do the first steps of the
 * reaction to the interrupt. The major part of it should happen
 * in an extra function.
 */

#include <xc.h>
#include "main.h"

interrupt void Isr() {
    if(CCP1IF == 1) {
        CCP1IF = 0;
        T1CONbits.TMR1ON = 0;
        SignalOut();
        NOP();
        NOP();
    }
    if(TMR3GIF == 1) {
        TMR3GIF = 0;
        time_gear = 0;
        time_gear = TMR3H;
        time_gear <<= 8;
        time_gear |= TMR3L;
        NOP();
        NOP();
        TMR3H = 0;
        TMR3L = 0;
        ModeCheck();
        SignalOut();    /* initial call after remaining break to 20 ms
                         * starts with Aileron (needs to be set in last
                         * case statement, case 0) following delays will
                         * be processed by the previous routine */
        pulsecounter++;
    }
}
