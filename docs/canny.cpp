#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
void main()
{
	Mat srcImage = imread("F:\\source.jpg");
	if (!srcImage.data){
		cout << "falied to read" << endl;
		system("pause");  
		return;
	}
	Mat srcGray;
	cvtColor(srcImage, srcGray, CV_BGR2GRAY);
	//高斯滤波
	GaussianBlur(srcGray, srcGray, Size(3, 3),
		0, 0, BORDER_DEFAULT);
	//Canny检测
	int edgeThresh =100;
	Mat Canny_result;
	Canny(srcImage, Canny_result, edgeThresh, edgeThresh * 3, 3);
	imshow("src", srcImage);
	imshow("Canny_result", Canny_result);
	waitKey(0);
}

