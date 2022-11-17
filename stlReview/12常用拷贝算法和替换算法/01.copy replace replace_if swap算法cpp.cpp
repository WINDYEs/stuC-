#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void myPrint(int val) 
{
	cout << val << "  ";
}

class MyCompare 
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};



//copy�㷨 ����ָ����Χ��Ԫ�ؿ�������һ��Ԫ��������

//copy(��ʼ������,����������,Ŀ����ʼ������)
void test() 
{
	vector<int>v;
	v.push_back(12);
	v.push_back(11);
	v.push_back(13);
	v.push_back(14);
	vector<int>v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

}


//replace�㷨 
//�������ھ�Ԫ���滻����Ԫ�� ������ͬ��Ԫ�ض��滻
//replace(��ʼ������,����������,��Ԫ��,��Ԫ��);
void test2()
{
	vector<int>v;
	v.push_back(8);
	v.push_back(9);
	v.push_back(15);
	v.push_back(16);
	cout << "Before replace \n";
	for_each(v.begin(), v.end(), MyCompare());
	cout << endl;
	replace(v.begin(), v.end(), 13, 23);
	cout << "After replace \n";
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

}

class Greater11 
{
public:
	bool operator()(int val) 
	{
		return val > 11;
	}
};


//replace_if�㷨 �������滻Ԫ�� �����������滻��ָ��Ԫ��
//replace_if(��ʼ������,����������,ν��,��Ԫ��)
void test3()
{
	vector<int>v;
	v.push_back(8);
	v.push_back(9);
	v.push_back(13);
	v.push_back(14);
	replace_if(v.begin(), v.end(), Greater11(), 12);
	for_each(v.begin(), v.end(), MyCompare());
	cout << endl;
}

//swap�㷨 ��������������Ԫ��
//swap(container c1, container c2);
void test4()
{
	cout << "Before exchange------ \n";
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	vector<int>v2;
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(7);
	v2.push_back(8);
	v2.push_back(9);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
	
	cout << "After exchange------ \n";
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

}

int main() {
	test4();
	system("pause");
	return 0;

}