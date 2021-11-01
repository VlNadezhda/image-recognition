#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(int argc, char** argv)
{
    cv::Mat im_rgb= cv::imread("ll.jpg");

    if (im_rgb.empty()) {
        cout << "Error" << endl;
        return -1;
    }

    cv::imshow("original",im_rgb);
    cv::waitKey(0);

    cv::Mat im_gr;
    cvtColor(im_rgb,im_gr,cv::COLOR_RGB2GRAY);
    imshow("gray", im_gr);
    cv::waitKey(0);

    cv::Mat im_canny;
    cv::Canny(im_rgb,im_canny,100,200);
    imshow("Canny", im_canny);
    cv::waitKey(0);

    cv::Mat im_gauss;
    GaussianBlur(im_rgb,im_gauss, cv::Size(5, 5), 0);
    imshow("Gaussian", im_gauss);
    cv::waitKey(0);

    cv::Mat im_hsv;
    cvtColor(im_rgb,im_hsv, cv::COLOR_BGR2HSV);
    imshow("HSV", im_hsv);
    cv::waitKey(0);

    cv::Mat im_clr;
    cvtColor(im_rgb,im_clr, cv::COLOR_BGR2YCrCb);
    imshow("YCrCb", im_clr);
    cv::waitKey(0);
    return 0;
}
