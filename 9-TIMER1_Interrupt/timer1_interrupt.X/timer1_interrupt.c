/*
 * File:   timer1_interrupt.c
 * Author: aliberkarad
 *
 * Created on 25 Nisan 2022 Pazartesi, 18:26
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

void __interrupt() t1(void){
    if(TMR1IF){
        count++;
        if(count==20){
            count=0;
            RB0=RB0^1; // XOR   
        }
    }
    TMR1IF=0;
    TMR1=15536;
}
void main(void) {
    GIE=1;                      // Global Interrupts Flag
    PEIE=1;                     // Environmental Interrupts ON 
    TMR1IE=1;                   // TIMER1 permission Enabled
    T1CKPS1=0;                  // divison ratio for 1sec
    T1CKPS0=0;                  // divison ratio for 1sec
    TMR1CS=0;                   // TIMER1 timer mode not counter 
    TMR1ON=1;                   // TIMER1 ON
    TMR1=15536;                 // TIMER1 Set Value
    
    TRISB=0x00;
    PORTB=0x00;
    
    while(1){
        
    }
}
