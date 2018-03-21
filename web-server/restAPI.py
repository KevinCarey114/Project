#!flask/bin/python
import sys 
sys.path.insert(0,"/usr/local/lib/python3.4/dist-packages")
from flask import Flask, jsonify, request
from flask_cors import CORS, cross_origin
import RPi.GPIO as GPIO
import subprocess 

app = Flask(__name__)
CORS(app)
@app.route('/todo/api/v1.0/tasks', methods=['POST'])
def get_tasks():
    print(sys.path)
    dir = request.args.get('direction')
    if dir == 'up':
        subprocess.Popen(['/home/pi/MoveRobotCommands/Forward'], shell = True)	
    if dir == 'down':
        subprocess.Popen(['/home/pi/MoveRobotCommands/Reverse'], shell = True)	
    if dir == 'left':
        subprocess.Popen(['/home/pi/MoveRobotCommands/TurnLeft'], shell = True)	
    if dir == 'right':
        subprocess.Popen(['/home/pi/MoveRobotCommands/TurnRight'], shell = True)	 
    return dir

if __name__ == '__main__':
    app.run(host='0.0.0.0',port = 5001)

