
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
 
#define vm2 PORTDbits.RD0
#define am2 PORTDbits.RD1
#define vd2 PORTDbits.RD2
#define vm1 PORTDbits.RD3
#define am1 PORTDbits.RD4
#define vd1 PORTDbits.RD5
#define vd3 PORTDbits.RD6
#define vm3 PORTDbits.RD7
#define chave PORTBbits.RB0
#pragma code int_h = 0x000008 //vetor de interrupção de baixa prioridade
#pragma interrupt INT_EXT0 /*define a função INT_EXT0 como rotina de
 ....tratamento da interrupção externa*/
void INT_EXT0(void) //função INT_TEXT0
{
 INTCONbits.INT0IF = 0; //Limpa o flag de interrupção externa
 //PORTD = ~PORTD; //inverte o estado da PORTA D
vm2 = 1; am2 = 0; vd2 = 0; vm1 = 1; am1 = 0; vd1 = 0;vd3 = 1;vm3 =0;
	Delay10KTCYx(200);
}

void main(void) {
    
  TRISD = 0b00000000;
  TRISB = 0b00000001;
  INTCONbits.INT0IE = 1; //Habilita interrupção externa INT0
  INTCON2bits.INTEDG0 = 0; //Habilita interrupção na borda de descida
  INTCONbits.GIE = 1; //Habilita todas as interrupções
    while(1)
 {
      
        vm2 = 1; am2 = 0; vd2 = 0; vm1 = 0; am1 = 0; vd1 = 1;vd3 = 0;vm3 =1;
  
        Delay10KTCYx(200);
        
        vm2 = 1; am2 = 0; vd2 = 0; vm1 = 0; am1 = 1; vd1 = 0;vd3 = 0;vm3 =1;
  
        Delay10KTCYx(200);
        
       
       vm2 = 1; am2 = 0; vd2 = 0; vm1 = 1; am1 = 0; vd1 = 0;vd3 = 0;vm3 =1;
       Delay10KTCYx(200);


        Delay10KTCYx(200);
        
        vm2 = 0; am2 = 0; vd2 = 1; vm1 = 1; am1 = 0; vd1 = 0;vd3 = 0;vm3 =1;
  
        Delay10KTCYx(200);
        
        vm2 = 0; am2 = 1; vd2 = 0; vm1 = 1; am1 = 0; vd1 = 0;vd3 = 0;vm3 =1;
  
        Delay10KTCYx(200);
        
        vm2 = 1; am2 = 0; vd2 = 0; vm1 = 1; am1 = 0; vd1 = 0;vd3 = 0;vm3 =1;
  
     
       // vm2 = 1; am2 = 0; vd2 = 0; vm1 = 1; am1 = 0; vd1 = 0;vd3 = 1;vm3 =0;
       // Delay10KTCYx(200);
	
        
        vm2 = 1; am2 = 0; vd2 = 0; vm1 = 1; am1 = 0; vd1 = 0;vd3 = 0;vm3 =1;
        Delay10KTCYx(200);

       
       
        
      
      
   }
      
          
      
    return;
}
