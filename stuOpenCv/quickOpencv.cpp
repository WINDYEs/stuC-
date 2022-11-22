#include "quickOpencv.h"
#include <opencv2/dnn.hpp>
using namespace std;
using namespace cv;
void QuickDemo::colorSpace_Demo(Mat& image) {
	Mat gray, hsv;
	cvtColor(image,hsv,COLOR_BGR2HSV); //RGB 转HSV
	// H，S，V 0-180,  H调颜色 S调饱和度 V调亮度
	cvtColor(image,gray,COLOR_BGR2GRAY); //RGB 转gray
	imshow("HSV", hsv);
	imshow("GRAY", gray);
	imwrite("E:/pic/hsv.png", hsv);
	imwrite("E:/pic/gray.png", gray);
}


void QuickDemo::mat_creation_demo(Mat& image) {
	Mat m1, m2; //矩阵就是列是图片宽度 行是图片高度 
	m1 = image.clone(); //克隆
	image.copyTo(m2); //复制


	//创建空白图像
	Mat m3 = Mat::zeros(Size(400, 400), CV_8UC3); //创建4行4列的空白矩阵 8位的无符号char 单通道1个像素点就一个像素值 三通道就是1个像素点 3个像素值 
	//Mat m3 = Mat::ones(Size(4, 4), CV_8UC1); 注意使用ones 的时候如果定义的三通道 它只会在第一个通道设置为1 其他通道不会设置


	m3 = Scalar(0,255,0);// Scalar可以设置通道的值几通道就设置几个值

	//std::cout << m3 << std::endl;
	std::cout << "width: " << m3.cols << "\t height: " << m3.rows << "\t channels: " << m3.channels() << std::endl;
	imshow("Green", m3);

	Mat m4;
	m4 = m3.clone();
	m4 = Scalar(255, 0, 0);
	imshow("Blue", m4);
	Mat m5 = (Mat_<char>(3, 3)<< 0, 0, 0,
		1, 5, 11,
		0, 1, 0);
	imshow("unknown", m5);
}


