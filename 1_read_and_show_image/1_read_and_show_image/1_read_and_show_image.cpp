// 1_read_and_show_image.cpp: 定义控制台应用程序的入口点。
// description: read and show an image
// author: ihaoming
// date: 2018/03/06

//included files
#include "stdafx.h"
#include<iostream>
#include<opencv2/opencv.hpp>

//namespace
using namespace cv;
using namespace std;

int main()
{
	//step1: read the image
	Mat image = imread("./clock.jpg");

	//step2: jude the data
	if (image.data != NULL)
	{
		//step3: show the image
		imshow("clock", image);
		waitKey(0);
	}
	else
	{
		cout << "can't openc the file!" << endl;
		getchar();
	}
	return 0;
}

