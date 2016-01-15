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
void UartSendError(void);
void UartDump(void);

unsigned char received;
unsigned char c_path = 0;
unsigned char c_name = 0;
unsigned char numb_cc = 0;  // Number of received CC
unsigned char numb_cc_table = 0;    /* point from which on CC's are on
                                     * a table */
bit receiving_ok = 0;   /* States if startkondition appeared or not if not,
                         * received bytes wont be stored as CC num */

typedef struct nt_path{
    unsigned char lower_cc;
    unsigned char higher_cc;
}t_path;

t_path a_path[21];

unsigned char a_name[32];
bit path_name = 0;  // 0 => storing path; 1 => storing name

#endif	/* WLAN_H */

