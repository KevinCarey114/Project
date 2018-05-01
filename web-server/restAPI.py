#!flask/bin/python
import sys 
sys.path.insert(0,"/usr/local/lib/python3.4/dist-packages")
from flask import Flask, jsonify, request
from flask_cors import CORS, cross_origin
import RPi.GPIO as GPIO
import time
import subprocess 
from subprocess import call


subprocess.Popen(['sudo python /home/pi/web-server/Video-Stream/app.py'], shell = True)

app = Flask(__name__)
CORS(app)
@app.route('/Controls', methods=['POST'])
def get_tasks():
    dir = request.args.get('direction')
    if dir == 'up':
        subprocess.Popen(['/home/pi/MoveRobotCommands/newForward'], shell = True)	
    if dir == 'stop':
        subprocess.Popen(['/home/pi/MoveRobotCommands/StopMotors'], shell = True)
    if dir == 'down':
        subprocess.Popen(['/home/pi/MoveRobotCommands/Reverse'], shell = True)	
    if dir == 'left':
        subprocess.Popen(['/home/pi/MoveRobotCommands/TurnLeft'], shell = True)	
    if dir == 'right':
        subprocess.Popen(['/home/pi/MoveRobotCommands/TurnRight'], shell = True)	 
    return dir
@app.route('/CaptureImage', methods=['POST'])
def get_image():
    #capture image
    time.sleep(8)
    subprocess.Popen(['/home/pi/OpencvC++/imageCapture'], shell = True)
    time.sleep(5)
    return "{}"

@app.route('/CaptureVideo', methods=['POST'])
def get_Video():
    #capture Video
    time.sleep(8)
    subprocess.Popen(['/home/pi/OpencvC++/ExecVidFile'], shell = True)
    time.sleep(60)
    return "{}"

if __name__ == '__main__':
    app.run(host='0.0.0.0',port = 5001)

