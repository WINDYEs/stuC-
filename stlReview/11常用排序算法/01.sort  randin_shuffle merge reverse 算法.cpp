#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<ctime>
using namespace std;


class MyCompare 
{
public:
	bool operator()(int v1,int v2) 
	{
		return v1 > v2;
	}

};

void myPrint(int val)
{
	cout << val << "  ";
}


//sort �㷨  sort(��ʼ������,����������,ν��)
void test() 
{
	vector<int>v;
	v.push_back(12);
	v.push_back(11);
	v.push_back(15);
	v.push_back(10);
	//sort(v.begin(), v.end());//Ĭ������

	//sort(v.begin(), v.end(),MyCompare());//ʹ��ν�ʸı�Ϊ����
	sort(v.begin(), v.end(),greater<int>());//ʹ�������ڽ��������� ����greater<typename>()
	for_each(v.begin(), v.end(), myPrint);
	

}

		//ϴ���㷨
//random_shuffle(��ʼ������,����������) ָ����Χ�ڵ�Ԫ�������������
void test2() 
{
	vector<int>v;
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);

	//ϴ���㷨����Ԫ��˳��
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);

}


//merge�㷨 ��������Ԫ�غϲ� ���洢����һ��Ԫ��������
//ע���������������������
//merge(����1����ʼ������,����1�Ľ���������,����2����ʼ������,����2�Ľ���������,Ŀ����������ʼ������)

void test3() 
{
	vector<int>v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);
	vector<int>v2;
	//һ������ һ�����������Ҳ���� ������ͬһ������
	v2.push_back(19);
	v2.push_back(20);
	v2.push_back(21);
	v2.push_back(22);

	vector<int>v3;
	//��ǰ��Ŀ���������ٿռ�
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin());
	for_each(v3.begin(), v3.end(), myPrint);
	cout << endl;

}


//reverse�㷨 ��������Ԫ��˳����з�ת
//reverse(��ʼ������,����������);
void test4() 
{
	vector<int>v;
	/*v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);*/
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	cout << "Before reverse-----\n";
	for_each(v.begin(), v.end(), myPrint);
	
	cout << endl;

	cout << "After reverse------\n";
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

}
int main() {
	//������������
	srand((unsigned int)time(NULL));
	test4();
	system("pause");
	return 0;

}