#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
using namespace std;

//accumulate�㷨 ��������������Ԫ��ֵ���ۼ�
//accumulate(��ʼ������,����������,��ʼֵ)

void myPrint(int val) 
{
	cout << val << "  ";
}

void test() 
{  
	vector<int>v;
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	//accumulate ��ͷ�ļ� numeric��
	int res = accumulate(v.begin(), v.end(), 100);
	//for_each(v.begin(), v.end(), myPrint);
	cout << res ;

}

//fill�㷨 �����������ָ����Ԫ��
//fill(��ʼ������,����������,����ֵ)
void test2()
{
	vector<int>v;
	/*v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);*/
	v.resize(12);
	fill(v.begin(), v.end(), 5);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

}
int main() {
	test2();
	system("pause");
	return 0;

}