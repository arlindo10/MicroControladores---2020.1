/*
 * File:   SEMAFORO.c
 * Author: Arlindo
 *
 */

#include <p18F4550.h>
#include <delays.h>
#pragma config FOSC = HS
#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF //Desabilita o Watchdog Timer (WDT).
#pragma config PWRT = ON //Habilita o Power-up Timer (PWRT).
#pragma config BOR = ON  //Brown-out Reset (BOR) habilitado somente no hardware.   
#pragma config BORV = 1    //Voltagem do BOR é 4,33V.
#pragma config PBADEN = OFF   //RB0,1,2,3 e 4 configurado como I/O digital.
#pragma config LVP = OFF   //Desabilita o Low Voltage Program.
   
#define semaforo PORTD
#define vd_1 0b00100001
#define am_1 0b00010001
#define vm_1 0b00001001

#define vd_2 0b00001100
#define am_2 0b00001010
#define vm_2 0b00001001


void main(void) {
  
  TRISD = 0b00000000; 
  


  while(1)
  {
      semaforo = vd_1;
      Delay10KTCYx(200);
      
      semaforo = am_1;
      Delay10KTCYx(200);
      
      semaforo = vm_1;
      Delay10KTCYx(200);
      
      
      
      semaforo = vd_2;
      Delay10KTCYx(200);
      
      semaforo = am_2;
      Delay10KTCYx(200);
      
      semaforo = vm_2;
      Delay10KTCYx(200);
  }
  
    return;
}
