//그레이스케일 영상 다루기

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void func(Mat& img);
int main()
{
	
	Mat img1 = cv::imread("../images/lena.jpg", IMREAD_GRAYSCALE);

	//Mat img2(img1.size(), CV_8UC1, Scalar(0));
	//img2 = img1;
	Mat img2(img1.size(), CV_8UC1, Scalar(255)); // Scalar 값 바꿔도 상관없음.
	img2 = img1;

	Mat img3 = imread("../images/lena.jpg", IMREAD_COLOR);
	Mat img4;
	cvtColor(img3, img4, COLOR_BGR2GRAY);

	/* 이미지 에러 확인
	if (img.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}
	*/

	func(img3); // 에러

	imshow("Image1", img1);
	imshow("Image2", img2);
	imshow("Image3", img3);
	imshow("Image4", img4);

	cv::waitKey();
	destroyAllWindows();
	return 0;
}

void func(Mat& img)
{
	CV_Assert(img.type() == CV_8UC1);

	// 그레이스케일 영상 처리 수행
}