#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>

// Three GPIOs are used
// 1st - Enable/Disable signal
// 2nd - bit 0 of 2-bit signal to control direction
// 3rd - bit 1 of 2-bit signal to control direction

//	Using Pi B+ or B2
int EnablePin1=1; // WiringPi 24, physical 35, GPIO 19
int Motor1_1=4; // WiringPi 27, physical 36, GPIO 16
int Motor1_2=5; // WiringPi 25, physical 37, GPIO 26

int EnablePin2=21; // WiringPi 24, physical 35, GPIO 19
int Motor2_1=22; // WiringPi 27, physical 36, GPIO 16
int Motor2_2=23; // WiringPi 25, physical 37, GPIO 26

void Turn_Left()
{
	digitalWrite(EnablePin1,LOW);
	digitalWrite(EnablePin2,LOW);

	digitalWrite(Motor1_1,LOW);
	digitalWrite(Motor1_2,HIGH);
	digitalWrite(EnablePin1,HIGH);

	digitalWrite(Motor2_1,HIGH);
	digitalWrite(Motor2_2,LOW);
	digitalWrite(EnablePin2,HIGH);

}

int main (int argc, char *argv[])
{
char input;
	wiringPiSetup();

// Set up pins to all OUTPUT
	pinMode(EnablePin1,OUTPUT);
	pinMode(Motor1_1,OUTPUT);
	pinMode(Motor1_2,OUTPUT);

	pinMode(EnablePin2,OUTPUT);
	pinMode(Motor2_1,OUTPUT);
	pinMode(Motor2_2,OUTPUT);

	Turn_Left();
	return 0 ;
}
