/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext f�r eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses ben�tigt wird.             */

#ifndef ACTORS_H
#define	ACTORS_H

#include <xc.h>
#include "main.h"

/*---------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                               */ 
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userroutines">
void ActAileron(unsigned char change);
void ActElevator(unsigned char change);
void ActThrottle(signed char change);
void ActRudder(unsigned char change);
void SignalOut(void);
void Delay(unsigned int del);
// </editor-fold>


/*---------------------------------------------------------------------------*/
/* Beginning of uservariables.                                               */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Uservariables">
typedef struct act_out {
    unsigned int aile;      //Seitw�rts
    unsigned int elev;      //Vorw�rts/R�ckw�rts
    unsigned int thro;      //H�he
    unsigned int rudd;      //Drehung
} t_actors;

t_actors a_actors[1];
// </editor-fold>

#endif	/* ACTORS_H */

