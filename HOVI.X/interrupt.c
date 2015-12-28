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

#include <xc.h>
#include "main.h"

interrupt void Fkt_Isr() {
    NOP();
    if(TMR3GIF == 1) {
        TMR3GIF = 0;
        Fkt_ModeCheck();
    }else if (TMR3IF == 1) {
        TMR3IF = 0;
        NOP();
        NOP();
    }
}