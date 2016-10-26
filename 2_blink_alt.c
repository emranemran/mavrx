#include <stdio.h>
#include <wiringPi.h>

#define	LED 2

int main (void)
{
  printf ("1. Blink an LED at 5Hz\n") ;

  wiringPiSetup () ;
  pinMode (LED, OUTPUT) ;

  while (1) {
    //blink LED at 5Hz 50% duty cycle - 0.1s ON - 0.1s OFF
    digitalWrite (LED, HIGH);	
    delay (100);		
    digitalWrite (LED, LOW);	
    delay (100);
  }

  return 0 ;
}
