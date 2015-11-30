#include <PIC16F1827.h>
#include "hovi_LED_v2.h"


void getObject(void){
    
    unsigned int start, objcc;
    
    typedef struct colorobject{
        unsigned int num; // num besteht bei einem 2F�rbigen Objekt aus 2Ziffern -> Farbe 3, Farbe 7, num = 37
        unsigned int posX; // Mittelpunkt X
        unsigned int posY; // Mittelpunkt Y
        unsigned int width; 
        unsigned int height;
        unsigned int angle; // Rotation
        
    };
    
    typedef struct colorobject farben1;
    typedef struct colorobject farben2;
    
    unsigned char frame = 0;
    
    while(!frame) {
        ExchangeSpi2char(PIXY_SYNC, DUMMY);
        
        if(ExchangeSpi2char() == 0xaa55) {
            frame = 1;
        }
    }
    proofObject();
    
}

void proofObject(void){
    
    unsigned int posX, posY, objnum;
    
    if(){
        
    }
    
    xxx(posX, posY);
    
}



void LedSignalling(unsigned int posX, unsigned int posY){
    
    
     if(posX > 170){
         LEDleft = 0;
         LEDright = 1;
     }else if(posX < 150){
         LEDleft = 1;
         LEDright = 0;   
     }else if(posX >= 150 && posX <= 170){
         LEDleft = 0;
         LEDright = 0;  
     }else{
         LEDleft = 1;
         LEDright = 1; 
     }
     
     if(posY < 90){
         LEDup = 1;
         LEDdown = 0;
     }else if(posY > 110){
         LEDup = 0;
         LEDdown = 1;
     }else if(posY >= 90 && posY <= 110){
         LEDup = 0;
         LEDdown = 0;
     }else{
         LEDup = 1;
         LEDdown = 1;
     }
     
}


