/*
 * File:   compare.c
 * Author: aliberkarad
 *
 * Created on 29 Nisan 2022 Cuma, 15:43
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

void __interrupt() compare(void){
    if(CCP1IF){
        RC2=RC2^1;
    }
    CCP1IF=0;
}

void main(void) {
    GIE=1;
    PEIE=1;
    
    TMR1IE=1;
    TMR1CS=1;
    T1OSCEN=1;
    TMR1ON=1;
    TMR1=1;
    
    TRISC=0x01;
    PORTC=0x00;
    
    CCP1M3=1;
    CCP1M2=0;
    CCP1M1=1;
    CCP1M0=1;
    CCP1IE=1;
    CCPR1=5;
    
    while(1){}
}
