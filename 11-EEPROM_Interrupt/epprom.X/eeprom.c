/*
 * File:   eeprom.c
 * Author: aliberkarad
 *
 * Created on 27 Nisan 2022 Çar?amba, 19:31
 */


#include <xc.h>
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)
#define _XTAL_FREQ 4000000      // 4MHZ

int counter=0;

void __interrupt() epprom(){
    
    if(EEIF){
        EEADR=0x02;
        RD=1;
        PORTB=EEDATA;
    }
    EEIF=0;
}

void main(void) {
    EEIE=1;
    
    TRISB=0x00;
    TRISA=0x01;
    PORTB=0x00;
    
    while(1){
        if(RA0){
            while(RA0){}
            counter++;
            EEADR=0x02;
            EEDATA=counter;
            WREN=1;
            EECON2=0x55;
            EECON2=0xAA;
            WR=1;
            GIE=1;
        }
    }
}