void QuickDemo::pixel_Visit_Demo(Mat& image) {
	int width = image.cols; //获取宽度
	int height = image.rows; //获取高度
	int dims = image.channels(); //获取通道数


	//下标访问改变图像像素操作
	/*
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (dims == 1) { //灰度图像
				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv; //获取灰度图像像素点；
			}
			if (dims == 3) { //反相
				Vec3b bgr = image.at<Vec3b>(row, col);
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];//获取反相图像像素点B；
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];//获取反相图像像素点G；
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];//获取反相图像像素点R；
			}
		}
	}
	*/
	

		//指针访问改变图像像素操作
	for (int row = 0; row < height; row++) {
		uchar* current_row = image.ptr<uchar>(row); //获取行指针
		for (int col = 0; col < width; col++) {
			if (dims == 1) { //单通道灰度图像
				*current_row++ = 255 - *current_row; //++指向下一个像素点
				
			}
			if (dims == 3) { //三通道反相
				*current_row++ = 255 - *current_row; //指向同一个像素点 下一个通道
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}


	imshow("像素点演示", image);

}


void QuickDemo::operators_Demo(Mat& image) {
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(2, 2, 2);


	//加法具体实现
	//int width = image.cols; //获取宽度
	//int height = image.rows; //获取高度
	//int dims = image.channels(); //获取通道数

	//for (int row = 0; row < height; row++) {
	//	for (int col = 0; col < width; col++) {
	//		if (dims == 3){
	//			Vec3b p1 = image.at<Vec3b>(row, col);
	//			Vec3b p2 = m.at<Vec3b>(row, col);
	//			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);//dst图像原来的像素点加50
	//			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
	//			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
	//		}
	//	}
	//}
	//add(image, m, dst); //加数 被加数 存储数
	//subtract(image, m, dst); -
	//multiply(image, m, dst); *
	divide(image, m, dst); // /
	imshow("+50", dst); //显示被加50后的image图像 
}

static void on_track(int lightness, void* imageData) {
	Mat image = *((Mat*)imageData);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(lightness, lightness, lightness);
	addWeighted(image, 1.0, m, 0, lightness, dst);
	imshow("亮度与对比度调整", dst);

}

static void on_contrast(int contrastValue,void* imageData) {
	Mat image = *((Mat*)imageData);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = contrastValue / 100.0;
	addWeighted(image, contrast, m, 0, 0, dst); //1数组 数组权重 2数组 数组权重 融合后添加数值 存储的融合后的数组
	imshow("亮度与对比度调整", dst);

}



void QuickDemo::tracking_Bar_Demo(Mat& image) {
	namedWindow("亮度与对比度调整", WINDOW_AUTOSIZE);
	int max_value = 100;
	int lightness = 50; //初始亮度为50
	int contrastValue = 50; //初始对比度为50
	createTrackbar("value Bar:", "亮度与对比度调整", &lightness, max_value, on_track, &image);
	createTrackbar("Contrast:", "亮度与对比度调整", &contrastValue, 200, on_contrast, &image);
	//on_track(lightness, &image);
}

void QuickDemo::key_Demo(Mat& image) {
	Mat dst = Mat::zeros(image.size(),image.type());
	while (true)
	{
		char c = waitKey(0); //waitKey()--这个函数是在一个给定的时间内(单位ms)等待用户按键触发;如果用户没有按下 键,则接续等待(循环)
		if (c == '`')
			break;
		if (c == '1') {
			std::cout << "The image changes to gray" << std::endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);
		}
		if (c == '2') {
			std::cout << "The image changes to hsv" << std::endl;
			cvtColor(image, dst, COLOR_BGR2HSV);
		}
		if (c == '3') {
			std::cout << "The image changes to Highlight" << std::endl;
			dst = Scalar(50, 50, 50);
			add(image, dst, dst);
		}
		imshow("键盘命令", dst);
	}
}


void QuickDemo::color_Style_Demo(Mat& image) {

	int colormap[] = {
		COLORMAP_AUTUMN,
		COLORMAP_BONE,
		COLORMAP_CIVIDIS,
		COLORMAP_COOL,
		COLORMAP_DEEPGREEN,
		COLORMAP_HOT,
		COLORMAP_HSV,
		COLORMAP_INFERNO,
		COLORMAP_JET,
		COLORMAP_MAGMA,
		COLORMAP_OCEAN,
		COLORMAP_PARULA,
		COLORMAP_PINK,
		COLORMAP_PLASMA,
		COLORMAP_RAINBOW,
		COLORMAP_SPRING,
		COLORMAP_SUMMER,
		COLORMAP_TURBO,
		COLORMAP_TWILIGHT,
		COLORMAP_TWILIGHT_SHIFTED,
		COLORMAP_VIRIDIS,
		COLORMAP_WINTER
	};
	Mat dst;
	int index = 0;
	while (true)
	{
		char c = waitKey(500);
		if (c == '`')
			break;
		applyColorMap(image, dst, colormap[index % 19]);
		index++;
		imshow("颜色模式", dst);
	}

}

void QuickDemo::bitwise_Demo(Mat& image) {
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 70, 70), Scalar(255, 0, 0), -1, LINE_8, 0); //-1是填充 大于0是绘制 LINE_8锯齿
	rectangle(m2, Rect(140, 140, 70, 70), Scalar(0, 255, 0), -1, LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	//bitwise_and(m1, m2, dst);
	//bitwise_or(m1, m2, dst);
	//bitwise_not(image, dst); //dst = ~image;
	bitwise_xor(m1, m2, dst);
	imshow("像素位操作", dst);
}


void QuickDemo::channers_Demo(Mat& image) {
	std::vector<Mat>mv;
	split(image, mv); //分离三通道 存储到 mv容器中 
	//从单通道灰度补成3通道RGB
	//分离后为单通道，相当于分离通道的同时把其他两个通道填充了相同的数值。比如红色通道，分离出红色通道的同时，绿色和蓝色被填充为和红色相同的数值，这样一来就只有黑白灰了。
	imshow("blue", mv[0]); //显示各通道的灰度图
	imshow("green", mv[1]);
	imshow("red", mv[2]);

	Mat dst;
	//蓝色
	mv[1] = 0; //修改其他两个通道的值
	mv[2] = 0;
	merge(mv, dst); //从单通道灰度补成3通道RGB
	imshow("blue", dst);
	
	//绿色
	/*mv[0] = 0;
	mv[2] = 0;
	merge(mv, dst);
	imshow("green", dst);*/

	//红色
	/*mv[0] = 0;
	mv[1] = 0;
	merge(mv, dst); 
	imshow("red", dst);*/

	int from_to[] = { 0,1, 1,2, 2,0 }; //image0通道复制到dst1通道 image1通道复制到dst2通道 image2通道复制到dst0通道
	mixChannels(&image, 1, &dst, 1, from_to, 3);
		/*第一个参数：输入矩阵
		第二个参数：输入矩阵的数量
		第三个参数：输出矩阵
		第四个参数：输出矩阵的数量
		第五个参数：复制列表
		第六个参数：复制列表覆盖的通道数量*/
	imshow("mixChannelS", dst);
}

