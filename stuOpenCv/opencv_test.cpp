#include <opencv2/opencv.hpp>
#include "quickOpencv.h"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argcm, char** argv) {
	Mat src = imread("E:/pic/nops.png"); //��ȡͼ��	ͼƬ·��,ͼƬɫ�ʿռ��ģʽ
	//src�������ö������ʾ��1 ��ʵ��24λ��ΪͼƬ����ɫͨ����24һ��ͨ����8λ ��ȡ��˳���� B G R
	if (src.empty())
	{
		printf("clould not loading the pic\n");
		return -1;
	}
	//namedWindow("pic", WINDOW_FREERATIO);//����:��������,ͼƬ��ʾ��ģʽ ���Ӳ��� Ĭ��ΪWINDOW_AUTOSIZE �޷��޸Ĵ��ڴ�С
	imshow("RGB", src); //��ʾͼ�� ����:��������,Mat�洢ͼƬ�Ķ���
	
	
	QuickDemo qd; 
	//qd.colorSpace_Demo(src); ����hsv ��gray ͼ
	//qd.mat_creation_demo(src); ͼ�����Ĵ��� �Լ����ɵ�һ��ɫ����
	//qd.pixel_Visit_Demo(src); �±�ָ�����ͼ�����صĶ�д����
	//qd.operators_Demo(src); //���������ı�ͼ��
	//qd.tracking_Bar_Demo(src); //����������ͼ������ �Աȶ�
	//qd.key_Demo(src); �����������ͼƬģʽ
	//qd.color_Style_Demo(src); opencv �Դ���ͼ��ģʽ
	//qd.bitwise_Demo(src); ͼ����߼�����
	//qd.channers_Demo(src); //ͨ���ķ���ͺϲ�
	//qd.inrange_Demo(src); //ͼ��ɫ�ʿռ�ת�� ʵ����ĻͼƬ�����񻻱���
	//qd.pixel_Statistic_Demo(src);//ͼ������ֵͳ�� ���ֵ��Сֵ ��ֵ�ͷ���
	//qd.drawing_Demo(src); //ͼ�񼸺λ��� ���� Բ�� ��Բ ��
	//qd.random_Drawing_Demo(); //���������������
	//qd.polyline_Drawing_Demo(); //����εĻ��������
	//qd.mouse_Drawing_Demo(src); //����������Ӧ
	//qd.norm_Demo(src); //ͼ����������ת���͹�һ��
	//qd.resize_Demo(src); //ͼ������Ͳ�ֵ
	//qd.flip_Demo(src); //ͼ��ת
	//qd.rotate_Demo(src); //ͼ����ת
	//qd.camera_Demo(src); //����ͷ����
	//qd.show_Histogram_Demo(src); //����ͼ��ֱ��ͼ
	//qd.show_Histogram2D_Demo(src); //���ƶ�άֱ��ͼ
	//qd.histogram_Eq_Demo(src); //ֱ��ͼ���⻯
	//qd.blur_Demo(src); //ͼ��������
	//qd.gaussian_Blur_Demo(src); //��˹ģ��
	// qd.bifilter_Demo(src);	//��˹˫��ģ��
	qd.face_Detection_Demo(); //�������
	waitKey(0);//0 һֱ����
	destroyAllWindows();//�������е���ʾ����
	return 0;
}