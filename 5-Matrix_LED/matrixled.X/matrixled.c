/*
 * File:   matrixled.c
 * Author: aliberkarad
 *
 * Created on 23 Nisan 2022 Cumartesi, 17:02
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

int i,j,k;
int satir[2][5]={0x03,0x3A,0x3B,0x3A,0x03,
                 0x40,0x5E,0x1E,0x5E,0x5E};
//int sutun[]={0x01,0x02,0x04,0x08,0x10};


void main(void) {
    
    TRISB=0;
    TRISC=0;
    
    while(1){
        for(k=0;k<2;k++){
            for(j=0;j<100;j++){
                PORTC=1;
                for(i=0;i<5;i++){
                    PORTB=satir[k][i];
                    __delay_ms(5);
                    PORTC=PORTC<<1;
                }
            }
        }
    }
    
}