void  QuickDemo::inrange_Demo(Mat& image) {
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV); //图片转变为hsv图像 存储到hsv中
	Mat mask;
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask); //hsv格式图片保留hsv格式除了绿色范围以外的值存储到mask中
	imshow("mask", mask);

	Mat blueBack = Mat::zeros(image.size(), image.type());
	blueBack = Scalar(244, 12, 12); //和图片大小相同的蓝色背景图
	bitwise_not(mask, mask);//人像变白色其他区域变为黑色
	imshow("mask", mask);
	image.copyTo(blueBack, mask); //意思是蓝色背景图可以得到一个附加掩膜MASK的图片掩盖后在图像中掩膜中所有像素值对应为0的点变为黑色（被掩盖），其他点（所有非0值）和原来一致
	imshow("bluebackground", blueBack);

}

void QuickDemo::pixel_Statistic_Demo(Mat& image) {
	double minv, maxv;
	Point minPonit, maxPoint;
	std::vector<Mat> mv;
	split(image, mv); //image分离三通道存储到mv
	for (int i = 0; i < mv.size(); i++) {
		minMaxLoc(mv[i], &minv, &maxv, &minPonit, &maxPoint);
		std::cout << "channels:" << i << "min pixel value is " << minv << " max pixel value is " << maxv << std::endl; //获取图片的最大最小像素并返回对应的指针
	
	}

	//方差小图像整体差异没什么变化
	Mat mean, stddev;
	Mat back = Mat::zeros(image.size(), image.type());
	back = Scalar(230, 12, 0);
	meanStdDev(back, mean, stddev); //获取back 的均值和标准差
	std::cout << "means: " << mean << std::endl;
	std::cout << "stddev: " << stddev << std::endl;
	imshow("back", back);
}


void QuickDemo::drawing_Demo(Mat& image) {
	Rect rect;
	rect.x = 125;
	rect.y = 0;
	rect.width = 210;
	rect.height = 270;
	Mat bg = Mat::zeros(image.size(), image.type());
	//空白图上绘制圆形和矩形 线
	rectangle(bg, rect, Scalar(0, 255, 0), 2, 8, 0);//矩形要绘制的图片,矩形, 矩形的颜色显示,矩形线条的厚度, lineType线的类型, 点坐标中的小数位数
	circle(bg, Point(355, 290), 20, Scalar(10, 10, 230), -1, 8, 0); //圆形要绘制的图片,圆坐标,半径,绘制的颜色 , 圆形线条的厚度, lineType线的类型, 点坐标中的小数位数
	line(bg, Point(125, 0), Point(335, 270), Scalar(255, 0, 0), 2, LINE_AA, 0);//线要绘制的图片,线的起始坐标,线的终止坐标,绘制的颜色,线条的厚度, lineType线的类型, LINE_AA 反锯齿 点坐标中的小数位数 
	//绘制椭圆
	RotatedRect rrt;
	rrt.center = Point(200, 100); //椭圆圆心坐标
	rrt.size = Size(100, 200); //width,height
	rrt.angle = 80.0; //椭圆的角度
	ellipse(bg, rrt, Scalar(0, 255, 255), 2, 8);//椭圆形要绘制的图片,椭圆形, 椭圆形的颜色显示,椭圆形线条的厚度, lineType线的类型
	Mat dst;
	addWeighted(image, 0.7, bg, 0.4, 2, dst); //1数组 数组权重 2数组 数组权重 融合后添加数值 存储的融合后的数组
	//imshow("绘制", image);
	imshow("融合", dst);
}

