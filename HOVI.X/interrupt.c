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
 * The function declared hear should only do the first steps of the
 * reaction to the interrupt. The major part of it should happen
 * in an extra function.
 */

#include <xc.h>
#include "main.h"

interrupt void Isr() {
    if(TMR3GIF == 1) {
        TMR3GIF = 0;
        time_gear = TMR3H;
        time_gear <<= 8;
        time_gear = TMR3L;
        TMR3H = 0;
        TMR3L = 0;
        // Funktion für Ausgabe von Steuersignalen fehlt
        SignalOut();
        
    }
}
