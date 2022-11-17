#include<iostream>
#include<deque>
using namespace std;

//deque容器 双端数组，可以对头端进行插入删除操作 deque内部的中控器

/*
	deque和vector的区别
	vector 对头部操作效率低 数据越大 效率越低 
	deque相对 vector效率要高 速度要快
	vector 访问元素的速度比deque要快 这是两者的内部实现有关
*/

//迭代器设置为只读取
template<typename T>
void printDeque(const deque<T>&d) 
{
	for (typename deque<T>::const_iterator it = d.begin(); it != d.end(); it++) 
	{
		//*it = 100; 容器值无法修改现在是只读状态
		if(it == d.end() - 1) {
			cout << *it;
			break;
		}
		cout << *it << ",";
	}
	cout << endl;

}


void test() 
{
	deque<int>d1;
	for (int i = 0; i < 5; i++) 
	{
		d1.push_back(i);
	
	}
	printDeque(d1);// 0,1,2,3,4

	deque<int>d2(d1.begin(), d1.end());//区间
	printDeque(d2);// 0,1,2,3,4

	deque<char>d3(5, 'b');//n个elem
	printDeque(d3);// b,b,b,b,b

	deque<char>d4(d3);//对象
	printDeque(d4);// b,b,b,b,b


}


//赋值操作
void test2()
{
	deque<int>d;
	for (int i = 0; i < 5; i++)
	{
		d.push_back(i+1);

	}
	printDeque(d);//1,2,3,4,5
	//=赋值
	deque<int>d2;
	d2 = d;
	printDeque(d2);//1,2,3,4,5

	//assign赋值
	deque<int>d3;//区间赋值
	d3.assign(d.begin() + 1, d.end() - 1);
	printDeque(d3);//2,3,4


	deque<char>d4;//n个elem
	d4.assign(2, 'a');
	printDeque(d4);//a,a

}


//大小操作
void test3()
{
	//deque是没有容量的 可以无限开辟空间
	deque<int>d;
	for (int i = 0; i < 5; i++)
	{
		d.push_back(i + 2);

	}
	printDeque(d);//2,3,4,5,6
	
	if (d.empty()) //判断是否为空 为空为true 否则为false
	{
		cout << "d is empty " << endl;
	}
	else 
	{
		cout << "d is not empty " << endl;
		cout << "d size is " << d.size() << endl;//5
	}

	//重新指定大小
	//d.resize(7); 
	printDeque(d);//扩展后的数据默认 用0填充 2,3,4,5,6,0,0
	d.resize(7,4);
	printDeque(d);//2,3,4,5,6,4,4
	d.resize(4); //指定比原来小就会舍弃末端数据
	printDeque(d);//2,3,4,5

}


int main() {
	test();
	test2();
	test3();
	system("pause");
	return 0;

}