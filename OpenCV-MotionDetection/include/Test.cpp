#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Test.hpp"
#include "camLib.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int test()
{
        char path[255];
        char num[10];
        char png[10] = ".png";
        int counter = 1;
	int PicCounter = 0;
	// Create a camera instance...
	Camera cam1;
	int number_of_changes = 0;
	const int frameBuffer = 50;	// Frame buffer around motion ...
	const int lengthThreshold = 5;	// How many frames in a sequence need to show motion...
	// if more than 'there_is_motion' pixels are changed, we say there is motion...
	// and store the image...
	int there_is_motion = 5;
	int frameCounter = 0;		// Counter for frames...
	int frameSequence = 0;		// Count sequence of frames...
	int framesTotal = 0;		// Total number fa frames containing motion -- for saving...
	Mat frame;			// Captured single frames...
	int framesize;			// size of a frame...	
	time_t seconds;
	struct tm * timeinfo;
	char detectionfile[80];
	
	// Start endless loop to capture frames...
	// This endless loop is stopped by user pressing the ESC key...
	// Generate new file name with a time-stamp right after the sequence that was captures
	while(1)
{
       // Display the resulting frames... 
       frame = cam1.captureVideo();			// Capture a frame from the live stream of camera...
       framesize = sizeof(frame);

	if(frameCounter < frameBuffer)	
	{	
		frameCounter++;					// Count frames...
		framesTotal++;
		PicCounter++;
		// Only if there are more than 'there_is_motion' in the image
		// Ais it accepted that there is motion..
		number_of_changes = cam1.detectMotion();
		if(number_of_changes >= there_is_motion)
		{
			cout << "...Motion Detected..." << "frameTotal= " << framesTotal <<"   FrameCounter ="<< frameCounter << endl;
	        if(PicCounter > 20) {
		        strcpy(path, "/home/pi/web-server/Video-Stream/static/MotionCaptured");
		        sprintf(num, "%i", counter);
		        strcat(path, num);   
		        strcat(path, png);
			cout << "Picture Taken!..." << counter << "...." << endl;
		        imwrite(path, frame);
	        	counter++;
			PicCounter = 0;	
        	}
			frameSequence++;
			// Need a minimum amount of frames in a sequence showing motion...
			// Was motion detected over multiple frames...?
			if(frameSequence > lengthThreshold)  {		
				frameCounter = 0;		// Reset the frame-counter, so that more frames are captured after the motion detection...
			}
		}
		else{							// If not enough motion detected, then reset the counter...
			// Reset...
			frameSequence = 0;
		}
	}
	else  {						// In case no motion was detected, discard the images collected on the stack...
		frameCounter = 0;
		frameSequence = 0;
		PicCounter = 0;
		cout <<".....No Motion Detected....." << endl;
		}

		if (waitKey(30) == 27) 		//wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			//system("sudo /home/pi/ForLoop.sh");
			cout << "esc key is pressed by user" << endl;
            break; 
		}
    }
	return 0;
}

int test2()
{        
    return 0;
}