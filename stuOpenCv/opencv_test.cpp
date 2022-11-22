#include <opencv2/opencv.hpp>
#include "quickOpencv.h"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argcm, char** argv) {
	Mat src = imread("E:/pic/nops.png"); //读取图像	图片路径,图片色彩空间的模式
	//src的深度用枚举来表示是1 其实是24位因为图片的三色通道是24一个通道是8位 读取的顺序是 B G R
	if (src.empty())
	{
		printf("clould not loading the pic\n");
		return -1;
	}
	//namedWindow("pic", WINDOW_FREERATIO);//参数:窗口名称,图片显示的模式 不加参数 默认为WINDOW_AUTOSIZE 无法修改窗口大小
	imshow("RGB", src); //显示图像 参数:窗口名称,Mat存储图片的对象
	
	
	QuickDemo qd; 
	//qd.colorSpace_Demo(src); 创建hsv 和gray 图
	//qd.mat_creation_demo(src); 图像对象的创建 以及生成单一颜色窗口
	//qd.pixel_Visit_Demo(src); 下标指针访问图像像素的读写操作
	//qd.operators_Demo(src); //算术操作改变图像
	//qd.tracking_Bar_Demo(src); //滚动条调整图像亮度 对比度
	//qd.key_Demo(src); 键盘输入调整图片模式
	//qd.color_Style_Demo(src); opencv 自带的图像模式
	//qd.bitwise_Demo(src); 图像的逻辑操作
	//qd.channers_Demo(src); //通道的分离和合并
	//qd.inrange_Demo(src); //图像色彩空间转换 实现绿幕图片扣人像换背景
	//qd.pixel_Statistic_Demo(src);//图像像素值统计 最大值最小值 均值和方差
	//qd.drawing_Demo(src); //图像几何绘制 矩形 圆形 椭圆 线
	//qd.random_Drawing_Demo(); //画布中随机绘制线
	//qd.polyline_Drawing_Demo(); //多边形的绘制与填充
	//qd.mouse_Drawing_Demo(src); //鼠标操作和响应
	//qd.norm_Demo(src); //图像像素类型转换和归一化
	//qd.resize_Demo(src); //图像放缩和插值
	//qd.flip_Demo(src); //图像翻转
	//qd.rotate_Demo(src); //图像旋转
	//qd.camera_Demo(src); //摄像头调用
	//qd.show_Histogram_Demo(src); //绘制图像直方图
	//qd.show_Histogram2D_Demo(src); //绘制二维直方图
	//qd.histogram_Eq_Demo(src); //直方图均衡化
	//qd.blur_Demo(src); //图像卷积操作
	//qd.gaussian_Blur_Demo(src); //高斯模糊
	// qd.bifilter_Demo(src);	//高斯双边模糊
	qd.face_Detection_Demo(); //人脸检测
	waitKey(0);//0 一直阻塞
	destroyAllWindows();//销毁所有的显示窗口
	return 0;
}