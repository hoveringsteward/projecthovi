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
void Init(void);
void InitPort(void);
void InitTris(void);
void InitAnsel(void);
void InitOsc(void);
void InitUart(void);
void InitSpi(void);
void InitTimer(void);
void InitInterrupt(void);

#endif	/* INIT_H */

