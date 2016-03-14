/*
 * File:   sim_test8.c
 * Author: Lucas
 *
 * Created on 16. Februar 2016, 10:14
 */


#include <xc.h>

unsigned int var = 32145;
unsigned char a;
unsigned char info = 0;

void main(void) {
    if(++info) {
        var = info;
        NOP();
    }
    return;
}
