#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void brightness2();
void brightness3();


int main(void)
{
	/* 픽셀 값이 0 ~ 255 범위를 넘을 경우
	unsigned char a = 257; 
	cout << "a = " << a << endl; // a = 1;
	unsigned char b = -5; // -5의 보수로 표현(251, 11111011)
	cout << "b = " << b << endl; // b = 251;
	*/
	brightness2();
	brightness3();

	return 0;
}


void brightness2()
{
	Mat src = imread("../images/lena.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = src.at<uchar>(j, i) - 100; // <uchar> = unsigned intager
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}

void brightness3()
{
	Mat src = imread("../images/lena.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	destroyAllWindows();
}