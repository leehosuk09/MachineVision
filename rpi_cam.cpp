#include <iostream>
#include <raspicam/raspicam_cv.h>
using namespace std; 
using namespace cv;
int main ( int argc,char **argv ) {
   
    raspicam::RaspiCam_Cv Camera;
    int width=320;
    int height=240;
    int fps=15;
    Size framesize(width,height);
    
      
    //set camera params
    Camera.set(CV_CAP_PROP_FORMAT, CV_8UC3 );
    Camera.set(CV_CAP_PROP_FRAME_WIDTH, width );
    Camera.set(CV_CAP_PROP_FRAME_HEIGHT,height );
    
    
    //Open camera
    cout<<"Opening Camera..."<<endl;
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}
 
    namedWindow("test",1);
    
    //Start capture
	while(1)
	{
		Mat image;
		Camera.grab();
		Camera.retrieve (image); // read a new frame from video
		flip(image,image,0);
		
		oVideoWriter.write(image);		
		imshow("test",image);
		
		if(waitKey(30)==27)
		{
			cout<< "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
}
