import RPi.GPIO as gpio
import time

def init():
	gpio.setmode(gpio.BOARD)
	gpio.setup(7, gpio.OUT)
	gpio.setup(11, gpio.OUT)
	gpio.setup(13, gpio.OUT)
	gpio.setup(15, gpio.OUT)

def forward(tf):
	init()
	gpio.output(7 , False)
	gpio.output(11 , True)
	gpio.output(13 , True)	
	gpio.output(15 , False)
	time.sleep(tf)
	gpio.cleanup()

def reverse(tf):
	init()
	gpio.output(7 , True)
	gpio.output(11 , False)
	gpio.output(13 , False)	
	gpio.output(15 , True)
	time.sleep(tf)
	gpio.cleanup()
	
##forward(2)
##reverse(2)

def turn_left(tf):
	init()
	gpio.output(7 , True)
	gpio.output(11 , True)
	gpio.output(13 , True)	
	gpio.output(15 , False)
	time.sleep(tf)
	gpio.cleanup()

def turn_right(tf):
	init()
	gpio.output(7 , False)
	gpio.output(11 , True)
	gpio.output(13 , False)	
	gpio.output(15 , False)
	time.sleep(tf)
	gpio.cleanup()

def pivot_left(tf):
	init()
	gpio.output(7 , True)
	gpio.output(11 , False)
	gpio.output(13 , True)	
	gpio.output(15 , False)
	time.sleep(tf)
	gpio.cleanup()


def pivot_right(tf):
	init()
	gpio.output(7 , False)
	gpio.output(11 , True)
	gpio.output(13 , False)	
	gpio.output(15 , True)
	time.sleep(tf)
	gpio.cleanup()

pivot_right(1)