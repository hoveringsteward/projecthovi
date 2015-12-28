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
 * The function declared hear should only do the first steps of the
 * reaction to the interrupt. The major part of it should happen
 * in an extra function.
 */

#include <xc.h>
#include "main.h"

interrupt void Isr() {
    NOP();
    if(TMR3GIF == 1) {
        TMR3GIF = 0;
        ModeCheck();
    }else if (TMR3IF == 1) {
        TMR3IF = 0;
    }
}