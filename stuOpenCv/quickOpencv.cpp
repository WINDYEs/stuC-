#include "quickOpencv.h"
#include <opencv2/dnn.hpp>
using namespace std;
using namespace cv;
void QuickDemo::colorSpace_Demo(Mat& image) {
	Mat gray, hsv;
	cvtColor(image,hsv,COLOR_BGR2HSV); //RGB תHSV
	// H��S��V 0-180,  H����ɫ S�����Ͷ� V������
	cvtColor(image,gray,COLOR_BGR2GRAY); //RGB תgray
	imshow("HSV", hsv);
	imshow("GRAY", gray);
	imwrite("E:/pic/hsv.png", hsv);
	imwrite("E:/pic/gray.png", gray);
}


void QuickDemo::mat_creation_demo(Mat& image) {
	Mat m1, m2; //�����������ͼƬ��� ����ͼƬ�߶� 
	m1 = image.clone(); //��¡
	image.copyTo(m2); //����


	//�����հ�ͼ��
	Mat m3 = Mat::zeros(Size(400, 400), CV_8UC3); //����4��4�еĿհ׾��� 8λ���޷���char ��ͨ��1�����ص��һ������ֵ ��ͨ������1�����ص� 3������ֵ 
	//Mat m3 = Mat::ones(Size(4, 4), CV_8UC1); ע��ʹ��ones ��ʱ������������ͨ�� ��ֻ���ڵ�һ��ͨ������Ϊ1 ����ͨ����������


	m3 = Scalar(0,255,0);// Scalar��������ͨ����ֵ��ͨ�������ü���ֵ

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
	int width = image.cols; //��ȡ���
	int height = image.rows; //��ȡ�߶�
	int dims = image.channels(); //��ȡͨ����


	//�±���ʸı�ͼ�����ز���
	/*
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (dims == 1) { //�Ҷ�ͼ��
				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv; //��ȡ�Ҷ�ͼ�����ص㣻
			}
			if (dims == 3) { //����
				Vec3b bgr = image.at<Vec3b>(row, col);
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];//��ȡ����ͼ�����ص�B��
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];//��ȡ����ͼ�����ص�G��
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];//��ȡ����ͼ�����ص�R��
			}
		}
	}
	*/
	

		//ָ����ʸı�ͼ�����ز���
	for (int row = 0; row < height; row++) {
		uchar* current_row = image.ptr<uchar>(row); //��ȡ��ָ��
		for (int col = 0; col < width; col++) {
			if (dims == 1) { //��ͨ���Ҷ�ͼ��
				*current_row++ = 255 - *current_row; //++ָ����һ�����ص�
				
			}
			if (dims == 3) { //��ͨ������
				*current_row++ = 255 - *current_row; //ָ��ͬһ�����ص� ��һ��ͨ��
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}


	imshow("���ص���ʾ", image);

}


void QuickDemo::operators_Demo(Mat& image) {
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(2, 2, 2);


	//�ӷ�����ʵ��
	//int width = image.cols; //��ȡ���
	//int height = image.rows; //��ȡ�߶�
	//int dims = image.channels(); //��ȡͨ����

	//for (int row = 0; row < height; row++) {
	//	for (int col = 0; col < width; col++) {
	//		if (dims == 3){
	//			Vec3b p1 = image.at<Vec3b>(row, col);
	//			Vec3b p2 = m.at<Vec3b>(row, col);
	//			dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);//dstͼ��ԭ�������ص��50
	//			dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
	//			dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
	//		}
	//	}
	//}
	//add(image, m, dst); //���� ������ �洢��
	//subtract(image, m, dst); -
	//multiply(image, m, dst); *
	divide(image, m, dst); // /
	imshow("+50", dst); //��ʾ����50���imageͼ�� 
}

static void on_track(int lightness, void* imageData) {
	Mat image = *((Mat*)imageData);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(lightness, lightness, lightness);
	addWeighted(image, 1.0, m, 0, lightness, dst);
	imshow("������Աȶȵ���", dst);

}

static void on_contrast(int contrastValue,void* imageData) {
	Mat image = *((Mat*)imageData);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = contrastValue / 100.0;
	addWeighted(image, contrast, m, 0, 0, dst); //1���� ����Ȩ�� 2���� ����Ȩ�� �ںϺ������ֵ �洢���ںϺ������
	imshow("������Աȶȵ���", dst);

}



void QuickDemo::tracking_Bar_Demo(Mat& image) {
	namedWindow("������Աȶȵ���", WINDOW_AUTOSIZE);
	int max_value = 100;
	int lightness = 50; //��ʼ����Ϊ50
	int contrastValue = 50; //��ʼ�Աȶ�Ϊ50
	createTrackbar("value Bar:", "������Աȶȵ���", &lightness, max_value, on_track, &image);
	createTrackbar("Contrast:", "������Աȶȵ���", &contrastValue, 200, on_contrast, &image);
	//on_track(lightness, &image);
}

void QuickDemo::key_Demo(Mat& image) {
	Mat dst = Mat::zeros(image.size(),image.type());
	while (true)
	{
		char c = waitKey(0); //waitKey()--�����������һ��������ʱ����(��λms)�ȴ��û���������;����û�û�а��� ��,������ȴ�(ѭ��)
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
		imshow("��������", dst);
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
		imshow("��ɫģʽ", dst);
	}

}

void QuickDemo::bitwise_Demo(Mat& image) {
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 70, 70), Scalar(255, 0, 0), -1, LINE_8, 0); //-1����� ����0�ǻ��� LINE_8���
	rectangle(m2, Rect(140, 140, 70, 70), Scalar(0, 255, 0), -1, LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	//bitwise_and(m1, m2, dst);
	//bitwise_or(m1, m2, dst);
	//bitwise_not(image, dst); //dst = ~image;
	bitwise_xor(m1, m2, dst);
	imshow("����λ����", dst);
}


void QuickDemo::channers_Demo(Mat& image) {
	std::vector<Mat>mv;
	split(image, mv); //������ͨ�� �洢�� mv������ 
	//�ӵ�ͨ���ҶȲ���3ͨ��RGB
	//�����Ϊ��ͨ�����൱�ڷ���ͨ����ͬʱ����������ͨ���������ͬ����ֵ�������ɫͨ�����������ɫͨ����ͬʱ����ɫ����ɫ�����Ϊ�ͺ�ɫ��ͬ����ֵ������һ����ֻ�кڰ׻��ˡ�
	imshow("blue", mv[0]); //��ʾ��ͨ���ĻҶ�ͼ
	imshow("green", mv[1]);
	imshow("red", mv[2]);

	Mat dst;
	//��ɫ
	mv[1] = 0; //�޸���������ͨ����ֵ
	mv[2] = 0;
	merge(mv, dst); //�ӵ�ͨ���ҶȲ���3ͨ��RGB
	imshow("blue", dst);
	
	//��ɫ
	/*mv[0] = 0;
	mv[2] = 0;
	merge(mv, dst);
	imshow("green", dst);*/

	//��ɫ
	/*mv[0] = 0;
	mv[1] = 0;
	merge(mv, dst); 
	imshow("red", dst);*/

	int from_to[] = { 0,1, 1,2, 2,0 }; //image0ͨ�����Ƶ�dst1ͨ�� image1ͨ�����Ƶ�dst2ͨ�� image2ͨ�����Ƶ�dst0ͨ��
	mixChannels(&image, 1, &dst, 1, from_to, 3);
		/*��һ���������������
		�ڶ���������������������
		�������������������
		���ĸ�������������������
		����������������б�
		�����������������б��ǵ�ͨ������*/
	imshow("mixChannelS", dst);
}

void  QuickDemo::inrange_Demo(Mat& image) {
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV); //ͼƬת��Ϊhsvͼ�� �洢��hsv��
	Mat mask;
	inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask); //hsv��ʽͼƬ����hsv��ʽ������ɫ��Χ�����ֵ�洢��mask��
	imshow("mask", mask);

	Mat blueBack = Mat::zeros(image.size(), image.type());
	blueBack = Scalar(244, 12, 12); //��ͼƬ��С��ͬ����ɫ����ͼ
	bitwise_not(mask, mask);//������ɫ���������Ϊ��ɫ
	imshow("mask", mask);
	image.copyTo(blueBack, mask); //��˼����ɫ����ͼ���Եõ�һ��������ĤMASK��ͼƬ�ڸǺ���ͼ������Ĥ����������ֵ��ӦΪ0�ĵ��Ϊ��ɫ�����ڸǣ��������㣨���з�0ֵ����ԭ��һ��
	imshow("bluebackground", blueBack);

}

