#!/bin/bash 
for((i=1;i<10;i++))
do
sudo /home/pi/Dropbox-Uploader/dropbox_uploader.sh -s -q delete /ProjectImages/MotionCaptured$i.png
done
for((i=1;i<10;i++))
do
	sudo /home/pi/Dropbox-Uploader/dropbox_uploader.sh -s -q upload /home/pi/web-server/Video-Stream/static/MotionCaptured$i.png /ProjectImages/
done