void QuickDemo::random_Drawing_Demo() {
	Mat canvas = Mat::zeros(Size(500,500),CV_8UC3); //画布大小 三通道
	RNG rng((unsigned)time(NULL)); //使用系统时间（1970年1月1日零时零分零秒，到目前为止所经历德 总秒数）来作为随机种子。
	int width = canvas.cols;
	int height = canvas.rows;
	while (true)
	{
		int c = waitKey(10);//10ms刷新
		if (c == 27)
			break;
		int xStart = rng.uniform(0, width); //随机线起始坐标 范围 是0 到 画布的宽度大小
		int yStart = rng.uniform(0, height); //随机线起始坐标 范围 是0 到 画布的高度大小
		int xEnd = rng.uniform(0, width); //随机线结束坐标 范围 是0 到 画布的宽度大小
		int yEnd = rng.uniform(0, height); //随机线结束坐标 范围 是0 到 画布的高度大小

		int b = rng.uniform(0, 255); //随机通道颜色 范围0 - 255
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);
		//画布范围随机生成线
		//canvas = Scalar(0, 0, 0);生成一条线绘制画布为黑背景覆盖一条 就展示一条线了
		line(canvas, Point(xStart, yStart), Point(xEnd, yEnd), Scalar(b, g, r), 1, LINE_AA, 0);
		//线要绘制的图片,线的起始坐标,线的终止坐标,绘制的颜色,线条的厚度, lineType线的类型, LINE_AA 反锯齿 点坐标中的小数位数 
		imshow("随机线绘制", canvas);

	}

}

void QuickDemo::polyline_Drawing_Demo() {
	Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3); //绘制画布
	//定义多边形的点
	Point p1(400, 200);
	Point p2(140, 100);
	Point p3(300, 210);
	Point p4(120, 300);
	Point p5(250, 450);
	std::vector<Point> pts; //定义一维Vector数组
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);
	polylines(canvas, pts, true, Scalar(0, 255, 255), 2, LINE_AA, 0);/*
		image:绘制图像 ,pts : 多边形曲行数组 ,isClosed : 指示绘制的折线是否闭合的标志。如果它们是闭合的，则该函数从每条曲线的最后一个顶点到其第一个顶点绘制一条线 绘制的颜色 绘制的厚度, 线类型, 点坐标中的小数位 注意这里不可以填充*/
	fillPoly(canvas, pts, Scalar(255, 0, 0), LINE_AA, 0);//填充多边形

	//绘制多个多边形
	std::vector<std::vector<Point>>polygons; //定义二维vector数组 存储多边形
	polygons.push_back(pts);//存储多边形
	drawContours(canvas, polygons, 0, Scalar(0,255,0), 2, LINE_AA); //绘制的画布, 多边形数组，输出第几个多边形的索引 -1是输出所有多边形 颜色, 厚度, 线的类型 这个可以直接填充
	imshow("绘制多边形", canvas);
}

