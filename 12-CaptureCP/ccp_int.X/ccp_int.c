/*
 * File:   ccp_int.c
 * Author: aliberkarad
 *
 * Created on 29 Nisan 2022 Cuma, 15:03
 */


#include <xc.h>
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low Voltage In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF         // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)
#define _XTAL_FREQ 4000000

int counter=0,times=0;

void __interrupt() capture(void){
    if(TMR1IF){
        counter++;
    }
    if(CCP1IF){
        times=(65536*counter+CCPR1)/1000000;
        if(times>=255){
            times=0;
            counter=0;
        }
        PORTB=times;
        counter=0;
        times=0;
    }
    TMR1IF=0;
    CCP1IF=0;
    TMR1=0;
}

void main(void) {
    GIE=1;
    PEIE=1;
    
    TMR1IE=1;
    TMR1CS=0;
    T1CKPS1=0;
    T1CKPS0=0;
    TMR1ON=1;
    TMR1=0;
    
    TRISB=0x00;
    TRISC=0x04;
    PORTB=0x00;
    PORTC=0x00;
    
    CCP1M0=1;
    CCP1M1=0;    
    CCP1M2=1;
    CCP1M3=0;
    CCP1IE=1;
    
    while(1){}
}