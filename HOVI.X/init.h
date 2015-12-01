/* 
 * File:   init.h
 * Author: Lucas
 *
 * Created on 25. November 2015, 17:02
 */

#ifndef INIT_H
#define	INIT_H

#include <xc.h>
#include "main.h"

/*****************************************************************************/
/* Prototypes of userroutines.                                               */ 
/*****************************************************************************/
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

