/* 
 * File:   hovi_LED.h
 * Author: Lucas
 *
 * Created on 14. November 2015, 07:12
 */

#include "hovi_v2.h"

#ifndef HOVI_LED_V2_H
#define	HOVI_LED_V2_H

unsigned char GetObject(unsigned char des_obj_type, unsigned int des_obj, unsigned char max_obj);
bit ProofObject(unsigned int des_obj, unsigned int num);
void LedSignalling(unsigned int pos_x, unsigned int pos_y);

#endif	/* HOVI_LED_H */