void QuickDemo::pixel_Statistic_Demo(Mat& image) {
	double minv, maxv;
	Point minPonit, maxPoint;
	std::vector<Mat> mv;
	split(image, mv); //image������ͨ���洢��mv
	for (int i = 0; i < mv.size(); i++) {
		minMaxLoc(mv[i], &minv, &maxv, &minPonit, &maxPoint);
		std::cout << "channels:" << i << "min pixel value is " << minv << " max pixel value is " << maxv << std::endl; //��ȡͼƬ�������С���ز����ض�Ӧ��ָ��
	
	}

	//����Сͼ���������ûʲô�仯
	Mat mean, stddev;
	Mat back = Mat::zeros(image.size(), image.type());
	back = Scalar(230, 12, 0);
	meanStdDev(back, mean, stddev); //��ȡback �ľ�ֵ�ͱ�׼��
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
	//�հ�ͼ�ϻ���Բ�κ;��� ��
	rectangle(bg, rect, Scalar(0, 255, 0), 2, 8, 0);//����Ҫ���Ƶ�ͼƬ,����, ���ε���ɫ��ʾ,���������ĺ��, lineType�ߵ�����, �������е�С��λ��
	circle(bg, Point(355, 290), 20, Scalar(10, 10, 230), -1, 8, 0); //Բ��Ҫ���Ƶ�ͼƬ,Բ����,�뾶,���Ƶ���ɫ , Բ�������ĺ��, lineType�ߵ�����, �������е�С��λ��
	line(bg, Point(125, 0), Point(335, 270), Scalar(255, 0, 0), 2, LINE_AA, 0);//��Ҫ���Ƶ�ͼƬ,�ߵ���ʼ����,�ߵ���ֹ����,���Ƶ���ɫ,�����ĺ��, lineType�ߵ�����, LINE_AA ����� �������е�С��λ�� 
	//������Բ
	RotatedRect rrt;
	rrt.center = Point(200, 100); //��ԲԲ������
	rrt.size = Size(100, 200); //width,height
	rrt.angle = 80.0; //��Բ�ĽǶ�
	ellipse(bg, rrt, Scalar(0, 255, 255), 2, 8);//��Բ��Ҫ���Ƶ�ͼƬ,��Բ��, ��Բ�ε���ɫ��ʾ,��Բ�������ĺ��, lineType�ߵ�����
	Mat dst;
	addWeighted(image, 0.7, bg, 0.4, 2, dst); //1���� ����Ȩ�� 2���� ����Ȩ�� �ںϺ������ֵ �洢���ںϺ������
	//imshow("����", image);
	imshow("�ں�", dst);
}

