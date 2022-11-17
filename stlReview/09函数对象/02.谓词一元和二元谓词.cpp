#include<iostream>
#include<vector>
#include<algorithm>//标准算法头文件
using namespace std;
/*
	谓词概念 
	返回值是bool 的仿函数称为谓词
	如果 operator()接受一个参数 为一元谓词 
	如果 operator()接受两个参数 为二元谓词
*/
class GreaterThree 
{
public:
	bool operator()(int val) 
	{
		return val > 3; //传入数值大于3 true 小于3 false
	}

};
void test() 
{
	vector<int>v;
	for (int i = 0; i < 6; i++) {
		v.push_back(i);
	
	}
	//查找容器有没有大于3的数字
	//GreaterThree()匿名函数对象
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterThree()); //返回一个大于3的迭代器
	//(first,last,pred ) first 到 last 区间 pred 需要一个谓词
	if (it == v.end()) {
		cout << " Not find it\n";
	
	}
	else {
		cout << "Yes I found it and it is " << *it << endl; //4
	}
}

class MyCompare 
{
public:
	bool operator()(int v1, int v2) 
	{
		return v1 > v2;
	}
};

void test2() 
{
	vector<int>v;
	v.push_back(12);
	v.push_back(13);
	v.push_back(11);
	v.push_back(14);
	MyCompare my;
	//sort(v.begin(), v.end());
	//使用函数对像，改变排序规则 改为降序
	sort(v.begin(), v.end(),my);//降序
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl;// 14 13 12 11

}

int main() {
	test();
	test2();
	system("pause");
	return 0;

}