// 2_image_erode.cpp: 定义控制台应用程序的入口点。
//date: 2018/03/21
//editor: ihaoming

//include files
#include "stdafx.h"
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

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
	else
	{
		imshow("src_image", src_image);
		//get structuring element
		Mat element_1 = getStructuringElement(MORPH_RECT, Size(15, 15));
		Mat element_2 = getStructuringElement(MORPH_CROSS, Size(15, 15));
		Mat element_3 = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
		Mat dst_image_1;
		Mat dst_image_2;
		Mat dst_image_3;
		//erode the image
		erode(src_image, dst_image_1, element_1);
		erode(src_image, dst_image_2, element_2);
		erode(src_image, dst_image_3, element_3);

		imshow("dst_image", dst_image_1);
		imshow("dst_image_2", dst_image_2);
		imshow("dst_image_3", dst_image_3);

		waitKey(0);

	}
	return 0;
}

