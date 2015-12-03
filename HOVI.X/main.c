/*
 * File:   main.c
 * Author: Lucas
 *
 * Created on 25. November 2015, 16:50
 */


#include <xc.h>

#include "main.h"
    

void main(void) {
    Fkt_Init();
    LED = 1;
    while(1) {
        
        NOP();
    }
    return;
}
