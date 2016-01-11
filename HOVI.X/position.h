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
void CompareFrames(void);
void CheckAileron(void);
void CheckElevator(void);
void BeneathTable(void);
void BeneathFloor(void);
void CheckThrottle(void);
void CheckRudderAhead(void);
void CheckRudderBack(void);
void StoreAsOld(void);
// </editor-fold>


/*----------------------------------------------------------------------*/
/* User defined Variables                                               */
/*----------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Variables">
typedef struct nt_frame {
    unsigned int num; // colorcode id
    unsigned int pos_x; // X center of object
    unsigned int pos_y; // Y center of object
    unsigned int height; // height of hex-rotor
    int angle; // rotation 
} t_frame;

t_frame a_frame[2];
/* a_frame[0] = current frame
 * a_frame[1] = last frame
 */

typedef struct nt_frame_dif {
    unsigned int num; // colorcode id
    signed int pos_x; // X center of object
    signed int pos_y; // Y center of object
    signed int height; // height of hex-rotor
    signed int angle; // rotation
} t_frame_dif;

t_frame_dif a_frame_dif[1];
/* a_frame_dif[0] = difference of a_frame[0] and a_frame[1] */

bit direction;      /* Flightdirection, 0 == ahead, 1 == back */

int cm180 = 41982;
int cm220 = 51310;
int cm100 = 23323;
int cm120 = 27987;
int cm80 = 18659;
int cm50 = 11662; // 11661.5

// FÜRS WLAN !!!!!!!!!!!!!!! - gehört da nicht rein
int c_path = 10; // 10 counter der farben
int id_current_cc; // der wievielte Farbcode 0-9

bit storedif;
bit table;

// </editor-fold>
#endif	/* POSITION_H */

