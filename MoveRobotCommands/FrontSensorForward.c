/*
 *  hc-sr04.c:
 *	Simple test program to test the wiringPi functions
 */

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int ENABLEPIN1=1; // WiringPi 24, physical 35, GPIO 19
int Motor1_1=4; // WiringPi 27, physical 36, GPIO 16
int Motor1_2=5; // WiringPi 25, physical 37, GPIO 26


int ENABLEPIN2=21; // WiringPi 24, physical 35, GPIO 19
int Motor2_1=22; // WiringPi 27, physical 36, GPIO 16
int Motor2_2=23; // WiringPi 25, physical 37, GPIO 26

#define TRIG1 29  
#define ECHO1 28
#define TRIG2 27  
#define ECHO2 26

const int delayNum = 200;
void setup() 
{
        wiringPiSetup();


	// Set up pins to all OUTPUT
	pinMode(ENABLEPIN1,OUTPUT);
	pinMode(Motor1_1,OUTPUT);
	pinMode(Motor1_2,OUTPUT);

	pinMode(ENABLEPIN2,OUTPUT);
	pinMode(Motor2_1,OUTPUT);
	pinMode(Motor2_2,OUTPUT);

	pinMode(TRIG1, OUTPUT);
	pinMode(ECHO1, INPUT);
	pinMode(TRIG2, OUTPUT);
	pinMode(ECHO2, INPUT);

}
//Stop Motors
void StopMotors()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(Motor1_1,LOW);
	digitalWrite(Motor1_2,LOW);


	digitalWrite(ENABLEPIN2,LOW);
	digitalWrite(Motor2_1,LOW);
	digitalWrite(Motor2_2,LOW);
}

//Forward
void Forward()
{
	long ping       = 0;
	long pong       = 0;
	float distance  = 0;
 	long timeout    = 500000; // 0.5 sec ~ 171 m
	
	// Ensure trigger is low.
	digitalWrite(TRIG1, LOW);
	delay(50);
	
	// Trigger the ping.
	digitalWrite(TRIG1, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG1, LOW);

	
	// Wait for ping response, or timeout.
	while (digitalRead(ECHO1) == LOW );
	
	
	ping = micros();
	
	// Wait for pong response, or timeout.
	while (digitalRead(ECHO1) == HIGH );
	
	pong = micros();

	// Convert ping duration to distance.
	distance = (float) (pong - ping) * 0.017150;
	printf("Sensor %.2f cm.\n",distance);
	if(distance > 20){
		digitalWrite(ENABLEPIN1,LOW);
		digitalWrite(ENABLEPIN2,LOW);
	
		digitalWrite(Motor1_1,LOW);
		digitalWrite(Motor1_2,HIGH);
		digitalWrite(ENABLEPIN1,HIGH);
	
		digitalWrite(Motor2_1,LOW);
		digitalWrite(Motor2_2,HIGH);
		digitalWrite(ENABLEPIN2,HIGH);
		printf("Sensor %.2f cm.\n",distance);
	}
	else{
		StopMotors();
	}

}
int FrontSensor()
{
	long ping       = 0;
	long pong       = 0;
	float distance  = 0;
 	long timeout    = 500000; // 0.5 sec ~ 171 m
	
	// Ensure trigger is low.
	digitalWrite(TRIG1, LOW);
	delay(50);
	
	// Trigger the ping.
	digitalWrite(TRIG1, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG1, LOW);

	
	// Wait for ping response, or timeout.
	while (digitalRead(ECHO1) == LOW );
	
	
	ping = micros();
	
	// Wait for pong response, or timeout.
	while (digitalRead(ECHO1) == HIGH );
	
	pong = micros();

	// Convert ping duration to distance.
	distance = (float) (pong - ping) * 0.017150;
	printf("Sensor %.2f cm.\n",distance);
	//return distance;
}
int main (int argc, char *argv[])
{
	setup();
	Forward();	
	return 0;

}

