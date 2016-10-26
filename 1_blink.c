#include <stdio.h>
#include <wiringPi.h>

#define	LED 0

int main (void)
{
  printf ("1. Blink an LED at 1Hz\n") ;

  wiringPiSetup () ;
  pinMode (LED, OUTPUT) ;

  while (1) {
    //blink LED at 1Hz 50% duty cycle - 0.5s ON - 0.5s OFF
    digitalWrite (LED, HIGH);	
    delay (500);		
    digitalWrite (LED, LOW);	
    delay (500);
  }

  return 0 ;
}
