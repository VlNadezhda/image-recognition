#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(int argc, char** argv)
{
    cv::Mat im_rgb= cv::imread("/home/nadezhda/Документы/MyPractic/1/lena.jpg");

    if (im_rgb.empty()) {
        cout << "Error" << endl;
        return -1;
    }

    cv::imshow("original",im_rgb);
    cv::waitKey(0);

    cv::Mat im_gr;
    cvtColor(im_rgb,im_gr,cv::COLOR_RGB2GRAY);
    imshow("gray", im_gr); // Show our image inside the created window.
    cv::waitKey(0);

    cv::Mat im_canny;
    cv::Canny(im_rgb,im_canny,100,200);
    imshow("Canny", im_canny); // Show our image inside the created window.
    cv::waitKey(0);

    cv::Mat im_gauss;
    GaussianBlur(im_rgb,im_gauss, cv::Size(5, 5), 0);
    imshow("Gaussian", im_gauss); // Show our image inside the created window.
    cv::waitKey(0);

    cv::Mat im_hsv;
    cvtColor(im_rgb,im_hsv, cv::COLOR_BGR2HSV);
    imshow("HSV", im_hsv); // Show our image inside the created window.
    cv::waitKey(0);
    return 0;
}