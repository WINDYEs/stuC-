#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>//stl的算法头文件
//vector 容器存放内置数据类型

void myPrint(int val) 
{
	cout << val << endl;
}
void test() 
{
	vector<int> v;
	//向容器插入数据
	v.push_back(10);//vector 提供的尾插法 
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin(); //起始迭代器 指向容器中第一个元素
	vector<int>::iterator itEnd = v.end(); //结束迭代器	指向容器中最后一个元素的下一个位置
	// //第一种遍历方式
	// while (itBegin != itEnd) 
	// {
	// 	//类似于指向第一个元素的指针
	// 	cout << *itBegin << endl;
	// 	itBegin++;
	// }


	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << *it << endl;
	}


	//第三种遍历方式 利用stl提供的遍历方式
	//for_each(v.begin(), v.end(), myPrint);
	//加入algorithm头文件 使用for_each(起始迭代器，结尾迭代器， 提供的函数 );
}

int main() {
	test();
	system("pause");
	return 0;
}