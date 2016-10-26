#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <wiringPi.h>

#define	LED1 0
#define	LED2 2

void *blink_led_1Hz(void *ptr);
void *blink_led_5Hz(void *ptr);

main()
{
	pthread_t thread1, thread2;
	char *msg1 = "Starting Thread 1";
	char *msg2 = "Starting Thread 2";
	int  rc1, rc2;

	wiringPiSetup () ;
	pinMode (LED1, OUTPUT) ;
	pinMode (LED2, OUTPUT) ;
	
	// Create two separate threads for each LED	
	rc1 = pthread_create( &thread1, NULL, blink_led_1Hz, (void*) msg1);
	rc2 = pthread_create( &thread2, NULL, blink_led_5Hz, (void*) msg2);
	
	// Join each thread so that both threads finish executing
	// In this case, each thread blinks LEDs for an infinite amount of time for demo purposes  	
	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL); 
	
	printf("Thread 1 done: %d\n", rc1);
	printf("Thread 2 done: %d\n", rc2);
	exit(0);
}



void *blink_led_1Hz( void *msg )
{

	printf("%s \n", (char*)msg);

	while (1) {
		//blink LED at 1Hz 50% duty cycle - 0.5s ON - 0.5s OFF
		digitalWrite (LED1, HIGH);	
		delay (500);		
		digitalWrite (LED1, LOW);	
		delay (500);
	}
}

void *blink_led_5Hz( void *msg )
{

	printf("%s \n", (char*)msg);

	while (1) {
		//blink LED at 5Hz 50% duty cycle - 0.1s ON - 0.1s OFF
		digitalWrite (LED2, HIGH);	
		delay (100);		
		digitalWrite (LED2, LOW);	
		delay (100);
	}
}


