/*
 * File:   main.c
 * Author: Lucas
 *
 * Created on 25. November 2015, 16:50
 */


#include <xc.h>

#include "main.h"
#include "init.h"


void main(void) {
    init();
    while(1) {
        LED = 1;
        __delay_ms(300);
        LED = 0;
        __delay_ms(300);
    }
    return;
}
