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

