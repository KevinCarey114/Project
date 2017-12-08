import RPi.GPIO as gpio
import time

def init():
	gpio.setmode(gpio.BOARD)
	gpio.setup(7, gpio.OUT)
	gpio.setup(11, gpio.OUT)
	gpio.setup(13, gpio.OUT)
	gpio.setup(15, gpio.OUT)

def Reverse(tf):
	init()
	gpio.output(7 , False)
	gpio.output(11 , True)
	gpio.output(13 , True)	
	gpio.output(15 , False)
	time.sleep(tf)
	gpio.cleanup()

def Forward(tf):
	init()
	gpio.output(7 , True)
	gpio.output(11 , False)
	gpio.output(13 , False)	
	gpio.output(15 , True)
	time.sleep(tf)
	gpio.cleanup()
	
Forward(1)
Reverse(1.5)