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

// </editor-fold>


/*---------------------------------------------------------------------------*/
/* Beginning of uservariables.                                               */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Uservariables">
typedef struct act_out{
    unsigned int aile;      //Seitw�rts
    unsigned int elev;      //Vorw�rts/R�ckw�rts
    unsigned int thro;      //H�he
    unsigned int rudd;      //Drehung
} t_actors;
// </editor-fold>

#endif	/* ACTORS_H */

