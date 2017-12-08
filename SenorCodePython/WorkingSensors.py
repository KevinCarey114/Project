############################################################
##This Program Keeps track on how close an abject is from the sensors
##if the object is under 20cm from the sensors it will print a message
## to the command line and will keep printing the message if it is still
## too close to the sensor until the object is further then 20 cm.
##updated code to send a picture of the object via the users Dropbox
##if the sesnors are too close to the object.
##A Another Script 'CameraPic.sh' is added to the program to allow to take a snip of the object 
##infront of the sensor. 
############################################################

import time
import RPi.GPIO as GPIO
import os

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
timeout = 0.020
timeout1 = 0.020

import subprocess

Frontcount=0
Rearcount=0

 
while 1:
        GPIO.setup(11, GPIO.OUT)
        #cleanup output
        GPIO.output(11, 0)

        time.sleep(1)

        #send signal
        GPIO.output(11, 1)

        time.sleep(0.75)

        GPIO.output(11, 0)

        GPIO.setup(11, GPIO.IN)
        
        goodread=True
        watchtime=time.time()
        while GPIO.input(11)==0 and goodread:
                starttime=time.time()
                if (starttime-watchtime > timeout):
                        goodread=False

        if goodread:
                watchtime=time.time()
                while GPIO.input(11)==1 and goodread:
                        endtime=time.time()
                        if (endtime-watchtime > timeout):
                                goodread=False
        
       
			
########################################################################
####################### BACK SENSOR CODE ###############################
########################################################################			
########################################################################
	
	GPIO.setup(13, GPIO.OUT)
        #cleanup output
        GPIO.output(13, 0)

        time.sleep(1)

        #send signal
        GPIO.output(13, 1)

        GPIO.output(13, 0)

        GPIO.setup(13, GPIO.IN)
        
        goodread1=True
        watchtime1=time.time()
        while GPIO.input(13)==0 and goodread1:
                starttime1=time.time()
                if (starttime1-watchtime1 > timeout1):
                        goodread1=False

        if goodread1:
                watchtime1=time.time()
                while GPIO.input(13)==1 and goodread1:
                        endtime1=time.time()
                        if (endtime1-watchtime1 > timeout1):
                                goodread1=False

	if goodread:
                duration=endtime-starttime
                distance=duration*34000/2
                

		if distance < 25:
			print('Front End Too Close ', distance)
			while Frontcount !=1:
				os.system("/home/pi/Documents/Project/Robotics/CameraPic.sh , shell=True")
				Frontcount += 1
				print(Frontcount)
				break
		else:
			print ('Front End', distance)
			Frontcount=0
	
        
        if goodread1:
                duration1=endtime1-starttime1
                distance1=duration1*34000/2
                

		if distance1 < 25:
			print('Rear End Too Close ', distance1)
			while Rearcount !=1:
				os.system("/home/pi/Documents/Project/Robotics/CameraPic.sh , shell=True")
				Rearcount += 1
				print(Rearcount)
				break
		else:
			print ('Rear End', distance1)
			Rearcount=0
			

