// 4_canny.cpp: 定义控制台应用程序的入口点。
// use the canny to search edge
// date: 2018/03/24
// author: ihaoming

#include "stdafx.h"
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>

//namespace
using namespace std;
using namespace cv;


int main()
{
	//read image
	Mat src_image = imread("./clock.jpg");
	if (src_image.data == NULL)
	{
		cout << "can't open the file!" << endl;
		getchar();
		return -1;
	}

	//show source image
	imshow("src_image", src_image);
	//source image to gray image
	Mat gray_image;
	cvtColor(src_image, gray_image, COLOR_BGR2GRAY);	//opencv3

													//blur 
	Mat dst_image;
	blur(gray_image, dst_image, Size(3, 3));
	//canny
	Canny(dst_image, dst_image, 3, 9);

	imshow("dst_image", dst_image);
	waitKey(0);

	return 0;
}