void QuickDemo::random_Drawing_Demo() {
	Mat canvas = Mat::zeros(Size(500,500),CV_8UC3); //������С ��ͨ��
	RNG rng((unsigned)time(NULL)); //ʹ��ϵͳʱ�䣨1970��1��1����ʱ������룬��ĿǰΪֹ�������� ������������Ϊ������ӡ�
	int width = canvas.cols;
	int height = canvas.rows;
	while (true)
	{
		int c = waitKey(10);//10msˢ��
		if (c == 27)
			break;
		int xStart = rng.uniform(0, width); //�������ʼ���� ��Χ ��0 �� �����Ŀ�ȴ�С
		int yStart = rng.uniform(0, height); //�������ʼ���� ��Χ ��0 �� �����ĸ߶ȴ�С
		int xEnd = rng.uniform(0, width); //����߽������� ��Χ ��0 �� �����Ŀ�ȴ�С
		int yEnd = rng.uniform(0, height); //����߽������� ��Χ ��0 �� �����ĸ߶ȴ�С

		int b = rng.uniform(0, 255); //���ͨ����ɫ ��Χ0 - 255
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);
		//������Χ���������
		//canvas = Scalar(0, 0, 0);����һ���߻��ƻ���Ϊ�ڱ�������һ�� ��չʾһ������
		line(canvas, Point(xStart, yStart), Point(xEnd, yEnd), Scalar(b, g, r), 1, LINE_AA, 0);
		//��Ҫ���Ƶ�ͼƬ,�ߵ���ʼ����,�ߵ���ֹ����,���Ƶ���ɫ,�����ĺ��, lineType�ߵ�����, LINE_AA ����� �������е�С��λ�� 
		imshow("����߻���", canvas);

	}

}

