// grayscale_transformation.cpp : 定义控制台应用程序的入口点。
// date: 2017/03/30
// author: ihaoming

#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

static void linear_transform(Mat input_image, Mat output_image, const double k, const double b);
static void logarithm_transform(Mat input_image, Mat output_image, const double c);

int _tmain(int argc, _TCHAR* argv[])
{
	Mat src_image = imread("./lena.jpg");

	if (src_image.empty())
	{
		cout << "can't read the image!" << endl;
		getchar();
		return -1;
	}
	Mat dst_image(src_image.size(), src_image.type());


	//linear_transform(src_image, dst_image, 1.2, 50);
	logarithm_transform(src_image, dst_image, 1);


	imshow("src_image", src_image);
	imshow("dst_image", dst_image);

	waitKey(0);

	return 0;
}
static void linear_transform(Mat input_image, Mat output_image, const double k, const double b)
{
	CV_Assert(!input_image.empty());

	int rows = input_image.rows;
	int cols = input_image.cols;
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			for (int c = 0; c<3; c++)
			{
				output_image.at<Vec3b>(i, j)[c] = saturate_cast<uchar>(k* (input_image.at<Vec3b>(i, j)[c]) + b);
			}
		}
	}
}


static void logarithm_transform(Mat input_image, Mat output_image, const double c)
{
	CV_Assert(!input_image.empty());

	int rows = input_image.rows;
	int cols = input_image.cols;

	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			for (int c = 0; c<3; c++)
			{
				double t = (double)input_image.at<Vec3b>(i, j)[c];
				t = c * log(t + 1);
				output_image.at<Vec3b>(i, j)[c] = saturate_cast<uchar>(t);
			}
		}
	}

	normalize(output_image, output_image, 0, 255, NORM_MINMAX);

	convertScaleAbs(output_image, output_image);

}