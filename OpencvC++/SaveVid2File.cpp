/*
The Following Code will record when the script is running and will save a recording of it 
when the user ends the script using the escape key. the recording will be then saved to the pi 
*/

#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	string filename ="/home/pi/OpencvC++/SaveImagetoPi/output.avi";
	int fcc =CV_FOURCC('M','J','P','G');
	int fps = 10;
    cv::VideoCapture cap(0); 
        if(!cap.isOpened())
        {
            cout << "Cannot seem to open the file" << endl;
            return -1;
        }

    int frame_width=   cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height=  cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    cv::VideoWriter video(filename,fcc,fps, cv::Size(frame_width,frame_height),true);

    for(;;)
        {
            cv::Mat frame;
            cap >> frame;
            video.write(frame);
            cv::imshow( "Video Frame", frame );

            char c = (char)cv::waitKey(27);
            if( c == 27 )
	    	 break;
        }
  return 0;
}
