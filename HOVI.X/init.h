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

#ifndef INIT_H
#define	INIT_H

#include <xc.h>
#include "main.h"

/*---------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                               */ 
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userroutines">
void Init(void);
void InitPort(void);
void InitTris(void);
void InitAnsel(void);
void InitOsc(void);
void InitUart(void);
void InitSpi(void);
void InitTimer(void);
void InitComp(void);
void InitInterrupt(void);
void InitActors(void);
#ifdef WLAN
void InitWlan(void);
#endif
// </editor-fold>

/*------------------------------------------------------------------*/
/* User defined Variables                                           */
/*------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
unsigned char pin_out = 'A';
// </editor-fold>

#endif	/* INIT_H */
