#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/videoio/videoio.hpp>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace cv;
using namespace std;

int ex = 1734701162;

int main( int argc, const char** argv )
{

    VideoCapture cap(0);
    int i_fps = 15;
    time_t start = time(0);

    string OutputVideoPath = "/home/pi/output.mov";
    VideoWriter outputVideo(OutputVideoPath, ex, i_fps, Size(640,480), true);


    if(!cap.isOpened())  {
        cout << "Not opened" << endl; // check if we succeeded
        return -1;
    }

    while ( 1 ) {

        Mat frame;
        cap >> frame;
        outputVideo << frame;
        if ( difftime( time(0), start) == 30) break;

    }

    outputVideo.release();
    cap.release();


    return 0;
}
