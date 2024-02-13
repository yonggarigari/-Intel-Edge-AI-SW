#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void brightness1();

int main(void)
{
	brightness1();

	return 0;
}

void brightness1()
{
	Mat src = imread("../images/lena.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst = src + 100;
	//Mat dst = src - 100;
	Mat dst2;
	add(src, 100, dst2);
	//subtract(src, 100, dst2);

	imshow("src", src);
	imshow("dst", dst);
	imshow("dst2", dst2);
	waitKey();

	destroyAllWindows();
}
