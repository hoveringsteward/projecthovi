/*
 * File:   test_sim_2.c
 * Author: Lucas
 *
 * Created on 15. Dezember 2015, 16:13
 */


#include <xc.h>

#define TESTVAR 10
unsigned char product = 0;
bit status;

unsigned char Fkt_test(unsigned char multiplier) {
    product = 5 * multiplier;
    return product;
}

void main(void) {
    while(1) {
        if(Fkt_test(3) == TESTVAR) {
            status = 1;
        }else {
            status = 0;
        }
    }
    return;
}
