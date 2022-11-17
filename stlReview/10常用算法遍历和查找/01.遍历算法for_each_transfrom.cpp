#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void print01(int val) 
{
	cout << val << "  ";
}

class print02
{
public:
	void operator()(int val) 
	{
		cout << val << "\t";
	}
};

//常用遍历算法 
void test() 
{
	vector<int>v;
	for (int i = 0; i < 5; i++) 
	{
		v.push_back(i);
	}
	//普通
	for_each(v.begin(), v.end(), print01);
	cout << endl;// 0 1 2 3 4 
	//仿函数
	for_each(v.begin(), v.end(), print02());
	cout << endl;//0	1	2	3	4
}


class Transform 
{
public:
	int operator()(int v) 
	{
		return 110 + v;
	}
};

//transform算法(beg(源容器开始迭代器,源容器结束迭代器,目标容器开始迭代器,函数或函数对象)
void test2() 
{
	vector<int>v;
	v.push_back(14);
	v.push_back(15);
	v.push_back(16);
	v.push_back(17);
	vector<int>v2;
	//目标容器提前开辟空间
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(),Transform()); 
	
	//遍历
	for_each(v2.begin(), v2.end(), print02());
	cout << endl; //124	125	126	127

}


int main() {
	test();
	test2();
	system("pause");
	return 0;

}