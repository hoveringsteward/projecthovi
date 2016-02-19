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
    InitComp();
    InitInterrupt();
    InitActors();
#ifdef WLAN
    InitWlan();
#endif
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="PORT">
void InitPort(void) {
    PORTA = 0b00000000;
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
    OSCCON = 0b01110111;    /* 16 MHz, INTOSC, 
                             * stable HFOSC, Internal osc-block */
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="UART">
/* UART is used to communicate with the server over the WLAN module     */
/*  Baudrate 57600                                                      */
/*  Asynchronus mode                                                    */
/*  Trnsmission and reception enabled                                   */
/*  Interrupt on reception enabled                                      */
/*----------------------------------------------------------------------*/
void InitUart(void) {
    //Baudrate
    SPBRG1 = 68;
    TXSTA1bits.BRGH = 1;
    BAUDCON1bits.BRG16 = 1;
    //General
    //Tris already set in InitTris()
    TXSTA1bits.SYNC = 0;
    RCSTA1bits.SPEN = 1;
    //Transmission
    TXSTA1bits.TXEN = 1;
    TX1IF = 0;
    //Reception
    RCSTA1bits.CREN = 1;
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
/* Timer 1, used to measure the time of the outputs                     */
/*  gate control disabled                                               */
/*  FOSC/4                                                              */
/*  Prescaler 1:2                                                       */
/*  Timer disabled                                                      */
/*  1 Impulse: 0.5 µs                                                   */
/* Timer 3, used to measure time of gaer signal                         */
/* Timer 5, used to measure the ultrasonic echo                         */
/*  high active                                                         */
/*  no toggle mode                                                      */
/*  no single pulse mode                                                */
/*  gatepin                                                             */
/*  FOSC/4                                                              */
/*  Prescaler 1:1                                                       */
/*  no sync                                                             */
/*  16-Bit disabled                                                     */
/*  Timer activated                                                     */
/*  1 Impulse: 0.25 µs                                                  */
/*----------------------------------------------------------------------*/
void InitTimer(void) {
    // <editor-fold defaultstate="collapsed" desc="TMR1">
    T1CONbits.TMR1CS = 0b00;
    T1CONbits.T1CKPS = 0b01;
    T1CONbits.nT1SYNC = 1;
    T1CONbits.TMR1ON = 0;
    TMR1H = 0;
    TMR1L = 0;
    // </editor-fold>
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

// <editor-fold defaultstate="collapsed" desc="Comparator">
/* CCP1 used to stop time counted by timer 1                            */
/*  Interrupt on match                                                  */
/*  Output disabled                                                     */
/*----------------------------------------------------------------------*/
void InitComp(void) {
    CCP1CONbits.CCP1M = 0b1010;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Interrupt">
/* Interrupts from:                                                     */
/*  Timer 3 Gate                                                        */
/*  Compareunit 1                                                       */
/*----------------------------------------------------------------------*/
void InitInterrupt(void) {
    /* Enabling interrupt for Timer 3 gate                              */
    TMR3GIE = 1;
    TMR3IF = 0;
    /* Enabling interrupt for Compareunit 1                             */
    CCP1IE = 1;
    CCP1IF = 0;
    /* Enabling interrupts in general                                   */
    PEIE = 1;
    GIE = 1;
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

// <editor-fold defaultstate="collapsed" desc="WLAN">
void InitWlan(void) {
    while(Associated == 0);
    Connect = 1;
    __delay_ms(30);
    while(Connected == 0);
}
// </editor-fold>


// </editor-fold>
