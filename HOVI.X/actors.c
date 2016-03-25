/*-----------------------------------------------------------------*/
/* Author: Chrisy                                                  */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Actors are components like propellers
 * they have to act, after they get the information from sensors
 * (position.c)
 */


#include <xc.h>
#include "main.h"

void Delay(unsigned int del) {
    del <<= 1;      // x2, 1 times del equals 0.5 µs
    del = 2000 + del;
    TMR1L = 0;
    TMR1H = 0;
    CCPR1L = del;   // writing lower 8 bits to CCPR1 register
    del >>= 8;
    CCPR1H = del;   // writing upper 8 bits to CCPR1 register
    T1CONbits.TMR1ON = 1;
}

// <editor-fold defaultstate="collapsed" desc="Signal Out">
void SignalOut(void) {
    switch(pin_out) {
        case 'A': {
            A = 1;
            Delay(a_actors[0].aile);
            pin_out = 'E';
            break;
        }case 'E': {
            A = 0;
            E = 1;
            Delay(a_actors[0].elev);
            pin_out = 'T';
            break;
        }case 'T': {
            E = 0;
            T = 1;
            Delay(a_actors[0].thro);
            pin_out = 'R';
            break;
        }case 'R': {
            T = 0;
            R = 1;
            Delay(a_actors[0].rudd);
            pin_out = 0;
            break;
        }case 0: {
            R = 0;
            pin_out = 'A';
            break;
        }
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Act Ailerons">
/* ActAilerons                                                      */
/* roll = rollen -> left & right                                   */
/*------------------------------------------------------------------*/
void ActAileron(signed char change){
    a_actors[0].aile += change;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Act Elevator">
/* ActElevator                                                      */
/* pitch = nicken -> front & back                                    */
/*------------------------------------------------------------------*/
void ActElevator(signed char change){
    a_actors[0].elev += change;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Act Throttle">
/* ActThrottle                                                      */
/* Height                                                           */
/*------------------------------------------------------------------*/
void ActThrottle(signed char change) {
    if(a_actors[0].thro <= 550 || change < 0) {
        a_actors[0].thro += change;
        if(a_actors[0].thro > 1050) {
            a_actors[0].thro = 0;
        }
    }else {
        NOP();
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Act Rudder">
/* ActRudder                                                        */
/* Yaw - Rotation on it's own high-axis                        */
/*------------------------------------------------------------------*/
void ActRudder(signed char change){
    a_actors[0].rudd += change;
}
// </editor-fold>
