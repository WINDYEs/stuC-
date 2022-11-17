#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

class Imitation 
{
public:
	void operator()(int val) 
	{
		cout << val << "  ";
	}
};

//set_intersection�㷨	�����������Ľ��� ���غ��н�����Ŀ�������ĵ�����
//set_intersection(����1����ʼ������,����1�Ľ���������,����2����ʼ������,����2�Ľ���������,Ŀ����������ʼ������)
// 
// 
//ע����������������������

void test() 
{


	vector<int>v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);

	vector<int>v2;
	v2.push_back(12);
	v2.push_back(16);
	v2.push_back(17);
	v2.push_back(18);

	vector<int>v3;
	//����������������Ľ��� �պ�����С������size ʹ��min()�Ƚ�������СȻ��resize��ֵ��Ŀ������
	v3.resize(min(v1.size(),v2.size()));
 	vector<int>::iterator itEnd =  set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, Imitation());
	//for_each(v3.begin(), v3.end(), Imitation());//��v3.end()�������Ԫ�ض�����һ�飬ֻ����������Ԫ�ض��ǽ���������
	cout << endl;

}


//set_union �����������Ĳ��� ����������������
//set_union(����1����ʼ������,����1�Ľ���������,����2����ʼ������,����2�Ľ���������,Ŀ����������ʼ������)
void test2() 
{
	vector<int>v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);
	vector<int>v2;
	v2.push_back(12);
	v2.push_back(13);
	v2.push_back(15);
	v2.push_back(17);
	
	vector<int>v3;
	//����û�н���
	v3.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, Imitation());
	cout << endl;


}


//set_difference �����������Ĳ �������������ǽ����Ĳ���(�����Ƚϵ�˳��һ���Ҳ��һ��) ���������ཻ ��ô����� ���Ǳ���
// ע��Ҳ�Ǳ���������������� 
//set_difference(����1����ʼ������,����1�Ľ���������,����2����ʼ������,����2�Ľ���������,Ŀ����������ʼ������)
void test3() 
{
	vector<int>v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(17);
	vector<int>v2;
	v2.push_back(9);
	v2.push_back(11);
	v2.push_back(15);
	v2.push_back(16);
	v2.push_back(18);
	vector<int>Target;
	Target.resize(max(v1.size(), v2.size()));
	vector<int>:: iterator itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), Target.begin());
	cout << "v2 �� v1�Ĳ��\n";
	for_each(Target.begin(), itEnd, Imitation());
	cout << endl;


	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), Target.begin());
	cout << "v1 �� v2�Ĳ��\n";
	for_each(Target.begin(), itEnd, Imitation());
	cout << endl;




}


int main() {
	test3();
	system("pause");
	return 0;

}