Point sp(-1, -1); 
Point ep(-1, -1);
Mat temp;
static void on_draw(int event, int x, int y, int flags, void* userdata) {
	Mat image = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN) {
		sp.x = x; //记录鼠标左键按下时的坐标
		sp.y = y;
		std::cout << "start point " << sp << std::endl;

	}
	else if (event == EVENT_LBUTTONUP) {
		ep.x = x; //记录鼠标左键放开时的坐标
		ep.y = y;
		int width, height, rx, ry;
		if (ep.x != sp.x) { //鼠标移动有效才绘制图形
			if (ep.x > sp.x && ep.y > sp.y) { //从左上往右下画 
				width = ep.x - sp.x; //要绘制的矩形宽度  //大减小
				height = ep.y - sp.y; //要绘制的矩形高度
				rx = sp.x;
				ry = sp.y;
			}
			else if (ep.x < sp.x && ep.y < sp.y) { //从右下往左上画
				width = sp.x - ep.x;
				height = sp.y - ep.y;
				rx = ep.x;
				ry = ep.y;
			}
			else if (ep.x < sp.x && ep.y > sp.y) {//从右上往左下画
				width = sp.x - ep.x; //大减小
				height = ep.y - sp.y;
				rx = ep.x; //绘图都是从左上角为原点开始绘图的，所以就需要左上角原点的坐标
				ry = sp.y;

			}
			else if (ep.x > sp.x && ep.y < sp.y) {//从左下往右上画
				width = ep.x - sp.x;
				height = sp.y - ep.y;
				rx = sp.x;
				ry = ep.y;

			}
			Rect box(rx, ry, width, height);//设置图形 起始坐标 和宽高
			temp.copyTo(image); //覆盖移动过程的绘图红线
			imshow("cutRect", temp(box)); //获得绘制的矩形区域的图片
			rectangle(image, box, Scalar(255, 0, 255), 2, LINE_AA, 0);
			imshow("mouseDraw", image);
			sp.x = -1;//初始化起始坐标
			sp.y = -1;
		}

	}
	else if (event == EVENT_MOUSEMOVE) { //记录鼠标移动时的坐标
		if (sp.x > 0 && sp.y > 0) {
			ep.x = x;
			ep.y = y;
			int width, height, rx, ry;
			if (ep.x != sp.x) { //鼠标移动有效才绘制图形
				if (ep.x > sp.x && ep.y > sp.y) { //从左上往右下画 
					width = ep.x - sp.x; //要绘制的矩形宽度  //大减小
					height = ep.y - sp.y; //要绘制的矩形高度
					rx = sp.x;
					ry = sp.y;
				}
				else if (ep.x < sp.x && ep.y < sp.y) { //从右下往左上画
					width = sp.x - ep.x;
					height = sp.y - ep.y;
					rx = ep.x;
					ry = ep.y;
				}
				else if (ep.x < sp.x && ep.y > sp.y) {//从右上往左下画
					width = sp.x - ep.x; //大减小
					height = ep.y - sp.y;
					rx = ep.x; //绘图都是从左上角为原点开始绘图的，所以就需要左上角原点的坐标
					ry = sp.y;

				}
				else if (ep.x > sp.x && ep.y < sp.y) {//从左下往右上画
					width = ep.x - sp.x;
					height = sp.y - ep.y;
					rx = sp.x;
					ry = ep.y;

				}
				Rect box(rx, ry, width, height);//设置图形 起始坐标 和宽高
				temp.copyTo(image); //覆盖移动过程的绘图
				rectangle(image, box, Scalar(255, 0, 255), 2, LINE_AA, 0); //绘制的图片就是最新没有绘图过的原图
				imshow("mouseDraw", image);
			}
		}

	}
}
void QuickDemo::mouse_Drawing_Demo(Mat& image) {
	namedWindow("mouseDraw", WINDOW_AUTOSIZE);
	setMouseCallback("mouseDraw", on_draw, (void*)(&image));
	temp = image.clone();
}

void QuickDemo::norm_Demo(Mat& image) {
	Mat dst;
	std::cout << image.type() << std::endl;
	image.convertTo(image, CV_32F); //类型转换 CV_8UC3 -> CV_32FC3 8位3通道的无符号char类型 转为 32位3通道的float类型
	std::cout << image.type() << std::endl;
	normalize(image, dst, 1.0, 0, NORM_MINMAX);
	std::cout << image.type() << std::endl; //浮点数类型值范围0-1之间 所以需要归一化
	imshow("图像数据归一化", dst);

}

void QuickDemo::resize_Demo(Mat& image) {
	Mat zoomin, zoomout; //放大 缩小
	int height = image.rows;
	int width = image.cols;
	resize(image, zoomin, Size(2 * width, 2 * height), 0, 0, INTER_LINEAR); //原图片 放大图片，图片放大的尺寸， (fx, fy按比例缩小放大 图片大小已经操作 则fx,fy为0),INTER_LINEAR线性插值 
	imshow("放大", zoomin);

	resize(image, zoomout, Size(width / 2, height / 2), 0, 0, INTER_LINEAR); //原图片 缩小图片，图片缩小的尺寸， (fx, fy按比例缩小放大 图片大小已经操作 则fx,fy为0),INTER_LINEAR线性插值 
	imshow("缩小", zoomout);
}

void QuickDemo::flip_Demo(Mat& image) {
	Mat dst, dst2, dst3;
	flip(image, dst, 0); //上下翻转
	flip(image, dst2, 1); //左右翻转
	flip(image, dst3, -1); //180度翻转
	imshow("updownfilp", dst);
	imshow("lrfilp", dst2);
	imshow("180 filp", dst3);
}

