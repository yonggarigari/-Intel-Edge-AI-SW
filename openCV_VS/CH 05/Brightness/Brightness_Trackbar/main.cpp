#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void on_brightness(int pos, void* userdata)
{
	Mat src = *(Mat*)userdata;
	Mat dst = src + (pos - 100);
	imshow("Image", dst);
	cout << pos << endl;
}

int gvalue = 100;

int main()
{
	Mat img;
	img = cv::imread("lena.jpg", IMREAD_GRAYSCALE);

	if (img.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	namedWindow("Image");
	//createTrackbar("brightness", "Image", &gvalue, 200, on_brightness, (void*)&img);
	createTrackbar("brightness", "Image", 0, 200, on_brightness, (void*)&img);
	setTrackbarPos("brightness", "Image", 100);


	//cv::namedWindow("Image");
	//cv::imshow("Image", img);

	cv::waitKey();

	return 0;
}