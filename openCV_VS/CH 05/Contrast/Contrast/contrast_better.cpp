#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void contrast2();

int main(void)
{

	contrast2();

	return 0;
}

void contrast2()
{
	Mat src = imread("../images/lena.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	float alpha = 1.f;
	float beta = 0.5;
	
	Mat dst1 = src + (src - 128) * alpha;
	Mat dst2 = src + (src - 128) * beta;

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey();

	destroyAllWindows();
}