void QuickDemo::rotate_Demo(Mat& image) {
	Mat dst, M;
	int width = image.cols;
	int height = image.rows;
	M = getRotationMatrix2D(Point2f(width / 2, height / 2), 30, 1.0);//原来图像的中心位置, 旋转的角度, 旋转后的缩放比例 
	double cos = abs(M.at<double>(0, 0)); //获取旋转图片后的cos sin
	double sin = abs(M.at<double>(0, 1));
	//（0，0）是仿射矩阵M的第一行第一个元素就是cos，（0，1）就是第一行第二个元素就是sin
	//求出旋转后的新的宽度和高度
	double newWidth = cos * width + sin * height;
	double newHeight = sin * width + cos * height;

	//获取新的图像中心
	M.at<double>(0, 2) += (newWidth / 2 - width / 2);
	M.at<double>(1, 2) += (newHeight / 2 - height / 2);
	//旋转后的中心会发生变化，需要加上偏移量，(0, 2)(1, 2)分别就是x轴y轴偏移量
	
	//实现的图像的旋转 
	warpAffine(image, dst, M, Size(newWidth, newHeight),INTER_LINEAR, 0, Scalar(0,255,255)); //原图, 存储旋转后图片, 旋转的矩阵, 旋转后图像新的大小, 插值方式，0，背景颜色
	imshow("Rotate...", dst);
}

void QuickDemo::camera_Demo(Mat& image) {
	VideoCapture capture("E:/pic/pica.mov");
	double frame_width = capture.get(CAP_PROP_FRAME_WIDTH); //获取视频一帧的宽度
	double frame_height = capture.get(CAP_PROP_FRAME_HEIGHT); //获取视频一帧的高度
	double count = capture.get(CAP_PROP_FRAME_COUNT); //获取视频的总帧数
	double fps = capture.get(CAP_PROP_FPS);//获取视频一秒有多少帧数

	std::cout << "frame width: " << frame_width << std::endl;
	std::cout << "frame height: " << frame_height << std::endl;
	std::cout << "frame fps: " << fps << std::endl;
	std::cout << "frame count: " << count << std::endl;
	//不支持mov格式视频的保存
	VideoWriter writer("E:/test.mov", capture.get(CAP_PROP_FOURCC), fps, Size(frame_width, frame_height), true);//视频路径, 编码方式, 一秒多少帧, 视频宽高, 是否保留颜色 
	Mat frame;
	while (true)
	{
		capture.read(frame); //
		if (frame.empty())
			break;
		imshow("frame", frame);

		writer.write(frame); //保存视频
		//color_Style_Demo(frame);
		int c = waitKey(1);
		if (c == 27)
			break;
	}
	//release
	capture.release();
	writer.release();
}


void QuickDemo::show_Histogram_Demo(Mat& image) {
	//三通道分离
	std::vector<Mat> bgr_plane;
	split(image, bgr_plane);
	//定义参数变量
	const int channels[1] = { 0 };
	const int bins[1] = { 256 }; //256绘制点
	float hranges[2] = { 0 ,255 };
	const float* ranges[1] = { hranges };
	Mat b_hist;
	Mat g_hist;
	Mat r_hist;
	//计算BLUE GREEN RED 通道的直方图
	calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);


	//显示直方图
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / bins[0]);
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	//归一化直方图 把三个通道的取值归化到大小一致的范围
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//绘制直方图曲线
	for (int i = 1; i < bins[0]; i++) {
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255,0,0), 2, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
	}

	//显示直方图
	namedWindow("Histogram Demo", WINDOW_AUTOSIZE);
	imshow("Histogram Demo", histImage);


}