void QuickDemo::polyline_Drawing_Demo() {
	Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3); //���ƻ���
	//�������εĵ�
	Point p1(400, 200);
	Point p2(140, 100);
	Point p3(300, 210);
	Point p4(120, 300);
	Point p5(250, 450);
	std::vector<Point> pts; //����һάVector����
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);
	polylines(canvas, pts, true, Scalar(0, 255, 255), 2, LINE_AA, 0);/*
		image:����ͼ�� ,pts : ������������� ,isClosed : ָʾ���Ƶ������Ƿ�պϵı�־����������Ǳպϵģ���ú�����ÿ�����ߵ����һ�����㵽���һ���������һ���� ���Ƶ���ɫ ���Ƶĺ��, ������, �������е�С��λ ע�����ﲻ�������*/
	fillPoly(canvas, pts, Scalar(255, 0, 0), LINE_AA, 0);//�������

	//���ƶ�������
	std::vector<std::vector<Point>>polygons; //�����άvector���� �洢�����
	polygons.push_back(pts);//�洢�����
	drawContours(canvas, polygons, 0, Scalar(0,255,0), 2, LINE_AA); //���ƵĻ���, ��������飬����ڼ�������ε����� -1��������ж���� ��ɫ, ���, �ߵ����� �������ֱ�����
	imshow("���ƶ����", canvas);
}

