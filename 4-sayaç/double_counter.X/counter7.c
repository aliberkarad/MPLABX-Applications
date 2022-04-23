/*
 * File:   counter7.c
 * Author: aliberkarad
 *
 * Created on 23 Nisan 2022 Cumartesi, 16:15
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

int dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};
int birler=0,onlar=0,sayi=0;

void main(void) {
    
    TRISA = 0x00;
    TRISB = 0x00;
    PORTB = 0;
    PORTA = 0x03;

    while(1){
    
        for(onlar=0;onlar<10;onlar++){
            for(birler=0;birler<10;birler++){
                    RA0=0;RA1=1;
                    PORTB=dizi[birler];
                    __delay_ms(50);

                    RA0=1;RA1=0;
                    PORTB=dizi[onlar];
                    __delay_ms(50);
            }
        }        
            
               
    }



    
//    while(1){
//    
//        birler=sayi%10;
//        onlar=sayi/10;
//        
//        RA0=0;
//        PORTB=dizi[birler];
//        __delay_ms(50);
//        RA0=1;
//        
//        RA1=0;
//        PORTB=dizi[onlar];
//        __delay_ms(50);
//        RA1=1;
//        
//        sayi++;
//        if(sayi==100)sayi=0;
//    }
    
}
