// 3_use_blur_function.cpp: 定义控制台应用程序的入口点。
//use the blur function
//date:2018/03/22
//author:ihaoming

//include file

#include "stdafx.h"
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

//namespace 
using namespace std;
using namespace cv;


int main()
{
	Mat src_image = imread("./clock.jpg");
	if (src_image.data == NULL)
	{
		cout << "can't open the file!" << endl;
		getchar();
		return -1;
	}

	//use blur
	Mat dst_image;
	blur(src_image, dst_image, Size(7, 7));

	imshow("src_image", src_image);
	imshow("dst_image", dst_image);

	waitKey(0);

	return 0;
}