Point sp(-1, -1); 
Point ep(-1, -1);
Mat temp;
static void on_draw(int event, int x, int y, int flags, void* userdata) {
	Mat image = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN) {
		sp.x = x; //��¼����������ʱ������
		sp.y = y;
		std::cout << "start point " << sp << std::endl;

	}
	else if (event == EVENT_LBUTTONUP) {
		ep.x = x; //��¼�������ſ�ʱ������
		ep.y = y;
		int width, height, rx, ry;
		if (ep.x != sp.x) { //����ƶ���Ч�Ż���ͼ��
			if (ep.x > sp.x && ep.y > sp.y) { //�����������»� 
				width = ep.x - sp.x; //Ҫ���Ƶľ��ο��  //���С
				height = ep.y - sp.y; //Ҫ���Ƶľ��θ߶�
				rx = sp.x;
				ry = sp.y;
			}
			else if (ep.x < sp.x && ep.y < sp.y) { //�����������ϻ�
				width = sp.x - ep.x;
				height = sp.y - ep.y;
				rx = ep.x;
				ry = ep.y;
			}
			else if (ep.x < sp.x && ep.y > sp.y) {//�����������»�
				width = sp.x - ep.x; //���С
				height = ep.y - sp.y;
				rx = ep.x; //��ͼ���Ǵ����Ͻ�Ϊԭ�㿪ʼ��ͼ�ģ����Ծ���Ҫ���Ͻ�ԭ�������
				ry = sp.y;

			}
			else if (ep.x > sp.x && ep.y < sp.y) {//�����������ϻ�
				width = ep.x - sp.x;
				height = sp.y - ep.y;
				rx = sp.x;
				ry = ep.y;

			}
			Rect box(rx, ry, width, height);//����ͼ�� ��ʼ���� �Ϳ��
			temp.copyTo(image); //�����ƶ����̵Ļ�ͼ����
			imshow("cutRect", temp(box)); //��û��Ƶľ��������ͼƬ
			rectangle(image, box, Scalar(255, 0, 255), 2, LINE_AA, 0);
			imshow("mouseDraw", image);
			sp.x = -1;//��ʼ����ʼ����
			sp.y = -1;
		}

	}
	else if (event == EVENT_MOUSEMOVE) { //��¼����ƶ�ʱ������
		if (sp.x > 0 && sp.y > 0) {
			ep.x = x;
			ep.y = y;
			int width, height, rx, ry;
			if (ep.x != sp.x) { //����ƶ���Ч�Ż���ͼ��
				if (ep.x > sp.x && ep.y > sp.y) { //�����������»� 
					width = ep.x - sp.x; //Ҫ���Ƶľ��ο��  //���С
					height = ep.y - sp.y; //Ҫ���Ƶľ��θ߶�
					rx = sp.x;
					ry = sp.y;
				}
				else if (ep.x < sp.x && ep.y < sp.y) { //�����������ϻ�
					width = sp.x - ep.x;
					height = sp.y - ep.y;
					rx = ep.x;
					ry = ep.y;
				}
				else if (ep.x < sp.x && ep.y > sp.y) {//�����������»�
					width = sp.x - ep.x; //���С
					height = ep.y - sp.y;
					rx = ep.x; //��ͼ���Ǵ����Ͻ�Ϊԭ�㿪ʼ��ͼ�ģ����Ծ���Ҫ���Ͻ�ԭ�������
					ry = sp.y;

				}
				else if (ep.x > sp.x && ep.y < sp.y) {//�����������ϻ�
					width = ep.x - sp.x;
					height = sp.y - ep.y;
					rx = sp.x;
					ry = ep.y;

				}
				Rect box(rx, ry, width, height);//����ͼ�� ��ʼ���� �Ϳ��
				temp.copyTo(image); //�����ƶ����̵Ļ�ͼ
				rectangle(image, box, Scalar(255, 0, 255), 2, LINE_AA, 0); //���Ƶ�ͼƬ��������û�л�ͼ����ԭͼ
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
	image.convertTo(image, CV_32F); //����ת�� CV_8UC3 -> CV_32FC3 8λ3ͨ�����޷���char���� תΪ 32λ3ͨ����float����
	std::cout << image.type() << std::endl;
	normalize(image, dst, 1.0, 0, NORM_MINMAX);
	std::cout << image.type() << std::endl; //����������ֵ��Χ0-1֮�� ������Ҫ��һ��
	imshow("ͼ�����ݹ�һ��", dst);

}

void QuickDemo::resize_Demo(Mat& image) {
	Mat zoomin, zoomout; //�Ŵ� ��С
	int height = image.rows;
	int width = image.cols;
	resize(image, zoomin, Size(2 * width, 2 * height), 0, 0, INTER_LINEAR); //ԭͼƬ �Ŵ�ͼƬ��ͼƬ�Ŵ�ĳߴ磬 (fx, fy��������С�Ŵ� ͼƬ��С�Ѿ����� ��fx,fyΪ0),INTER_LINEAR���Բ�ֵ 
	imshow("�Ŵ�", zoomin);

	resize(image, zoomout, Size(width / 2, height / 2), 0, 0, INTER_LINEAR); //ԭͼƬ ��СͼƬ��ͼƬ��С�ĳߴ磬 (fx, fy��������С�Ŵ� ͼƬ��С�Ѿ����� ��fx,fyΪ0),INTER_LINEAR���Բ�ֵ 
	imshow("��С", zoomout);
}

void QuickDemo::flip_Demo(Mat& image) {
	Mat dst, dst2, dst3;
	flip(image, dst, 0); //���·�ת
	flip(image, dst2, 1); //���ҷ�ת
	flip(image, dst3, -1); //180�ȷ�ת
	imshow("updownfilp", dst);
	imshow("lrfilp", dst2);
	imshow("180 filp", dst3);
}

void QuickDemo::rotate_Demo(Mat& image) {
	Mat dst, M;
	int width = image.cols;
	int height = image.rows;
	M = getRotationMatrix2D(Point2f(width / 2, height / 2), 30, 1.0);//ԭ��ͼ�������λ��, ��ת�ĽǶ�, ��ת������ű��� 
	double cos = abs(M.at<double>(0, 0)); //��ȡ��תͼƬ���cos sin
	double sin = abs(M.at<double>(0, 1));
	//��0��0���Ƿ������M�ĵ�һ�е�һ��Ԫ�ؾ���cos����0��1�����ǵ�һ�еڶ���Ԫ�ؾ���sin
	//�����ת����µĿ�Ⱥ͸߶�
	double newWidth = cos * width + sin * height;
	double newHeight = sin * width + cos * height;

	//��ȡ�µ�ͼ������
	M.at<double>(0, 2) += (newWidth / 2 - width / 2);
	M.at<double>(1, 2) += (newHeight / 2 - height / 2);
	//��ת������Ļᷢ���仯����Ҫ����ƫ������(0, 2)(1, 2)�ֱ����x��y��ƫ����
	
	//ʵ�ֵ�ͼ�����ת 
	warpAffine(image, dst, M, Size(newWidth, newHeight),INTER_LINEAR, 0, Scalar(0,255,255)); //ԭͼ, �洢��ת��ͼƬ, ��ת�ľ���, ��ת��ͼ���µĴ�С, ��ֵ��ʽ��0��������ɫ
	imshow("Rotate...", dst);
}

void QuickDemo::camera_Demo(Mat& image) {
	VideoCapture capture("E:/pic/pica.mov");
	double frame_width = capture.get(CAP_PROP_FRAME_WIDTH); //��ȡ��Ƶһ֡�Ŀ��
	double frame_height = capture.get(CAP_PROP_FRAME_HEIGHT); //��ȡ��Ƶһ֡�ĸ߶�
	double count = capture.get(CAP_PROP_FRAME_COUNT); //��ȡ��Ƶ����֡��
	double fps = capture.get(CAP_PROP_FPS);//��ȡ��Ƶһ���ж���֡��

	std::cout << "frame width: " << frame_width << std::endl;
	std::cout << "frame height: " << frame_height << std::endl;
	std::cout << "frame fps: " << fps << std::endl;
	std::cout << "frame count: " << count << std::endl;
	//��֧��mov��ʽ��Ƶ�ı���
	VideoWriter writer("E:/test.mov", capture.get(CAP_PROP_FOURCC), fps, Size(frame_width, frame_height), true);//��Ƶ·��, ���뷽ʽ, һ�����֡, ��Ƶ���, �Ƿ�����ɫ 
	Mat frame;
	while (true)
	{
		capture.read(frame); //
		if (frame.empty())
			break;
		imshow("frame", frame);

		writer.write(frame); //������Ƶ
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
	//��ͨ������
	std::vector<Mat> bgr_plane;
	split(image, bgr_plane);
	//�����������
	const int channels[1] = { 0 };
	const int bins[1] = { 256 }; //256���Ƶ�
	float hranges[2] = { 0 ,255 };
	const float* ranges[1] = { hranges };
	Mat b_hist;
	Mat g_hist;
	Mat r_hist;
	//����BLUE GREEN RED ͨ����ֱ��ͼ
	calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
	calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
	calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);


	//��ʾֱ��ͼ
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / bins[0]);
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	//��һ��ֱ��ͼ ������ͨ����ȡֵ�黯����Сһ�µķ�Χ
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//����ֱ��ͼ����
	for (int i = 1; i < bins[0]; i++) {
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255,0,0), 2, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
	}

	//��ʾֱ��ͼ
	namedWindow("Histogram Demo", WINDOW_AUTOSIZE);
	imshow("Histogram Demo", histImage);


}

