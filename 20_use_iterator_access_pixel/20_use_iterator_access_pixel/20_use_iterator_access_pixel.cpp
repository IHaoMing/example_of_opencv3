// 20_use_iterator_access_pixel.cpp: 定义控制台应用程序的入口点。
// description: use the iterator to access pixel
// author: ihaoming
// date: 2018/04/05

//included files
#include "stdafx.h"
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

//namespace 
using namespace std;
using namespace cv;

//declare function
static void color_reduce(Mat& input_image, Mat& output_image, int div);


int main()
{
	//step1: read the source image
	Mat image = imread("./clock.jpg");
	if (image.empty())
	{
		cout << "failed to load the image!" << endl;
		getchar();
		return -1;
	}

	//step2: create the destination image
	Mat dst_image(image.size(), image.type());

	//step3: record the start time
	double time0 = static_cast<double>(getTickCount());

	//step4: call the color_reduce function
	color_reduce(image, dst_image, 32);

	//step5: calculate the time and print
	double time1 = static_cast<double>(getTickCount());
	cout << "spend " << (time1 - time0) / getTickFrequency() << " ms" << endl;

	//step6: show the destination image
	imshow("dst_image", dst_image);
	waitKey(0);

    return 0;
}

static void color_reduce(Mat& input_image, Mat& output_image, int div)
{
	//step1: copy the input image to output image
	output_image = input_image.clone();

	//step2: get the iterator
	Mat_<Vec3b>::iterator it = output_image.begin<Vec3b>();		//get the start of iterator
	Mat_<Vec3b>::iterator it_end = output_image.end<Vec3b>();	//get the end of iterator

	//step3: access the pixels
	for ( ; it != it_end ; ++it)
	{
		(*it)[0] = (*it)[0] / div * div + div / 2;
		(*it)[1] = (*it)[1] / div * div + div / 2;
		(*it)[2] = (*it)[2] / div * div + div / 2;
	}
}
