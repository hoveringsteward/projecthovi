/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext für eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses benötigt wird.             */

#ifndef INIT_H
#define	INIT_H

#include <xc.h>
#include "main.h"

/*---------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                               */ 
/*---------------------------------------------------------------------------*/
void Fkt_Init(void);
void Fkt_InitPort(void);
void Fkt_InitTris(void);
void Fkt_InitAnsel(void);
void Fkt_InitOsc(void);
void Fkt_InitUart(void);
void Fkt_InitSpi(void);
void Fkt_InitTimer(void);
void Fkt_InitInterrupt(void);

#endif	/* INIT_H */

