/*
 * File:   interrupt.c
 * Author: aliberkarad
 *
 * Created on 23 Nisan 2022 Cumartesi, 18:07
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

    if(RBIF==1 && (RB4==1 || RB5==1 ||RB6==1 || RB7==1)){
        RA0=1;
        __delay_ms(5000);
        RA0=0;
    }
    RBIF=0;
}


void main(void) {
    GIE=1;
    RBIE=1;
    TRISB=0xF0;
    TRISA=0;
    PORTA=0;
    
    while(1){
        RB1=0;__delay_ms(500);
        RB1=1;__delay_ms(500);
    }
}
