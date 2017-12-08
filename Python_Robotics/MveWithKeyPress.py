import RPi.GPIO as gpio
import time,sys, tty, termios
import Tkinter as tk

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

def turn_left(tf):
	init()
	gpio.output(7 , True)
	gpio.output(11 , False)
	gpio.output(13 , True)	
	gpio.output(15 , False)
	time.sleep(tf)
	gpio.cleanup()

def turn_right(tf):
	init()
	gpio.output(7 , False)
	gpio.output(11 , True)
	gpio.output(13 , False)	
	gpio.output(15 , True)
	time.sleep(tf)
	gpio.cleanup()
	
##Forward(1)
##Reverse(1.5)

def key_input(event):
	init()
	print 'Key:', event.char
	key_press = event.char
	sleep_time = 0.030

	if key_press.lower() == 'w':
		Forward(sleep_time)

	elif key_press.lower() == 's':
		Reverse(sleep_time)

	elif key_press.lower() == 'a':
		turn_left(sleep_time)

	elif key_press.lower() == 'd':
		turn_right(sleep_time)

	else:
		gpio.cleanup()

command = tk.Tk()
command.bind('<KeyPress>', key_input)
command.mainloop()
