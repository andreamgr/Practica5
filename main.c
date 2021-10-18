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

 void tocar_nota(int duracion, float tfrec){  //funcion generadora de notas, periodo de la nota y duracion de esta
 

     duracion = duracion/tfrec;
     tfrec = 255-((tfrec/2)/(.0002*128));

       for(b=0;b<duracion;b++){
           
            PORTAbits.RA0 = 1;
           TMR0 = tfrec;
           while(INTCONbits.TMR0IF==0);
           INTCONbits.TMR0IF=0;
  
        PORTAbits.RA0=0;
         TMR0 = tfrec;
         while(INTCONbits.TMR0IF==0);
         INTCONbits.TMR0IF=0;
}
  
 }
 void silencio(int duracion, float tfrec){  //funcion generadora de notas, periodo de la nota y duracion de esta
     
     duracion = duracion/tfrec;
     tfrec = 255-((tfrec/2)/(.0002*128));

       for(b=0;b<duracion;b++){
            PORTAbits.RA0 = 0;
           TMR0 = tfrec;
           while(INTCONbits.TMR0IF==0);
           INTCONbits.TMR0IF=0;
  
        PORTAbits.RA0=0;
         TMR0 = tfrec;
         while(INTCONbits.TMR0IF==0);
         INTCONbits.TMR0IF=0;
}
 }

 


 void confT0(){
     //11000010
    T0CONbits.TMR0ON = 1; //encendido
      T0CONbits.T08BIT = 1;  //modo 8 bits
      T0CONbits.T0CS = 0; //modo temporizador tcy
      T0CONbits.T0SE = 0; //leer bajadas
      T0CONbits.PSA = 0;  //con preescalador
      T0CONbits.T0PS = 0b110; 
     
      INTCONbits.TMR0IE = 1;      // Habilitamos las interrupci�n por desborde de TIMER0


 }
 
 
 void cancion1(){
      
     tocar_nota(500,3.034);
      tocar_nota(500,3.034);
      tocar_nota(500,3.034);
      
       tocar_nota(375,3.82);     
        tocar_nota(125,2.551);
        
        tocar_nota(500,3.034);
        
       tocar_nota(375,3.82);
        tocar_nota(125,2.551);
        
        tocar_nota(1000,3.034);
      
        tocar_nota(500,2.028);
        tocar_nota(500,2.028);
        tocar_nota(500,2.028);
        
        tocar_nota(375,1.911);
        tocar_nota(125,2.551);
        
        tocar_nota(500,3.61);
        
         tocar_nota(375,3.82);
        tocar_nota(125,2.551);
        
        tocar_nota(1000,3.034);

        tocar_nota(500,1.517);
        tocar_nota(375,3.034);
        tocar_nota(125,3.034);    
        tocar_nota(500,1.517);
 
         tocar_nota(375,1.607);
        tocar_nota(125,1.703);  
 
         tocar_nota(125,1.804);
          tocar_nota(125,1.911);
          tocar_nota(300,1.804);
          
          silencio(100,3.822); 
          tocar_nota(300,2.863);
          tocar_nota(500,2.145);

          tocar_nota(375,2.273);
        tocar_nota(125,2.408);  
        
        tocar_nota(125,2.551); 
        tocar_nota(125,2.703); 
        tocar_nota(300,2.551); 
        
        silencio(100,3.822); 
        tocar_nota(300,3.822); 
        tocar_nota(500,3.608); 
         tocar_nota(375,3.822);
        tocar_nota(125,2.551);
       
        tocar_nota(500,3.034); 
        tocar_nota(375,3.822);
        tocar_nota(125,2.551);
        tocar_nota(2500,3.034); 
        silencio(1000,3.822); 
 }

