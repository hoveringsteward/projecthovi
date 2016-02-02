/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext für eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses benötigt wird.             */

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
    unsigned int aile;      //Seitwärts
    unsigned int elev;      //Vorwärts/Rückwärts
    unsigned int thro;      //Höhe
    unsigned int rudd;      //Drehung
} t_actors;

t_actors a_actors[1];
// </editor-fold>

#endif	/* ACTORS_H */

