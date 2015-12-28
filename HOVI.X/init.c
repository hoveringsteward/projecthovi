/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext f�r eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses ben�tigt wird.             */

#include <xc.h>
#include "init.h"


/*---------------------------------------------------------------------------*/
/* Beginning of userroutines.                                                   */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Initfunctions">

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
}

void InitPort(void) {
    PORTA = 0b00010000;
    PORTB = 0b00001000;
    PORTC = 0b00000000;
    PORTD = 0b00001000;
    PORTE = 0b00000000;
}

void InitTris(void) {
    TRISA = 0b00000000;
    TRISB = 0b00010000;
    TRISC = 0b10010001;
    TRISD = 0b01010000;
    TRISE = 0b00000000;
}

void InitAnsel(void) {
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    ANSELC = 0b00000000;
    ANSELD = 0b00000000;
    ANSELE = 0b00000000;
}

void InitOsc(void) {
    OSCCON = 0b01110111;    // 16MHz, INTOSC, stable HFOSC, Internal osc-block
}

void InitUart(void) {
    
}

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

/* Timer 3, used to measure time of gaer signal                          */
/*  high active                                                          */
/*  no toggle mode                                                       */
/*  no single pulse mode                                                 */
/*  gatepin                                                              */
/*  FOSC/4                                                               */
/*  Prescale 1:1                                                         */
/*  no sync                                                              */
/*-----------------------------------------------------------------------*/
void InitTimer(void) {
    T3GCONbits.TMR3GE = 1;
    T3GCONbits.T3GSPM = 0;
    T3GCONbits.T3GTM = 0;
    T3GCONbits.T3GPOL = 1;
    T3GCONbits.T3GSS = 0b00;
    
    T3CONbits.TMR3CS = 0b00;
    T3CONbits.T3CKPS = 0b00;
    T3CONbits.nT3SYNC = 1;
    T3CONbits.TMR3ON = 1;
}

/* Interrupts from:                                                      */
/*  Timer 3 Gate                                                         */
/*-----------------------------------------------------------------------*/
void InitInterrupt(void) {
    GIE = 1;
    PEIE = 1;
    /* Enabling interrupt for Timer 3 gate                              */
    TMR3GIE = 1;        // Direct access due to conflicts with PIE3bits.TMR3GIE    
}

/* Setting the default point of the actors                              */
/* Actors are on default state -> no motion will occoure                */
void InitActors (void) {
    t_actors.aile = 500;
    t_actors.elev = 500;
    t_actors.thro = 0;
    t_actors.rudd = 500;
}
// </editor-fold>
