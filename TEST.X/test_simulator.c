/*
 * File:   test_simulator.c
 * Author: Lucas
 *
 * Created on 7. November 2015, 19:20
 */


unsigned char c = 0;

#include <xc.h>




void main(void) {
    
    typedef struct test{
        unsigned char var1;
        unsigned char var2;
        unsigned char var3;
    };
    
    unsigned char i = 0;
    
    typedef struct test stru;
    stru astru[];
    while(1) {
        astru[i].var1 = 2;
        c = astru[i].var1;
        NOP();
        c = 0;
        NOP();
        i++;
        astru[i].var1 = 3;
        c = astru[i].var1;
        NOP();
        c = 0;
        NOP();
    }
    return;
}
