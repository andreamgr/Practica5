/* 
 * File:   main.c
 * Author: Alan Cruz
 *
 * Created on 20 de septiembre de 2021, 12:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "LCD_lib.h"
#include "conf.h"


char buffer1[8];
float distancia = 2;
     int a,b,s;//DECLARAMOS VARIABLES DE TIPO ENTERO
void ADC_Init()
{    
    TRISA = 0xFF;	
    ADCON1 = 0x0E;	
    ADCON2 = 0x92;	
    ADRESH=0;		
    ADRESL=0;   
} 

int ADC_Read(int channel)
{
    int digital;
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);  
    ADCON0 |= ((1<<ADON)|(1<<GO));	
    while(ADCON0bits.GO_nDONE==1);
    digital = (ADRESH*256) | (ADRESL);	
    return(digital);
}


void main(void) {
   
    
    ADCON1 = 11;

    TRISA =  0b00010000;
     TRISB = 0b11111111;

     while(1){
         
     }
 
 

    
    
    
    
}




