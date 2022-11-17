#include<iostream>
using namespace std;
/*
	函数对象的概念：
		重载函数调用操作符的类，其对象称为函数对象
		函数对象使用重载的()时， 行为类似函数调用，也叫仿函数
		
		本质：
		函数对象(仿函数)是一个类，不是一个函数


		特点：
		函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值 
		函数对象超出普通函数的概念 函数对象可以有自己的状态
		函数对象可以作为参数传递

*/

class MyAdd
{
public:
	//函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值 
	int operator()(int v1, int v2) 
	{
		return v1 + v2;
	}


};

//函数对象超出普通函数的概念 函数对象可以有自己的状态
class MyPrint 
{
public:
	MyPrint() 
	{
		this->count = 0;//初始化
	}
	void operator()(string test) 
	{
		cout << test << endl;//输出传入的字符串
		this->count++;//1
	}
	int count; //内部自己状态 有自己成员
};






void test() 
{
	MyAdd myadd;
	cout << myadd(10,20)<< endl ;//30

}


void doPrint(MyPrint& mp, string test)
{
	//函数对象可以作为参数传递
	mp(test);

}

void test2() 
{
	MyPrint myp;
	myp("hello");//1
	myp("hello");
	myp("hello");
	myp("hello");
	myp("hello");//5 
	cout << "myp use frequency is " << myp.count << endl;//5
}


void test3() 
{
	MyPrint mp;
	doPrint(mp, "fuck you"); //fuck you
	cout << mp.count << endl; //1
}


int main() {
	test();
	test2();
	test3();
	system("pause");
	return 0;

}