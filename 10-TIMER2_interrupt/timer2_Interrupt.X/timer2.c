/*
 * File:   timer2.c
 * Author: aliberkarad
 *
 * Created on 25 Nisan 2022 Pazartesi, 18:58
 */


#include <xc.h>
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low Voltage In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON         // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)
#define _XTAL_FREQ 4000000      // 4MHZ EXT CRYSTAL

int count=0;

void __interrupt() t2(void){
    if(TMR2IF){
        count++;
        if(count==10){
            count=0;
            RB0=RB0^1;
        }
    }
    TMR2=0;
    TMR2IF=0;
}
void main(void) {
    GIE=1;                      // Global Interrupt Flag
    PEIE=1;                     // Enviromental Flag
    TMR2IE=1;                   // TIMER2 Flag
    TMR2ON=1;                   // TIMER2 Enabled
    
    T2CKPS1=1;                  // Division
    T2CKPS0=1;                  // Ratio
    
    TOUTPS3=1;                  // Pre 
    TOUTPS2=1;                  // and
    TOUTPS1=1;                  // End 
    TOUTPS0=1;                  // Scale
    
    TMR2=0;                     // TIMER2 Set Value
    
    TRISB=0x00;                  
    PORTB=0x00;                  
    
    while(1){}
}
