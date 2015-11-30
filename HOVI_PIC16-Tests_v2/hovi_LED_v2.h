/* 
 * File:   hovi_LED.h
 * Author: Lucas
 *
 * Created on 14. November 2015, 07:12
 */

#include "hovi_v2.h"

#ifndef HOVI_LED_H
#define	HOVI_LED_H

unsigned char GetObject(bit des_obj_type, unsigned int des_obj);
void ProofObject(unsigned int des_obj);
void LedSignalling(unsigned int pos_x, unsigned int pos_y);

#endif	/* HOVI_LED_H */

