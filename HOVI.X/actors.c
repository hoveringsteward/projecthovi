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
 * -> the commands for roll / nick / gear are in their c-files 
 * (roll_nick_gear - directory)
 */


#include <xc.h>
#include "main.h"

void ActAilerons(){
    
}

void ActElevator(){

}

void ActRudder(){

}

void ActThrottle(){
    // Height
}