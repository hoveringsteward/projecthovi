/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext f�r eine
 * Filebeschreibung aus welcher klar hervorgehen soll was in
 * diesem File passiert und wozu dieses ben�tigt wird.
 */

#ifndef COMMUNICATION_H
#define	COMMUNICATION_H

#include <xc.h>
#include "main.h"

/*---------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                               */ 
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userroutines">
unsigned char ExchangeSpiByte(unsigned char byte1);
unsigned int ExchangeSpiWord(unsigned char byte1, unsigned char byte2);
// </editor-fold>


#endif	/* COMMUNICATION_H */

