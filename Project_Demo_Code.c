/****************************************************************************
* rp-motor-control.c                                                        *
*                                                                           *
* Uses a Texas Instruments L293D IC to drive a motor in forward and reverse *
*                                                                           *
* Source -> http://www.noveldevices.co.uk/rpdl/rp-motor-control.c           *
*                                                                           *
* Written by JST Lawrence, Novel Devices.                                   *
*                                                                           *
* Notes:                                                                    *
* Uses the L293D Enable/Disable feature to avoid the risk of shorting the   *
* supply. Traps CTRL-C so that outputs are off before the program ends.     *
*                                                                           *
****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>

// Three GPIOs are used
// 1st - Enable/Disable signal
// 2nd - bit 0 of 2-bit signal to control direction
// 3rd - bit 1 of 2-bit signal to control direction

//	Using Pi B+ or B2
int ENABLEPIN1=24; // WiringPi 24, physical 35, GPIO 19
int Motor1_1=27; // WiringPi 27, physical 36, GPIO 16
int Motor1_2=25; // WiringPi 25, physical 37, GPIO 26

int ENABLEPIN2=1; // WiringPi 24, physical 35, GPIO 19
int Motor2_1=4; // WiringPi 27, physical 36, GPIO 16
int Motor2_2=5; // WiringPi 25, physical 37, GPIO 26

int ENABLEPIN3=0; // WiringPi 24, physical 35, GPIO 19
int Motor3_1=2; // WiringPi 27, physical 36, GPIO 16
int Motor3_2=3; // WiringPi 25, physical 37, GPIO 26

int ENABLEPIN4=29; // WiringPi 24, physical 35, GPIO 19
int Motor4_1=26; // WiringPi 27, physical 36, GPIO 16
int Motor4_2=28; // WiringPi 25, physical 37, GPIO 26

const int delayNum = 200;

//Stop Motors
void StopMotors()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(Motor1_1,LOW);
	digitalWrite(Motor1_2,LOW);

	digitalWrite(ENABLEPIN2,LOW);
	digitalWrite(Motor2_1,LOW);
	digitalWrite(Motor2_2,LOW);

	digitalWrite(ENABLEPIN3,LOW);
	digitalWrite(Motor3_1,LOW);
	digitalWrite(Motor3_2,LOW);

	digitalWrite(ENABLEPIN4,LOW);
	digitalWrite(Motor4_1,LOW);
	digitalWrite(Motor4_2,LOW);
}

// Function to trap <CTRL>C
void CatchCTRLC()
{
	StopMotors();
	printf("exiting\n");
	exit(0);
}

// Function to trap "kill" command
void CatchKill()
{
	StopMotors();
	printf("exiting because a kill command was issued\n");
	exit(0);
}
//Forward
void Forward()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(ENABLEPIN2,LOW);
	digitalWrite(ENABLEPIN3,LOW);
	digitalWrite(ENABLEPIN4,LOW);
	
	delay(500);
	digitalWrite(Motor1_1,LOW);
	digitalWrite(Motor1_2,HIGH);
	digitalWrite(ENABLEPIN1,HIGH);
	
	digitalWrite(Motor2_1,LOW);
	digitalWrite(Motor2_2,HIGH);
	digitalWrite(ENABLEPIN2,HIGH);
	
	digitalWrite(Motor3_1,LOW);
	digitalWrite(Motor3_2,HIGH);
	digitalWrite(ENABLEPIN3,HIGH);
	
	digitalWrite(Motor4_1,LOW);
	digitalWrite(Motor4_2,HIGH);
	digitalWrite(ENABLEPIN4,HIGH);
	
	delay(delayNum);
}
// Reverse
void Reverse()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(ENABLEPIN2,LOW);
	digitalWrite(ENABLEPIN3,LOW);
	digitalWrite(ENABLEPIN4,LOW);
	
	delay(delayNum);
	digitalWrite(Motor1_1,HIGH);
	digitalWrite(Motor1_2,LOW);
	digitalWrite(ENABLEPIN1,HIGH);
	
	digitalWrite(Motor2_1,HIGH);
	digitalWrite(Motor2_2,LOW);
	digitalWrite(ENABLEPIN2,HIGH);
	
	digitalWrite(Motor3_1,HIGH);
	digitalWrite(Motor3_2,LOW);
	digitalWrite(ENABLEPIN3,HIGH);
	
	digitalWrite(Motor4_1,HIGH);
	digitalWrite(Motor4_2,LOW);
	digitalWrite(ENABLEPIN4,HIGH);
	
	delay(delayNum);



}

void Turn_Right()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(ENABLEPIN2,LOW);
	digitalWrite(ENABLEPIN3,LOW);
	digitalWrite(ENABLEPIN4,LOW);
	
	delay(delayNum+800);
	digitalWrite(Motor1_1,LOW);
	digitalWrite(Motor1_2,HIGH);
	digitalWrite(ENABLEPIN1,HIGH);
	
	digitalWrite(Motor2_1,LOW);
	digitalWrite(Motor2_2,HIGH);
	digitalWrite(ENABLEPIN2,HIGH);
	
	digitalWrite(Motor3_1,HIGH);
	digitalWrite(Motor3_2,LOW);
	digitalWrite(ENABLEPIN3,HIGH);
	
	digitalWrite(Motor4_1,HIGH);
	digitalWrite(Motor4_2,LOW);
	digitalWrite(ENABLEPIN4,HIGH);
	
	delay(delayNum+800);
}

void Turn_Left()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(ENABLEPIN2,LOW);
	digitalWrite(ENABLEPIN3,LOW);
	digitalWrite(ENABLEPIN4,LOW);
	
	delay(delayNum+800);
	digitalWrite(Motor1_1,HIGH);
	digitalWrite(Motor1_2,LOW);
	digitalWrite(ENABLEPIN1,HIGH);
	
	digitalWrite(Motor2_1,HIGH);
	digitalWrite(Motor2_2,LOW);
	digitalWrite(ENABLEPIN2,HIGH);
	
	digitalWrite(Motor3_1,LOW);
	digitalWrite(Motor3_2,HIGH);
	digitalWrite(ENABLEPIN3,HIGH);
	
	digitalWrite(Motor4_1,LOW);
	digitalWrite(Motor4_2,HIGH);
	digitalWrite(ENABLEPIN4,HIGH);
	
	delay(delayNum+800);
}
int main (int argc, char *argv[])
{
char input;
	wiringPiSetup();

// Set up pins to all OUTPUT
	pinMode(ENABLEPIN1,OUTPUT);
	pinMode(Motor1_1,OUTPUT);
	pinMode(Motor1_2,OUTPUT);

	pinMode(ENABLEPIN2,OUTPUT);
	pinMode(Motor2_1,OUTPUT);
	pinMode(Motor2_2,OUTPUT);

	pinMode(ENABLEPIN3,OUTPUT);
	pinMode(Motor3_1,OUTPUT);
	pinMode(Motor3_2,OUTPUT);

	pinMode(ENABLEPIN4,OUTPUT);
	pinMode(Motor4_1,OUTPUT);
	pinMode(Motor4_2,OUTPUT);

	// Set up to catch <CTRL>C and "kill"
	signal(SIGINT,CatchCTRLC);
	signal(SIGTERM,CatchKill);

	while(1)
	{
// Forward
		input = getchar();
		printf("Input now contains the number %c . \n", input);
	
		switch(input)
		{
			case 'w':
			Forward();
			StopMotors();
			break;	

			case 's':
			Reverse();
			StopMotors();
			break;

			case 'a':
			Turn_Left();
			StopMotors();
			break;

			case 'd':
			Turn_Right();	
			StopMotors();
			break;

			case 'c':
			system("/home/pi/Documents/Project/RobotCar/CameraPic.sh"); 
			break;

			case 't':
			system("/home/pi/Documents/Project/RobotCar/SendEmail.sh");
			break;

			default:
			break;	
		}

	}
	
	return 0 ;
}
