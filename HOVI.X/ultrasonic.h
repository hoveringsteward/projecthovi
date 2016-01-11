/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext für eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses benötigt wird.             */
#ifndef ULTRASONIC_H
#define	ULTRASONIC_H

#include <xc.h>
#include "main.h"

/*---------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                               */ 
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userroutines">
void StartHeightMeasure(void);
void ReadHeight(void);
// </editor-fold>

/*------------------------------------------------------------------*/
/* User defined Variables                                           */
/*------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
unsigned int time_height;
float outgoing;
float changerate = 0.2; // 20 percent
bit highpassallowed = 1; // should be used in position.c -> check throttle
// </editor-fold>

#endif	/* ULTRASONIC_H */

