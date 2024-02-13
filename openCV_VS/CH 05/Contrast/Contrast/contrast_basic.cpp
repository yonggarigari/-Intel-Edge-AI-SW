#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void contrast1();

int main(void)
{
	contrast1();

	return 0;
}

void contrast1()
{
	Mat src = imread("../images/lena.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	float s = 2.f;
	//float s = 0.5;
	Mat dst = s * src;

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}