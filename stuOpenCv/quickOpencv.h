#pragma once

#include<opencv2/opencv.hpp>
using namespace cv;

class QuickDemo {
public:
	void colorSpace_Demo(Mat &image);
	void mat_creation_demo(Mat &image);
	void pixel_Visit_Demo(Mat& image);
	void operators_Demo(Mat& image);
	void tracking_Bar_Demo(Mat& image);
	void key_Demo(Mat& image);
	void color_Style_Demo(Mat& image);
	void bitwise_Demo(Mat& image);
	void channers_Demo(Mat& image);
	void inrange_Demo(Mat& image);
	void pixel_Statistic_Demo(Mat& image);
	void drawing_Demo(Mat& image);
	void random_Drawing_Demo();
	void polyline_Drawing_Demo();
	void mouse_Drawing_Demo(Mat& image);
	void norm_Demo(Mat& image);
	void resize_Demo(Mat& image);
	void flip_Demo(Mat& image);
	void rotate_Demo(Mat& image);
	void camera_Demo(Mat& image);
	void show_Histogram_Demo(Mat& image);
	void show_Histogram2D_Demo(Mat& image);
	void histogram_Eq_Demo(Mat& image);
	void blur_Demo(Mat& image);
	void gaussian_Blur_Demo(Mat& image);
	void bifilter_Demo(Mat& image);
	void face_Detection_Demo();

};