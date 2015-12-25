#include <PIC16F1827.h>
#include "hovi_LED_v2.h"


/*---------------------------------------------------------------------------*/
/* Retrieves Object from Pixy                                                */
/* Maximum tries for getting startcondition c = 10, retuns 0 if overrun      */
/* Returns a found Object in struct colorobject                              */
/* Searches for desired object des_obj by controlling with ProofObject()     */
/* Searches for specific objecttype by des_obj_type, desired object type     */
/*      des_obj_type = 0 => searches for normal objects                      */
/*      des_obj_type = 1 => searches for colorcodeobjects                    */
/* Maximum Objectss to dedect declared by max_obj                            */
/*---------------------------------------------------------------------------*/
unsigned char GetObject(unsigned char des_obj_type, unsigned int des_obj, unsigned char max_obj){
    unsigned int start, objcc;
    unsigned char obj_type;       /* declares type of detected object
                         * 0 for normal objects
                         * 1 for colorcode objects*/
    
    typedef struct colorobject{
        unsigned int num; /* num contains as much diggits as colors in the code 
                           * -> color 3, color 7, num = 37*/
        unsigned int pos_x; // X center of object
        unsigned int pos_y; // Y center of object
        unsigned int width; // width of object
        unsigned int height; // height of object
        unsigned int angle; // Rotation
        
    } farben;
    
    farben afarben[3];
    
    unsigned char c = 0;    // Counter for following do, while loop
    frame = 0;
    
    
    for(unsigned char c_obj = 0; c_obj < max_obj; c_obj++) {
        /* Routine for getting startcondition                                    */
        /* Returns 0 after 10 cycles without detecting an object                 */
        /*-----------------------------------------------------------------------*/
        
        while(frame == 0) {
            w = ExchangeSpi2char(PIXY_SYNC, DUMMY);
            if(lw == PIXY_FRAME_OBJ && w == PIXY_FRAME_OBJ) {
                frame = 1;
                obj_type = 0;
            } else if(lw == PIXY_FRAME_OBJ && w == PIXY_COLORCODE) {
                frame = 1;
                obj_type = 1;
            } else if(w == 0 && lw == 0){
                frame = 0;
            }
            lw = w;
            c++;
            if(c > 254) {
                return 0;
            }
        }

        unsigned int checksum = ExchangeSpi2char(PIXY_SYNC, DUMMY);


        afarben[c_obj].num =    ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].pos_x =  ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].pos_y =  ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].width =  ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].height = ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].angle =  ExchangeSpi2char(PIXY_SYNC, DUMMY);

        if(ProofObject(des_obj, afarben[c_obj].num)) {
            LedSignalling(afarben[c_obj].pos_x, afarben[c_obj].pos_y);
        }
    }
    __delay_ms(20);
    return 1;
}

bit ProofObject(unsigned int des_obj, unsigned int num){
    
    if(num == des_obj) {
        return 1;
    }else {
        NOP();
        return 0;
    }
}



void LedSignalling(unsigned int pos_x, unsigned int pos_y){
    
    /* Checking condtions for LED in x-direction                             */
    /* Sets LED in which direction the camera should be moved                */
    /* Both LEDs light up if data is nonsense                                */
    /*-----------------------------------------------------------------------*/
     if(pos_x > 170){
         LEDleft = 0;
         LEDright = 1;
     }else if(pos_x < 150){
         LEDleft = 1;
         LEDright = 0;   
     }else if(pos_x >= 150 && pos_x <= 170){
         LEDleft = 0;
         LEDright = 0;  
     }else{
         LEDleft = 1;
         LEDright = 1; 
     }
     
    /* Checking condtions for LED in y-direction                             */
    /* Sets LED in which direction the camera should be moved                */
    /* Both LEDs light up if data is nonsense                                */
    /*-----------------------------------------------------------------------*/
     if(pos_y < 90){
         LEDup = 1;
         LEDdown = 0;
     }else if(pos_y > 110){
         LEDup = 0;
         LEDdown = 1;
     }else if(pos_y >= 90 && pos_y <= 110){
         LEDup = 0;
         LEDdown = 0;
     }else{
         LEDup = 1;
         LEDdown = 1;
     }
}


