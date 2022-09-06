#include <iostream> 
#include <cstdlib>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

class Mouse
{
public:
    string getwindowName() { return windowName; };
    void imageOfPixels();
private:
    Mat image;
    string windowName;
};

bool draw = false;
void mouseEvents(int event, int x, int y, int flag, void* userData)
{
    Mat* image = (Mat*) userData;
    if (event == EVENT_LBUTTONDOWN)
    {
        draw = true;
    }
    else if (event == EVENT_LBUTTONUP)
    {
        draw = false;
    }
    if (draw)
    {
        image->at<Vec3b>(Point(x, y))[0] = rand() % 256;
        image->at<Vec3b>(Point(x, y))[1] = rand() % 256;
        image->at<Vec3b>(Point(x, y))[2] = rand() % 256;
        imshow("myWindow", *image);
    }
}
void Mouse::imageOfPixels()
{
    this->image = Mat::zeros(Size(900, 600), CV_8UC3);
    this->windowName = "myWindow";
    imshow(windowName, image);
    setMouseCallback(windowName, mouseEvents, &image);
    waitKey(0);
}
int main() {
    srand(time(0));
    Mouse mp;
    mp.imageOfPixels();
    return 0;
}


