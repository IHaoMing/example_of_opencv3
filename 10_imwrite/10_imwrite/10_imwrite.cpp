// 10_imwrite.cpp: 定义控制台应用程序的入口点。
// 利用imwrite函数生成png图片
// date: 2018/03/29
// author: ihaoming


#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<vector>
#include<iostream>

using namespace std;
using namespace cv;

static void create_alpha_mat(Mat &mat);

int _tmain(int argc, _TCHAR* argv[])
{
	Mat mat(480, 640, CV_8UC4);

	create_alpha_mat(mat);


	vector<int>compression_params;
	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	try {
		imwrite("透明Alpha值图.png", mat, compression_params);
		imshow("生成的png图", mat);
		fprintf(stdout, "PNG图片文件的alpha数据保存完毕~\n可以在工程目录下查看由imwrite函数生成的图片\n");
		waitKey(0);
	}
	catch (runtime_error& ex) {
		fprintf(stderr, "图像转换成PNG格式发生错误：%s\n", ex.what());
		return -1;
	}

	return 0;
}

static void create_alpha_mat(Mat &mat)
{
	CV_Assert(mat.channels() == 4);

	for (int i = 0; i<mat.rows; ++i)
	{
		for (int j = 0; j<mat.cols; ++j)
		{
			Vec4b &bgra = mat.at<Vec4b>(i, j);

			bgra[0] = UCHAR_MAX;	//blue
			bgra[1] = saturate_cast<uchar>(float(mat.cols - j) / float(mat.cols) * UCHAR_MAX);		//green
			bgra[2] = saturate_cast<uchar>(float(mat.rows - i) / float(mat.rows) * UCHAR_MAX);		//red
			bgra[3] = saturate_cast<uchar>(0.5 * (bgra[1] + bgra[2]));								//alpha
		}
	}
}
