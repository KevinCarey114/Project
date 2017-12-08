
#!/bin/bash
DATE=$(date +"%Y-%m-%d_%H%M")
raspistill -t 50 -o /home/pi/Documents/Project/RobotCar/CamPic$DATE.jpg -n -w 400 -h 480

/home/pi/./Dropbox-Uploader/dropbox_uploader.sh upload "/home/pi/Documents/Project/RobotCar/CamPic$DATE.jpg" /Project/Surveilance-Pictures
