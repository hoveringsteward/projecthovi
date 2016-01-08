/*-----------------------------------------------------------------*/
/* Author: Chrisy                                                  */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Actors are components like propellers
 * they have to act, after they get the information from sensors
 * for example: if the position is wrong, he has to nick
 * if the rotation is wrong, he has to gear
 * if everything is fine, he could fly forwards
 * he has to change the velocity, if he flys to high or to low
 * -> the commands for roll / pitch / yaw are in their c-files 
 */


#include <xc.h>
#include "main.h"

// <editor-fold defaultstate="collapsed" desc="Act Ailerons">
/* ActAilerons                                                      */
/* roll = rollen -> links/rechts                                    */
/*------------------------------------------------------------------*/
void ActAileron(unsigned char change){
    a_actors[0].aile += change;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Act Elevator">
/* ActElevator                                                      */
/* pitch = nicken -> vor/zurück                                     */
/*------------------------------------------------------------------*/
void ActElevator(unsigned char change){
    a_actors[0].elev += change;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Act Throttle">
/* ActThrottle                                                      */
/* Height                                                           */
/*------------------------------------------------------------------*/
void ActThrottle(unsigned char change){
    a_actors[0].thro += change;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Act Rudder">
/* ActRudder                                                        */
/* yaw = gieren -> drehung an der hochachse                         */
/*------------------------------------------------------------------*/
void ActRudder(unsigned char change){
    a_actors[0].rudd += change;
}
// </editor-fold>

