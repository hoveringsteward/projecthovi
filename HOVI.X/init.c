/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* This file contains all necessary initialisations.
 * The following Modules are initialised:
 *      Pins (Port, Tris, Ansel)
 *      Oscillator
 *      EUSART1
 *      SPI1
 *      Timer 1,3,5
 *      Interrupts
 *      Actors with default values
 */

#include <xc.h>
#include "main.h"


/*----------------------------------------------------------------------*/
/* Beginning of userroutines.                                           */
/*----------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Initfunctions">

// <editor-fold defaultstate="collapsed" desc="Init">
/* Calls all needed inits                                                    */
/*---------------------------------------------------------------------------*/
void Init(void) {
    InitPort();
    InitTris();
    InitAnsel();
    InitOsc();
    InitUart();
    InitSpi();
    InitTimer();
    InitInterrupt();
    InitActors();
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="PORT">
void InitPort(void) {
    PORTA = 0b00010000;
    PORTB = 0b00001000;
    PORTC = 0b00000000;
    PORTD = 0b00001000;
    PORTE = 0b00000000;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="TRIS">
void InitTris(void) {
    TRISA = 0b00000000;
    TRISB = 0b00010000;
    TRISC = 0b10010001;
    TRISD = 0b01010000;
    TRISE = 0b00000000;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="ANSEL">
void InitAnsel(void) {
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    ANSELC = 0b00000000;
    ANSELD = 0b00000000;
    ANSELE = 0b00000000;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="OSC">
void InitOsc(void) {
    OSCCON = 0b01110111;    // 16MHz, INTOSC, stable HFOSC, Internal osc-block
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="UART">
void InitUart(void) {
    
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="SPI">
/* SPI1 used to communicate with PIXY and possible othe periperals      */
/*  Samlpled at middle of data outpu                                    */
/*  Transmit on idle to active                                          */
/*  SPI1 enabled                                                        */
/*  Idle low                                                            */
/*  Master mode, clock FOSC/16                                          */
/*----------------------------------------------------------------------*/
void InitSpi(void) {
    SSP1STAT = 0b00000000;      //Rising edge;
    SSP1CON1 = 0b00100001;      //FOSC/16
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Timer">
/* Timer 3, used to measure time of gaer signal                         */
/* Timer 5, used to measure the ultrasonic echo                         */
/*  high active                                                         */
/*  no toggle mode                                                      */
/*  no single pulse mode                                                */
/*  gatepin                                                             */
/*  FOSC/4                                                              */
/*  Prescale 1:1                                                        */
/*  no sync                                                             */
/*  16-Bit disabled                                                      */
/*----------------------------------------------------------------------*/
void InitTimer(void) {
    // <editor-fold defaultstate="collapsed" desc="TMR3">
    //Timer 3 Gatecontrolregister
    T3GCONbits.TMR3GE = 1;
    T3GCONbits.T3GSPM = 0;
    T3GCONbits.T3GTM =  0;
    T3GCONbits.T3GPOL = 1;
    T3GCONbits.T3GSS =  0b00;
    //Timer 3 Controlregister
    T3CONbits.TMR3CS =  0b00;
    T3CONbits.T3CKPS =  0b00;
    T3CONbits.nT3SYNC = 1;
    T3CONbits.TMR3ON =  1;
    // </editor-fold>
    // <editor-fold defaultstate="collapsed" desc="TMR5">
    //Timer 5 Gatecontrolregister
    T5GCONbits.TMR5GE = 1;
    T5GCONbits.T5GSPM = 0;
    T5GCONbits.T5GTM =  0;
    T5GCONbits.T5GPOL = 1;
    T5GCONbits.T5GSS =  0b00;
    //Timer 5 Controlregister
    T5CONbits.TMR5CS =  0b00;
    T5CONbits.T5CKPS =  0b00;
    T5CONbits.nT5SYNC = 1;
    T5CONbits.TMR5ON =  1;
    // </editor-fold>
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Interrupt">
/* Interrupts from:                                                      */
/*  Timer 3 Gate                                                         */
/*-----------------------------------------------------------------------*/
void InitInterrupt(void) {
    GIE = 1;
    PEIE = 1;
    /* Enabling interrupt for Timer 3 gate                              */
    TMR3GIE = 1;        // Direct access due to conflicts with PIE3bits.TMR3GIE    
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Actors">
/* Setting the default point of the actors                              */
/* Actors are on default state -> no motion will occoure                */
void InitActors (void) {
    a_actors[0].aile = 500;
    a_actors[0].elev = 500;
    a_actors[0].thro = 0;
    a_actors[0].rudd = 500;
}
// </editor-fold>

// </editor-fold>
