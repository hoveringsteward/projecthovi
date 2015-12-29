/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext für eine              */
/* Filebeschreibung aus welcher klar hervorgehen soll was in       */
/* diesem File passiert und wozu dieses benötigt wird.             */

#ifndef PIXY_H
#define	PIXY_H

#include <xc.h>
#include "main.h"

/*----------------------------------------------------------------------*/
/* Prototypes of userroutines.                                          */ 
/*----------------------------------------------------------------------*/
unsigned char ReadObject(unsigned char des_obj_type, unsigned int des_obj, unsigned char max_obj);

/*----------------------------------------------------------------------*/
/* User defined Variables                                               */
/*----------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
typedef struct colorobject {
    unsigned int type;  /* Colorcode or Object */
    unsigned int num; /* num contains as much diggits as colors in the code
                       * displayed as octal value
                       * -> color 3, color 7, num = 37*/
    unsigned int pos_x; // X center of object
    unsigned int pos_y; // Y center of object
    unsigned int width; // width of object
    unsigned int height; // height of object
    unsigned int angle; // Rotation
} t_colors;
    
t_colors a_color[5];
bit frame = 0;
bit obj_type;
unsigned int w;
unsigned int lw;
// </editor-fold>

#endif	/* PIXY_H */

