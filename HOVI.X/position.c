/*-----------------------------------------------------------------*/
/* Author: Chrisy                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/*
 * 
 */

#include <xc.h>
#include "main.h"
#include "position.h"
#include "actors.h"



// <editor-fold defaultstate="collapsed" desc="compare Frames">

/*---------------------------------------------------------------------------*/
/* compareFrames
 * compares the position Y of one colorobject in a frame with the same 
 * colorobject in the next frame
 * 2nd frame - 1st frame
/*---------------------------------------------------------------------------*/

void CompareFrames(void){
       
    a_frame_dif[0].height = a_frame[1].height - a_frame[0].height;
    
    if(a_frame[1].num == a_frame[0].num){  
        a_frame_dif[0].pos_x = a_frame[1].pos_x - a_frame[0].pos_x;
        a_frame_dif[0].pos_y = a_frame[1].pos_y - a_frame[0].pos_y;
        a_frame_dif[0].angle = a_frame[1].angle - a_frame[0].angle;
    }else{
        return 0; 
    }
          
    a_frame[1].num = a_frame[0].num;
    a_frame[1].pos_x = a_frame[0].pos_x;
    a_frame[1].pos_y = a_frame[0].pos_y;
    a_frame[1].height = a_frame[0].height;
    a_frame[1].angle = a_frame[0].angle;
     
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="compare Frames">

/*---------------------------------------------------------------------------*/
/* compareFrames
 * compares the position Y of one colorobject in a frame with the same 
 * colorobject in the next frame
 * 2nd frame - 1st frame
/*---------------------------------------------------------------------------*/

void CheckAileron(void){
      
    DES_X_MIN, DES_X_MAX;
    int dif, difold;
     
    if(a_frame[1].num == a_frame[0].num){  
        
        if(a_frame[0].pos_x >= 150 && a_frame[0].pos_x <= 170){
            
            ActElevator();
            
        }else if(a_frame[0].pos_x > 170){
            if(a_frame[1].pos_x < a_frame[0].pos_x){
                if((a_frame[1].pos_x - a_frame[0].pos_x) < 4){
                    ActAileron(0); // keep doing
                }else{
                    ActAileron(-DUMMY); // slow down
                }
            }else{
                ActAileron(); // fly to the left
            }
        }else{ // a_frame[0].pos_x < 170
            if(a_frame[1].pos_x > a_frame[0].pos_x){
                if((a_frame[1].pos_x - a_frame[0].pos_x) >- 4){
                    ActAileron(0); // keep doing
                }else{
                    ActAileron(DUMMY); // slow down
                }
            }
            
            ActAileron(DUMMY); // fly to the right
        
        }
        
        
        
        {
            int tmp = difold - dif;
            if(tmp > 0){ // am richtigen Weg
                ActAileron(); // Zahl wie viel er schneller/langsame werden soll
            }else{
                ActAileron(); // am falschen Weg
            }
            
            
            
            
        }
        
        
        a_frame_dif[0].pos_x = a_frame[1].pos_x - a_frame[0].pos_x;
    }else{
        return 0; 
    }

    
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
    
    difold = dif;
    a_frame[1].num = a_frame[0].num;
    a_frame[1].pos_x = a_frame[0].pos_x;
    a_frame[1].pos_y = a_frame[0].pos_y;
    a_frame[1].height = a_frame[0].height;
    a_frame[1].angle = a_frame[0].angle;
     
     
     
}
// </editor-fold>