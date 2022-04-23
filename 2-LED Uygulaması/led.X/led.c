/*
 * File:   led.c
 * Author: aliberkarad
 *
 * Created on 23 Nisan 2022 Cumartesi, 15:08
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = XT     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

void main(void) {
    
    TRISB = 0x00;
    TRISA = 0x01;
    
    
    while(1){
    
        if(RA0==1){ PORTB=0x0F;}
        else {PORTB=0xF0;}
        
    }
}