void QuickDemo::show_Histogram2D_Demo(Mat& image) {
	//2D直方图 H色调、S饱和度、V明度 值范围分别是 [0,180)， [0,255)， [0,255)
	Mat hsv, hs_hist; 
	cvtColor(image, hsv, COLOR_BGR2HSV);
	int hbins = 30, sbins = 32; //步长 = 图像的灰度等级 / bins
	int hist_bins[] = { hbins, sbins };
	float h_range[] = { 0 ,180 }; //h通道的像素取值范围
	float s_range[] = { 0 ,256 }; //s的像素取值范围
	const float* hs_ranges[] = { h_range, s_range };
	int hs_channels[] = { 0 ,1 };
	calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_ranges, true, false);
			//图像,图像数量,要求取直方图的通道索引, Mat(), 存储的2d直方图, 直方图的维度, 存储通道的bins数组, 求去通道像素取值范围数组,true, false;
	double maxVal = 0;
	minMaxLoc(hs_hist, 0, &maxVal, 0, 0); //取最大值
	int scale = 10;
	Mat hist2d_image = Mat::zeros(sbins * scale, hbins * scale, CV_8UC3); //定义空白图像存储2维直方图
	for (int h = 0; h < hbins; h++) {
		for (int s = 0; s < sbins; s++) {
			float binVal = hs_hist.at<float>(h, s);
			int intensity = cvRound(binVal * 255 / maxVal);
			rectangle(hist2d_image, Point(h * scale, s * scale),
				Point((h + 1) * scale - 1, (s + 1) * scale - 1), Scalar::all(intensity),
				-1);
		}
	}
	imshow("H-S Histogram", hist2d_image);
	imwrite("E:/hist_2d.png", hist2d_image);



}


//直方图均衡化 就是把原始的直方图变换为在整个灰度范围（0~255）内均匀分布的形式，从而增加像素灰度值的动态范围，达到增强图像整体对比度的效果
void QuickDemo::histogram_Eq_Demo(Mat& image) {
	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("灰度图像", gray);
	Mat dst;
	equalizeHist(gray, dst);//就是把直方图的每个灰度值进行归一化处理，求每种灰度的累积分布，接着得到一个映射的灰度映射表，然后根据相应的灰度值来修正原图中的每个像素。
	imshow("直方图均衡化演示", dst);
}

void QuickDemo::blur_Demo(Mat& image) {
	Mat dst;
	// blur的作用是对输入的图像src进行均值滤波后用dst输出
	blur(image, dst, Size(3, 3), Point(-1, -1)); //Size 为卷积核大小 默认值Point(-1,-1)。如果这个点坐标是负值的话，就表示取核的中心为锚点，所以默认值Point(-1,-1)表示这个锚点在核的中心。
	imshow("图像模糊", dst);

}

void QuickDemo::gaussian_Blur_Demo(Mat& image) {
	Mat dst;
	GaussianBlur(image, dst, Size(0, 0), 7, 0); 
	/*ksize，高斯内核的大小。其中ksize.width和ksize.height可以不同，但他们都必须为正数和奇数（并不能理解）。或者，它们可以是零的，它们都是由sigma计算而来。
		sigmaX，表示高斯核函数在X方向的的标准偏差。
		sigmaY，表示高斯核函数在Y方向的的标准偏差。若sigmaY为零，就将它设为sigmaX，如果sigmaX和sigmaY都是0，那么就由ksize.width和ksize.height计算出来。*/
	imshow("高斯模糊", dst);

}


void QuickDemo::bifilter_Demo(Mat& image) {
	Mat dst;
	bilateralFilter(image, dst, 0, 100, 3);
	imshow("双边模糊", dst);

}

void QuickDemo::face_Detection_Demo() {
	std::string root_dir = "E:/Programs/OpenCv4.5.4/opencv/sources/samples/dnn/face_detector/";
	dnn::Net net = dnn::readNetFromTensorflow(root_dir + "opencv_face_detector_uint8.pb", root_dir + "opencv_face_detector.pbtxt");
	
	VideoCapture capture("E:/pic/pica.mov");
	Mat frame;
	while (true)
	{
		capture.read(frame); 
		if (frame.empty())
			break;
		//读取数据
		Mat blob = dnn::blobFromImage(frame, 1.0, Size(300, 300), Scalar(104, 177, 123), false, false); //1.0还是0-255的色彩空间 false 不进行rgb通道的交换 false视频不剪切
		net.setInput(blob);//准备数据 NCHW C通道 H高度 W宽度
		Mat probs = net.forward(); //
		Mat detectionMat(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
		//解析结果
		for (int i = 0; i < detectionMat.rows; i++) {
			float confidence = detectionMat.at<float>(i, 2);
			if (confidence > 0.5) {
				int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
				int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
				int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
				int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);
				Rect box(x1, y1, x2 - x1, y2 - y1);
				rectangle(frame, box, Scalar(0, 0, 255), 2, 8, 0);
			}
		}
		imshow("人脸检测", frame);

		
		int c = waitKey(1);
		if (c == 27)
			break;
	}
}