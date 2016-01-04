/* 
 * File:   wlan.h
 * Author: Lucas
 *
 * Created on 3. Januar 2016, 16:55
 */

#ifndef WLAN_H
#define	WLAN_H

#include "main.h"

void UartStore(void);
void UartSendOverflow(void);

unsigned char received;
unsigned char c_path = 0;
unsigned char c_name = 0;
unsigned char a_path[21];
unsigned char a_name[33];
bit path_name = 0;

#endif	/* WLAN_H */