void QuickDemo::show_Histogram2D_Demo(Mat& image) {
	//2Dֱ��ͼ Hɫ����S���Ͷȡ�V���� ֵ��Χ�ֱ��� [0,180)�� [0,255)�� [0,255)
	Mat hsv, hs_hist; 
	cvtColor(image, hsv, COLOR_BGR2HSV);
	int hbins = 30, sbins = 32; //���� = ͼ��ĻҶȵȼ� / bins
	int hist_bins[] = { hbins, sbins };
	float h_range[] = { 0 ,180 }; //hͨ��������ȡֵ��Χ
	float s_range[] = { 0 ,256 }; //s������ȡֵ��Χ
	const float* hs_ranges[] = { h_range, s_range };
	int hs_channels[] = { 0 ,1 };
	calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_ranges, true, false);
			//ͼ��,ͼ������,Ҫ��ȡֱ��ͼ��ͨ������, Mat(), �洢��2dֱ��ͼ, ֱ��ͼ��ά��, �洢ͨ����bins����, ��ȥͨ������ȡֵ��Χ����,true, false;
	double maxVal = 0;
	minMaxLoc(hs_hist, 0, &maxVal, 0, 0); //ȡ���ֵ
	int scale = 10;
	Mat hist2d_image = Mat::zeros(sbins * scale, hbins * scale, CV_8UC3); //����հ�ͼ��洢2άֱ��ͼ
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


