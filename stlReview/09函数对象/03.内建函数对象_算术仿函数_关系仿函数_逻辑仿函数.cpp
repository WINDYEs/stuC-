#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;


//使用内建函数对象 需要加入头文件#include<functional>


//算数仿函数 
//negate 一元仿函数 取反

//plus 二元仿函数 加法
//minus 二元仿函数 减法
//multiplies 二元仿函数 乘法
//divides 二元仿函数 除法
//modulus 二元仿函数 取模

void test() 
{
	negate<int>n;
	cout << n(50) << endl;//-50

	plus<int>p;
	cout << p(10, 20) << endl; //30
}

//关系仿函数 实现关系的对比
//bool equal_to 等于
//bool not_equal 不等于
//bool greater 大于
//bool greater_equal 大于等于
//bool less	小于
//bool less_equal 小于等于

class MyCompare {

public:
	bool operator()(int v1, int v2) 
	{
		return v1 > v2;//降序
	}
};

void test2()
{
	vector<int>v;
	v.push_back(12);
	v.push_back(13);
	v.push_back(11);

	//升序
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << *it << "  ";

	}
	cout << endl;//11 12 13
	//降序
	//sort(v.begin(), v.end(),MyCompare());
	sort(v.begin(), v.end(), greater<int>());//<elemtype> 大于 
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";

	}
	cout << endl;//13 12 11
	
}

//逻辑仿函数 
//bool	logical_and 逻辑与 two true is true  other is false 
//bool	logical_or 逻辑或	two false is false  one true is true
//bool	logical_not 逻辑非  true is false	false is true
void test3()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl; // 1 0 0 1

	//利用逻辑非 将容器1搬运到容器2 ，并进行取反操作
	vector<bool>v2;
	v2.resize(v.size());//复制容器1的大小 给容器2 不开辟空间是无法搬运的


	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>()); 
	//搬运(被搬运的起始区间,被搬运的结尾区间,搬运的起始区间,执行的操作)
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl; //0 1 1 0


}

int main() {
	test();
	test2();
	test3();
	system("pause");
	return 0;

}