#include <iostream>
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int, char**)
{
    string filename = "/home/pi/Image.png";
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
    namedWindow("camera");

    while(1){

        cap >> frame;
        imshow("camera",frame);

        if (waitKey(1) == 27 ) 		//wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
	{
	    cout << "esc key is pressed by user" << endl;
	    imwrite((filename),frame);
            break; 
	}
	           
            
    }
    cap.release();

  return 0;
}
