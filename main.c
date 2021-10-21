/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC18F4550
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc.h"
#include "stdio.h"
#include "stdlib.h"
#include <xlcd.h>

/*
                         Main application
 */

#define song_A  PORTBbits.RB7
#define inc  PORTBbits.RB6
#define dec  PORTBbits.RB5

#define A4      70
#define As4     66
#define B4      62
#define C4      118
#define Cs4     112
#define D4      105
#define Ds4     99
#define E4      94
#define F4      88
#define Fs4     83
#define G4      79
#define Gs4     74

#define A5      17
#define As5     16
#define B5      15
#define C5      29
#define Cs5     27
#define D5      26
#define Ds5     24
#define E5      23
#define F5      21
#define Fs5     20
#define G5      19
#define Gs5     18
int veloc;

//void modulePause(int mode, int mul);
void checkVeloc(void);
void pause(int vel);
void pause2(int vel);
void pause3(int vel);
void tone(int valTMR2);
void tone_2Pressed(int valTMR2);
void tone_3Pressed(int valTMR2);
void melody1(void);
void melody2(void);
void melody3(void);
    
void pause(int vel){
    if(vel == 1){
    __delay_ms(300);
    TMR2_StopTimer();
    __delay_ms(300);
    }
    if(vel == 2){
    __delay_ms(150);
    TMR2_StopTimer();
    __delay_ms(150);
    }
    if(vel == 3){
    __delay_ms(100);
    TMR2_StopTimer();
    __delay_ms(100);
    }
}

void pause2(int vel){
    if(vel == 1){
    __delay_ms(600);
    TMR2_StopTimer();
    __delay_ms(300);
    }
    if(vel == 2){
    __delay_ms(300);
    TMR2_StopTimer();
    __delay_ms(150);
    }
    if(vel == 3){
    __delay_ms(200);
    TMR2_StopTimer();
    __delay_ms(100);
    }
}

void pause3(int vel){
    if(vel == 1){
    __delay_ms(900);
    TMR2_StopTimer();
    __delay_ms(300);
    }
    if(vel == 2){
    __delay_ms(450);
    TMR2_StopTimer();
    __delay_ms(150);
    }
    if(vel == 3){
    __delay_ms(300);
    TMR2_StopTimer();
    __delay_ms(100);
    }
}

void tone(int valTMR2){
    TMR2_StartTimer();
    PR2 = valTMR2; 
    pause(veloc);
}

void tone_2Pressed(int valTMR2){
    TMR2_StartTimer();
    PR2 = valTMR2;
    pause2(veloc);
}

void tone_3Pressed(int valTMR2){
    TMR2_StartTimer();
    PR2 = valTMR2;
    pause3(veloc);
}

void melody1(){
    tone(C4);
    tone(C4);
    tone(G4);
    tone(G4);
    tone(A4);
    tone(A4);
    tone(G4);
    pause(veloc);
    tone(F4);
    tone(F4);
    tone(E4);
    tone(E4);
    tone(D4);
    tone(D4);
    tone(C4);
    pause(veloc);
    tone(G4);
    tone(G4);
    tone(F4);
    tone(F4);
    tone(E4);
    tone(E4);
    tone(D4);
    pause(veloc);
    tone(G4);
    tone(G4);
    tone(F4);
    tone(F4);
    tone(E4);
    tone(E4);
    tone(D4);
    tone(C4);
    tone(C4);
    tone(G4);
    tone(G4);
    tone(A4);
    tone(A4);
    tone(G4);
    pause(veloc);
    tone(F4);
    tone(F4);
    tone(E4);
    tone(E4);
    tone(D4);
    tone(D4);
    tone(C4);
    pause(veloc);
}

/*void melody2(){
    tone_2Pressed(G4);
    tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    pause();
    tone_2Pressed(G4);
    tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    pause();
    tone_2Pressed(D5);
    tone(D5);
    tone_3Pressed(B4);
    tone_2Pressed(C5);
    tone(C5);
    tone_3Pressed(G4);
    pause();
    tone_2Pressed(A4);
    tone(A4);
    tone_2Pressed(C5);
    tone(B4);
    tone(A4);
    tone_2Pressed(G4);
    tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    tone_2Pressed(A4);
    tone(A4);
    tone_2Pressed(C5);
    tone(B4);
    tone(A4);
    tone_2Pressed(G4);
    tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    pause();
    tone_2Pressed(D5);
    tone(D5);
    tone_2Pressed(F5);
    tone(D5);
    tone(B4);
    tone_3Pressed(C5);
    tone_3Pressed(E5);
    tone(C5);
    tone(G4);
    tone(E4);
    tone(G4);
    tone(F4);
    tone(D4);
    tone_3Pressed(C4);
    pause();
}

void melody3(){
    tone(D4);
    tone(D4);
    tone(E4);
    tone(D4);
    
    tone(G4);
    tone(Fs4);
    pause();
    
    tone(D4);
    tone(D4);
    tone(E4);
    tone(D4);
    
    tone(A4);
    tone(G4);
    pause();
    
    tone(D4);
    tone(D4);
    tone(D5);
    tone(B4);
    tone(G4);
    tone(Fs4);
    tone(E4);
    pause();
    
    tone(C5);
    tone(C5);
    tone(B4);
    tone(G4);
    tone(A4);
    tone(G4);
}*/

void checkVeloc(){
    if(inc){
        veloc++;
        if(veloc == 4) veloc = 1;
    }
    switch(veloc){
        case 1:
            T2CON = 0b00011011;
            break;
        case 2:
            T2CON = 0b00011001;
            break;
        case 3:
            T2CON = 0b00011000;
            break;
    }
    /*if(dec){
        if(veloc == 0) veloc = 3
        veloc--;
    }*/
}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    veloc = 1;
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //period of 100 us and duty cycle of 50 us
    
    /*tone(A4);
    tone_2Pressed(G4);
    tone_3Pressed(E4);
    pause();*/
            
    while (1)
    {
        if(song_A) melody1();
        if(inc) checkVeloc();
        //if(dec) checkVeloc();
    }
}

/**
 End of File
*/