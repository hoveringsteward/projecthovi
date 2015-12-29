/* 
 * File:   position.h
 * Author: Lucas
 *
 * Created on 29. Dezember 2015, 11:23
 */

#ifndef POSITION_H
#define	POSITION_H

#include <xc.h>
#include "main.h"

/*------------------------------------------------------------------*/
/* Prototypes of userroutines.                                      */ 
/*------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userroutines">
bit CompareFrames(void);
bit CheckAileron(void);
void StoreAsOld(void);
// </editor-fold>


/*----------------------------------------------------------------------*/
/* User defined Variables                                               */
/*----------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
typedef struct t_frame {
    unsigned int num; // colorcode id
    unsigned int pos_x; // X center of object
    unsigned int pos_y; // Y center of object
    unsigned int height; // height of hex-rotor
    unsigned int angle; // rotation
} a_frame[2];
/* (?) old
 * a_frame[0] = current frame
 * a_frame[1] = last frame
 * a_frame_dif[0] = difference of a_frame[0] and a_frame[1]
 */

typedef struct t_frame {
    unsigned int num; // colorcode id
    signed int pos_x; // X center of object
    signed int pos_y; // Y center of object
    signed int height; // height of hex-rotor
    signed int angle; // rotation
} a_frame_dif[1];
// </editor-fold>
#endif	/* POSITION_H */

