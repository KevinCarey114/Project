#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include <time.h>

//	Using Pi B+ or B2
int ENABLEPIN1=24; // WiringPi 24, physical 35
int Motor1_1=27; // WiringPi 27, physical 36
int Motor1_2=25; // WiringPi 25, physical 37

int ENABLEPIN2=1; // WiringPi 1, physical 12 
int Motor2_1=4; // WiringPi 4, physical 16
int Motor2_2=5; // WiringPi 5, physical 18


#define TRIG 0  // WiringPi 0, physical 11
#define ECHO 2  // WiringPi 2, physical 13

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
	
	delay(500);
	digitalWrite(Motor1_1,LOW);
	digitalWrite(Motor1_2,HIGH);
	digitalWrite(ENABLEPIN1,HIGH);
	
	digitalWrite(Motor2_1,LOW);
	digitalWrite(Motor2_2,HIGH);
	digitalWrite(ENABLEPIN2,HIGH);
	

	
	delay(delayNum);
}
// Reverse
void Reverse()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(ENABLEPIN2,LOW);
	
	delay(delayNum);
	digitalWrite(Motor1_1,HIGH);
	digitalWrite(Motor1_2,LOW);
	digitalWrite(ENABLEPIN1,HIGH);
	
	digitalWrite(Motor2_1,HIGH);
	digitalWrite(Motor2_2,LOW);
	digitalWrite(ENABLEPIN2,HIGH);
	
	delay(delayNum);



}

void Turn_Left()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(ENABLEPIN2,LOW);

	delay(delayNum+800);
	digitalWrite(Motor1_1,LOW);
	digitalWrite(Motor1_2,HIGH);
	digitalWrite(ENABLEPIN1,HIGH);
	
	digitalWrite(Motor2_1,LOW);
	digitalWrite(Motor2_2,HIGH);
	digitalWrite(ENABLEPIN2,HIGH);
	
	delay(delayNum+800);
}

void Turn_Right()
{
	digitalWrite(ENABLEPIN1,LOW);
	digitalWrite(ENABLEPIN2,LOW);

	
	delay(delayNum+800);
	digitalWrite(Motor1_1,HIGH);
	digitalWrite(Motor1_2,LOW);
	digitalWrite(ENABLEPIN1,HIGH);
	
	digitalWrite(Motor2_1,HIGH);
	digitalWrite(Motor2_2,LOW);
	digitalWrite(ENABLEPIN2,HIGH);
	
	
	delay(delayNum+800);
}

void RandomNum(){
	
int num = 0;
printf("\n%d",num);
	while(num != 10)
	{
		srand(time(NULL));
		int a = 1 + rand() % 10;
		if(a == 1){
		printf("\nForward");
		Forward();
		StopMotors();
		num++;
		}
		else if(a == 2){
		printf("\nReverse");
		Reverse();
		StopMotors();
		num++;
		}
		else if(a == 3){
		printf("\nReverse");
		Reverse();
		StopMotors();
		num++;
		}
		else if(a == 4){
		printf("\nTurnLeft");
		Turn_Left();
		StopMotors();
		num++;
		}
		else if(a == 5){
		printf("\nTurnRight");
		Turn_Right();
		StopMotors();
		num++;
		}
		else if(a == 7){
		printf("\nForward");
		Forward();
		StopMotors();
		num++;
		}
		delay(1000);
		
	}
	num = 0;
	printf("\n%d",num);
	
}

int getCM() {
        //Send trig pulse
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG, LOW);
 
        //Wait for echo start
        while(digitalRead(ECHO) == LOW);
 
        //Wait for echo end
        long startTime = micros();
        while(digitalRead(ECHO) == HIGH);
        long travelTime = micros() - startTime;
 
        //Get distance in cm
        int distance = travelTime / 58;
 
        return distance;
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

	pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
 
        //TRIG pin must start LOW
        digitalWrite(TRIG, LOW);
        delay(30);

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
				if(getCM() <5){
					
					printf("Front Too Close To Object");
					printf("Turning Left");
					Turn_Left();
					StopMotors();
				}
				else{
					Forward();
					StopMotors();
				}	
				break;	

			case 's':
				if(getCM() <5){
					printf("Rear Too Close To Object");
					printf("Turning Right");
					Turn_Right();
					StopMotors();
				}
				else{
					Reverse();
					StopMotors();
				}	
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
				system("/home/pi/Documents/Project/CameraPic.sh"); 
				break;

			case 't':
				system("bash /home/pi/Documents/Project/SendEmail.sh");
				break;

			case 'y':
				system("python /home/pi/Documents/Project/SenorCodePython/sensor.py");	
				break;
			case 'z':
				RandomNum();
				break;

			case 'p':
				printf("Distance: %dcm\n", getCM());
				
				break;
			default:
				break;	
		}

	}
	
	return 0 ;
}