//ֱ��ͼ���⻯ ���ǰ�ԭʼ��ֱ��ͼ�任Ϊ�������Ҷȷ�Χ��0~255���ھ��ȷֲ�����ʽ���Ӷ��������ػҶ�ֵ�Ķ�̬��Χ���ﵽ��ǿͼ������Աȶȵ�Ч��
void QuickDemo::histogram_Eq_Demo(Mat& image) {
	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("�Ҷ�ͼ��", gray);
	Mat dst;
	equalizeHist(gray, dst);//���ǰ�ֱ��ͼ��ÿ���Ҷ�ֵ���й�һ��������ÿ�ֻҶȵ��ۻ��ֲ������ŵõ�һ��ӳ��ĻҶ�ӳ���Ȼ�������Ӧ�ĻҶ�ֵ������ԭͼ�е�ÿ�����ء�
	imshow("ֱ��ͼ���⻯��ʾ", dst);
}

void QuickDemo::blur_Demo(Mat& image) {
	Mat dst;
	// blur�������Ƕ������ͼ��src���о�ֵ�˲�����dst���
	blur(image, dst, Size(3, 3), Point(-1, -1)); //Size Ϊ����˴�С Ĭ��ֵPoint(-1,-1)���������������Ǹ�ֵ�Ļ����ͱ�ʾȡ�˵�����Ϊê�㣬����Ĭ��ֵPoint(-1,-1)��ʾ���ê���ں˵����ġ�
	imshow("ͼ��ģ��", dst);

}

void QuickDemo::gaussian_Blur_Demo(Mat& image) {
	Mat dst;
	GaussianBlur(image, dst, Size(0, 0), 7, 0); 
	/*ksize����˹�ں˵Ĵ�С������ksize.width��ksize.height���Բ�ͬ�������Ƕ�����Ϊ��������������������⣩�����ߣ����ǿ�������ģ����Ƕ�����sigma���������
		sigmaX����ʾ��˹�˺�����X����ĵı�׼ƫ�
		sigmaY����ʾ��˹�˺�����Y����ĵı�׼ƫ���sigmaYΪ�㣬�ͽ�����ΪsigmaX�����sigmaX��sigmaY����0����ô����ksize.width��ksize.height���������*/
	imshow("��˹ģ��", dst);

}


void QuickDemo::bifilter_Demo(Mat& image) {
	Mat dst;
	bilateralFilter(image, dst, 0, 100, 3);
	imshow("˫��ģ��", dst);

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
		//��ȡ����
		Mat blob = dnn::blobFromImage(frame, 1.0, Size(300, 300), Scalar(104, 177, 123), false, false); //1.0����0-255��ɫ�ʿռ� false ������rgbͨ���Ľ��� false��Ƶ������
		net.setInput(blob);//׼������ NCHW Cͨ�� H�߶� W���
		Mat probs = net.forward(); //
		Mat detectionMat(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
		//�������
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
		imshow("�������", frame);

		
		int c = waitKey(1);
		if (c == 27)
			break;
	}
}