void cancion2(){ //ANDREA
 
 
  tocar_nota(150,1.51); //mi
  tocar_nota(150,1.51); //mi
  tocar_nota(150,1.51); //mi
   tocar_nota(150,1.91);     //do 
   tocar_nota(300,1.51); //mi
   tocar_nota(300,1.276); //sol
   
  tocar_nota(300,1.91);//do
   
  
   tocar_nota(300,2.551);//sol
   
   tocar_nota(300,3.034); //mi
 
   tocar_nota(300,2.551); //sol
   
   tocar_nota(300,2.025); //si
   
   tocar_nota(300,2.145); //la#
   
   tocar_nota(300,2.273);//la
   
   tocar_nota(300,2.551);//sol
   
   
   tocar_nota(300,1.51);//mi
   

   
   tocar_nota(300,1.27); //sol
   tocar_nota(300,1.13); //la
   
      tocar_nota(150,1.43); //fa
   tocar_nota(150,1.27); //sol
   
      tocar_nota(300,1.51);//mi
   
      
   tocar_nota(150,1.91);   //do  
   
   tocar_nota(150,1.70); //re
   
   tocar_nota(300,2.551); //sol
   
   

   tocar_nota(375,3.82);     //do 
  
   tocar_nota(125,3.034); //mi
   tocar_nota(500,2.551); //sol
   
   tocar_nota(375,3.82);//do
  
   tocar_nota(125,2.551);//sol
   
   tocar_nota(1000,2.863); //fa
 
   tocar_nota(500,2.273); //la
   
   tocar_nota(500,2.025); //si
   
   tocar_nota(500,2.145); //la#
   
   tocar_nota(375,2.273);//la
   
   tocar_nota(125,2.551);//sol
   
   tocar_nota(500,3.034);//mi
   
    tocar_nota(375,2.551);//sol
    
   tocar_nota(125,2.551); //la
   
   tocar_nota(1000,3.034); //fa
   tocar_nota(500,2.551); //sol
   
   tocar_nota(375,3.034); //mi
   
   tocar_nota(125,3.82);   //do  
   
   tocar_nota(500,3.405); //re
   tocar_nota(375,2.025); //si
   tocar_nota(125,2.551);//sol
   
   tocar_nota(500,3.034);//mi
   
   tocar_nota(375,2.551);//sol
    
   tocar_nota(125,2.551); //la
   
   tocar_nota(1000,3.034); //fa
   tocar_nota(500,2.551); //sol
   
   tocar_nota(375,3.034); //mi
   
   tocar_nota(125,3.82);   //do  
   
   tocar_nota(500,3.405); //re
   tocar_nota(375,2.025); //si
   tocar_nota(375,2.551);//sol
    
   tocar_nota(125,2.551); //la
   
   tocar_nota(1000,3.034); //fa
   tocar_nota(500,2.551); //sol
   
   tocar_nota(375,3.034); //mi
   
   tocar_nota(125,3.82);   //do  
   
   tocar_nota(500,3.405); //re
   tocar_nota(375,2.025); //si
   
   silencio(1000,3.822);
   
   
        
 }

 

  void cancion3(){ //Emman
      
      tocar_nota(500,2.70); 
 tocar_nota(500,2.70); 
tocar_nota(500,2.70);
tocar_nota(500,2.70); 
tocar_nota(375,2.73); //sol
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(500,2.70); 
tocar_nota(375,2.73);
tocar_nota(125,3.40);
tocar_nota(125,3.40);
tocar_nota(125,3.40);//re
tocar_nota(375,3.03); //mi
tocar_nota(375,3.03); //mi
tocar_nota(500,2.70); 
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
 tocar_nota(375,3.03);
tocar_nota(125,2.27);//la
  tocar_nota(1000,2.86);//fa
tocar_nota(125,3.82);//do
tocar_nota(375,3.03);
tocar_nota(375,3.03);
tocar_nota(500,2.70); 
 tocar_nota(500,2.70); 
tocar_nota(500,2.70); 
 tocar_nota(500,2.70); 
tocar_nota(500,2.70);
tocar_nota(500,2.70); 
tocar_nota(375,2.73); //sol
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(500,2.70); 
tocar_nota(375,2.73);
tocar_nota(125,3.40);
tocar_nota(125,3.40);
tocar_nota(125,3.40);//re
tocar_nota(375,3.03); //mi
tocar_nota(375,3.03); //mi
tocar_nota(500,2.70); 
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
 tocar_nota(375,3.03);
tocar_nota(125,2.27);//la
  tocar_nota(1000,2.86);//fa
tocar_nota(125,3.82);//do
tocar_nota(375,3.03);
tocar_nota(375,3.03);
tocar_nota(500,2.70); 
 tocar_nota(500,2.70); 
tocar_nota(500,2.70); 
 tocar_nota(500,2.70); 
tocar_nota(500,2.70);
tocar_nota(500,2.70); 
tocar_nota(375,2.73); //sol
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(500,2.70); 
tocar_nota(375,2.73);
tocar_nota(125,3.40);
tocar_nota(125,3.40);
tocar_nota(125,3.40);//re
tocar_nota(375,3.03); //mi
tocar_nota(375,3.03); //mi
tocar_nota(500,2.70); 
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
tocar_nota(375,2.73);
 tocar_nota(375,3.03);
tocar_nota(125,2.27);//la
  tocar_nota(1000,2.86);//fa
tocar_nota(125,3.82);//do
tocar_nota(375,3.03);
tocar_nota(375,3.03);
tocar_nota(500,2.70); 
 tocar_nota(500,2.70);
   silencio(1000,3.822);     
 }

void main(void) {
   
    ADCON1 = 15;

    TRISA =  0b00010000;
     TRISB = 0b11111111;
    confT0();

while (1) { 
        
     if (PORTBbits.RB0 == 1) {
         while(PORTBbits.RB0==1);
                       cancion1();
        
     }
     if (PORTBbits.RB1 == 1) {
while(PORTBbits.RB1==1);          
                       cancion2();
        
     }
     if (PORTBbits.RB2 == 1) {
         while(PORTBbits.RB2==1);
                       cancion3();
              
     }
     else{
         PORTAbits.RA0 = 0;
     }
      
 	} 
 
 

    
    
    
    
}




