import P3picam
import picamera
from datetime import datetime
from subprocess import call

MotionState = False
PicPath = "/home/pi/MotionDectionPi/Images/"

def CaptureImage(currentTime,PicPath):
        #Generate the .jpg name
        PicName = currentTime.strftime("%Y.%m.%d-%H%M%S") + '.jpg'
        with picamera.PiCamera() as camera:
                camera.resolution = (1280,720)
                camera.capture(PicPath + PicName)
        print("Picture Taken!")
        return PicName

def GetTime():
        #Fetch Current Time
        currentTime = datetime.now()
        return currentTime

#TimeStamp function
#def TimeStamp(currentTime,PicPath, PicName):
#        #Variable for file path
#        filePath = PicPath + PicName
#        #Create message to stamp on picture
#        message = currentTime.strftime("%Y.%m.%d - %H:%M:%S")
#        #Create cmd to execute
#        timeStampCmd =  filePath + " -pointsize 36 \
#        -fill red -annotate +700+650 '" + message + "' " + filePath
#        #Execute the Command using subprocess 'Call'
#        call([timeStampCmd], shell=True)
#        print("we have timestamped our picture")
while True:
        MotionState = P3picam.motion()
        print(MotionState)
        if MotionState:
                currentTime = GetTime()
		CaptureImage(currentTime, PicPath)
#Following lines of code are for timestamp
                #PicName = CaptureImage(currentTime, PicPath)
                #TimeStamp(currentTime, PicPath , PicName)
                          
