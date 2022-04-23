/*
 * File:   display.c
 * Author: aliberkarad
 *
 * Created on 23 Nisan 2022 Cumartesi, 15:43
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = XT     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

int dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7f,0x6f};
void main(void) {
    TRISB=0x00;
    PORTB=0x00;
    while(1){
    
        for(int i=0;i<10;i++){
        
            PORTB=dizi[i];
            __delay_ms(500);
        }
    }
}
