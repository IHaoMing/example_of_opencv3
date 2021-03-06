// 6_open_the_camera.cpp: 定义控制台应用程序的入口点。
// open the camera
// date: 2018/03/24
// author: ihaoming

#include "stdafx.h"
#include<iostream>
#include<opencv2/opencv.hpp>

//namespace 
using namespace cv;
using namespace std;


int main()
{
	VideoCapture capture(0);
	if (capture.isOpened())
	{
		Mat frame;
		//the  major cycle
		for (; ;)
		{
			int key_value = 0;
			if (capture.read(frame))
			{
				imshow("video", frame);
				//delay 30ms and get key value
				key_value = waitKey(30);
				if ((key_value == 27 || key_value == 81))
				{
					//key value: "esc" == 27, "Q" == 81
					//press "esc" or "Q" to quit
					return 0;
				}
			}
		}
	}
	else
	{
		cout << "failed to open the camera!" << endl;
		getchar();
		return -1;
	}
	return 0;
}

