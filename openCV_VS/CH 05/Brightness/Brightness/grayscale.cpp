//�׷��̽����� ���� �ٷ��

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
	Mat img2(img1.size(), CV_8UC1, Scalar(255)); // Scalar �� �ٲ㵵 �������.
	img2 = img1;

	Mat img3 = imread("../images/lena.jpg", IMREAD_COLOR);
	Mat img4;
	cvtColor(img3, img4, COLOR_BGR2GRAY);

	/* �̹��� ���� Ȯ��
	if (img.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}
	*/

	func(img3); // ����

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

	// �׷��̽����� ���� ó�� ����
}