/*
 * File:   interrupt.c
 * Author: aliberkarad
 *
 * Created on 23 Nisan 2022 Cumartesi, 17:47
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
#define _XTAL_FREQ 4000000


void __interrupt() kesme(void){
    if(INTF){
        PORTA=1;
        __delay_ms(2000);
        PORTA=0;
    }
    INTF=0;
}

void main(void) {
    GIE=1;
    INTE=1;
    TRISB=1;
    TRISA=0;
    PORTA=0;
    
    while(1){
        RB1=0;
        __delay_ms(500);
        RB1=1;
        
        RB2=0;
        __delay_ms(500);
        RB2=1;
    }
}
