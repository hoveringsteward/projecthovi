/* 
 * File:   hovi_SPI.h
 * Author: Lucas
 *
 * Created on 10. November 2015, 07:00
 */

#include "hovi_v2.h"

#ifndef HOVI_SPI_H
#define	HOVI_SPI_H

    
void send_SPI_char(unsigned char data);
    
unsigned char exchange_SPI_char(unsigned char data);

unsigned char exchange_SPI_2char(unsigned char data, unsigned char data2);


#endif	/* HOVI_SPI_H */

