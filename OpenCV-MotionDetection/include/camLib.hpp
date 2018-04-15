#ifndef __IOSTREAM_INCLUDED__
#define __IOSTREAM_INCLUDED__
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/videoio/videoio.hpp>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <time.h>

using namespace cv;
using namespace std;

class Camera
{
public:
    Camera(void);
    ~Camera(void);
    Mat captureVideo(void);
    Mat diffImg(Mat, Mat, Mat);
    int detectMotion(void);
    int closeVideo(void);
    int saveVideo(Mat );

private:
    
    VideoWriter writer;
    double dWidth;
    double dHeight;
    double fps;
    Mat frame;
    Mat prev_frame;
    Mat current_frame;
    Mat next_frame;
    Mat diff1, diff2;
    Mat motion;
    Mat result;
    int x_start, x_stop;
    int y_start, y_stop;
    int max_deviation;
    Scalar mean, stddev;
    int min_x, min_y;	// x, y coordinates of furthest left detected objects...
    int max_x, max_y;  	// x, y coordinates of furthest right detected objects...
    int codec;
    int number_of_changes;
    Mat kernel_ero;		// Erode kernel...
};


#endif	// __IOSTREAM_INCLUDED__
