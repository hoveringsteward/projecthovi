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

// </editor-fold>


/*---------------------------------------------------------------------------*/
/* Beginning of uservariables.                                               */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Uservariables">
typedef struct act_out{
    unsigned int aile;      //Seitwärts
    unsigned int elev;      //Vorwärts/Rückwärts
    unsigned int thro;      //Höhe
    unsigned int rudd;      //Drehung
} t_actors;
// </editor-fold>

#endif	/* ACTORS_H */

