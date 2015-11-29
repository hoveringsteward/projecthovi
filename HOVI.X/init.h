/* 
 * File:   init.h
 * Author: Lucas
 *
 * Created on 25. November 2015, 17:02
 */

#ifndef INIT_H
#define	INIT_H

#include <xc.h>

/*****************************************************************************/
/* Prototypes of userroutines.                                               */ 
/*****************************************************************************/

void init(void);
void init_PORT(void);
void init_TRIS(void);
void init_ANSEL(void);
void init_UART(void);
void init_SPI(void);
void init_TMR(void);
void init_OSC(void);

#endif	/* INIT_H */

