#include <iostream>
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <time.h>
#include <unistd.h>
using namespace cv;
using namespace std;
time_t seconds;
struct tm * timeinfo;
time_t start = time(0);
int main(int, char**)
{
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    char TestStr[100];
    string filename = "/home/pi/web-server/Video-Stream/static/ImageCapture.png";
    Mat frame;
    VideoCapture cap(0); // Try with 0,1,2, etc. this is the number of your camera 
    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
    }
	cout << " Camera warming up..." << endl;
   
    // Determine camera output size automatically...
    double dWidth  = cap.get(CV_CAP_PROP_FRAME_WIDTH); 		// get the width of frames of the video
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); 	// get the height of frames of the video
    int fps     = 15;

    cout << "Frame size : " << dWidth << " x " << dHeight << " --- fps: " << fps << endl;
while(1){
    cap >> frame;
    
     if ( difftime( time(0), start) == 3) {
    sprintf(TestStr,"%d-%d-%d",tm.tm_year + 1900, tm.tm_mon +1, tm.tm_mday);
    putText(frame,TestStr, cvPoint(480,400),FONT_HERSHEY_COMPLEX_SMALL,0.8,cvScalar(124,255,255),1,CV_AA);
    imwrite((filename),frame);
    break;
}
}
    cap.release();

  return 0;
}
