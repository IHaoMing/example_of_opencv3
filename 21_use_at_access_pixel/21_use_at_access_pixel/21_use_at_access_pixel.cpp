// 21_use_at_access_pixel.cpp: 定义控制台应用程序的入口点。
// description: use the 'at' to access pixel
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

//declare funtion
static void color_reduce(Mat& input_image, Mat& output_image, int div);
int main()
{
	//step1: read and show the source image
	Mat src_image = imread("./clock.jpg");
	if (src_image.empty())
	{
		cout << "failed to load the image!" << endl;
		getchar();
		return -1;
	}

	//step2: create the output image
	Mat dst_image(src_image.size(), src_image.type());

	//step3: record  start time
	double stime = static_cast<double>(getTickCount());

	//step4: call the test function
	color_reduce(src_image, dst_image, 32);

	//step5: recod the end time and calculate the cost
	double etime = static_cast<double>(getTickCount());
	double cost = (etime - stime) / getTickFrequency();
	cout << "cost: " << cost << " ms" << endl;

	//step6: show the output image
	imshow("dst_image", dst_image);
	waitKey(0);

    return 0;
}

static void color_reduce(Mat& input_image, Mat& output_image, int div)
{
	//step1: copy the input image to out put image 
	output_image = input_image.clone();

	//step2: get rows and cols
	int rows = output_image.rows;
	int cols = output_image.cols;

	//step3: access the pixels
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			output_image.at<Vec3b>(i, j)[0] = output_image.at<Vec3b>(i, j)[0] / div * div + div / 2;	//blue
			output_image.at<Vec3b>(i, j)[1] = output_image.at<Vec3b>(i, j)[1] / div * div + div / 2;	//green
			output_image.at<Vec3b>(i, j)[2] = output_image.at<Vec3b>(i, j)[2] / div * div + div / 2;	//red
		}
	}
}