#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
template<typename T>
const void printDeque(deque<T> &d) 
{
	for (typename deque<T>::const_iterator it = d.begin(); it != d.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl;
}


//deque容器插入和删除
void test() 
{
	deque<int>d;

	//尾插
	d.push_back(1);
	d.push_back(2);
	//1 2

	//头插
	d.push_front(3);
	d.push_front(4);//头部为最新一个头插为主
	//4 3 1 2
	printDeque(d);//4 3 1 2

	//尾删
	d.pop_back();
	printDeque(d);// 4 3 1

	//头删
	d.pop_front();
	printDeque(d);// 3 1

}


//插入 
void test2() 
{
	deque<int>d;
	d.push_back(11);
	d.push_back(21);
	d.push_front(31);
	d.push_front(41);
	printDeque(d);// 41 31 11 21

	//insert 插入 
	d.insert(d.begin(), 120); //从头部插入 
	printDeque(d);// 120 41 31 11 21

	d.insert(d.begin(),	2, 100); //插入位置，插入的个数，插入的元素 
	printDeque(d);//100 100 120 41 31 11 21 


	//按照区间进行插入
	deque<int>d2;
	d2.push_back(88);
	d2.push_back(99);
	d.insert(d.begin(), d2.begin(), d2.end()); 
	printDeque(d);//88 99 100 100 120 41 31 11 21



	cout << "delete------\n";
	//删除
	deque<int>::iterator it = d2.begin();
	//it++;//指向了begin()的下一个元素
	//d2.erase(d2.begin(), d2.end());//区间删除
	d2.clear();
	printDeque(d2);

}


//数据存取
void test3() 
{
	deque<int>d;
	d.push_back(70);
	d.push_back(80);
	d.push_back(90);
	d.push_back(100);//70 80 90 100
	d.push_front(60);
	d.push_front(50);
	d.push_front(40);
	d.push_front(30);
	//printDeque(d);//30 40 50 60 70 80 90 100


	//通过[]访问元素
	for (int i = 0; i < d.size(); i++) 
	{
		cout << d[i] << "  ";
	}
	cout << endl;//30 40 50 60 70 80 90 100

	cout << "this is a dividing line-----------------\n";

	//通过at访问元素
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << "  ";
	}
	cout << endl;//30 40 50 60 70 80 90 100

	//访问头尾元素 
	cout << " deque the first one elem is " << d.front() << endl;//第一个元素 30
	cout << "deque the last one elem is " << d.back() << endl; //最后一个元素 100

}



//deque容器的排序操作
void test4()
{
	deque<int>d;
	d.push_back(12);
	d.push_back(22);
	d.push_back(32);
	d.push_back(2);//12 22 32 2
	d.push_front(3);
	d.push_front(4);
	d.push_front(1);
	d.push_front(9);
	printDeque(d);//9 1 4 3 12 22 32 2

	//排序 使用标准模板算法需要加入头文件 
	sort(d.begin(), d.end());//(开始 ，结尾) 升序从小到大

	cout << "After sorting\n";
	printDeque(d);//1 2 3 4 9 12 22 32 
}

int main() {
	test();
	test2();
	test3();
	test4();
	system("pause");
	return 0;

}