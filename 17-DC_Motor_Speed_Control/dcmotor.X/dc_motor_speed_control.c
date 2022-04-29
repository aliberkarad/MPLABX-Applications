/*
 * File:   dc_motor_speed_control.c
 * Author: aliberkarad
 *
 * Created on 29 Nisan 2022 Cuma, 16:51
 */


#include <xc.h>
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000

void __interrupt() inter(void){
    if(!RB6){
        PORTD=5;
    }
    else{
        PORTD=10;
    }
    if(RB5){
        if(CCPR1L>245){
            CCPR1L=1;
        }       
        CCPR1L+=20;
    }
    if(RB4){
        if(CCPR1L==0){
            CCPR1L=245;
        }       
        CCPR1L-=20;
    }
    RBIF=0;
}

void main(void) {
    GIE=1;
    RBIE=1;
    
    TRISB=0xF0;
    TRISC=0x00;
    TRISD=0x00;
    PORTD=0x05;
    
    CCP1M3=1;
    CCP1M2=1;
    CCPR1L=125;
    
    PR2=249;
    T2CKPS1=0;
    T2CKPS0=1;
    TMR2ON=1;
    
    while(1);
}
