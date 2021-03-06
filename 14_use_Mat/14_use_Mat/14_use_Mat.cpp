// 14_use_Mat.cpp: 定义控制台应用程序的入口点。
// date: 2018/03/31
// author: ihaoming

//included fils
#include "stdafx.h"
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

//namespace 
using namespace std;
using namespace cv;


int main()
{
	//use the eye()
	Mat I = Mat::eye(4, 4, CV_64F);
	I.at<double>(1, 1) = CV_PI;
	cout << "\nI = " << I << ";\n" << endl;

	Mat r = Mat(10, 3, CV_8UC3);		//create a 10*3 and  channels matrix
	randu(r, Scalar::all(0), Scalar::all(255));		//Uniform distribution of gray values

	//different styles display
	//the format() is diferent from opencv2
	cout << "opencv default style: \n" << r << ";" << endl << endl;
	cout << "python style: \n" << format(r, Formatter::FMT_PYTHON) << ";" << endl << endl;
	cout << "numpy style: \n" << format(r, Formatter::FMT_NUMPY) << ";" << endl << endl;
	cout << "CSV style:\n" << format(r, Formatter::FMT_CSV) << ";" << endl << endl;
	cout << "C style:\n" << format(r, Formatter::FMT_C) << ";" << endl << endl;

	Point2f p(6, 2);		//Two-dimensional point
	cout << "2d point = \n" << p << ";" << endl;

	Point3f p3f(10, 2, 0);		//Three-dimensional point
	cout << "3d point = \n" << p3f << ";" << endl;

	//vector witch basic on Mat
	vector<float> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	cout << "vector witch basic on Mat = " << Mat(v) << ";\n" << endl;


	vector<Point2f> points(20);
	for (size_t i = 0; i < points.size(); ++i)
		points[i] = Point2f((float)(i * 5), (float)(i % 7));

	cout << "2d points = " << points << ";";

	getchar();
	return 0;
}

