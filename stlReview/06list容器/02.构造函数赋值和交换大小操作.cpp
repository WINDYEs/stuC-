#include<iostream>
#include<list>
using namespace std;

void printList(const list<int>& li) 
{
	for (list<int>::const_iterator it = li.begin(); it != li.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl;
}


void test() 
{
	list<int>li;//默认构造

	///添加元素
	li.push_back(10);
	li.push_back(20);
	li.push_back(30);

	printList(li);// 10 20 30


	//区间
	list<int>li2(li.begin(), li.end());
	printList(li2);// 10 20 30

	//拷贝
	list<int>li3(li);
	printList(li3);// 10 20 30


	//n个元素
	list<int>li4(6, 6);
	printList(li4);// 6 6 6 6 6 6
}


//赋值操作
void test2() 
{
	list<int>li;
	li.push_back(12);
	li.push_back(13);
	li.push_back(14);
	li.push_back(15);
	printList(li);//12 13 14 15 
	list<int>li2;
	li2 = li;//operator= 赋值
	printList(li2);//12 13 14 15 


	list<int>li3;
	li3.assign(li2.begin(),li2.end());//assign区间赋值
	printList(li3);////12 13 14 15 

	list<int>li4;
	li4.assign(8, 7);//assign n个元素赋值
	printList(li4);//7 7 7 7 7 7 7 7

	list<int>li5;
	li5.assign(7, 8);//8 8 8 8 8 8 8
	printList(li5);
	//交换 
	li5.swap(li4);
	printList(li4);//8 8 8 8 8 8 8
	printList(li5);//7 7 7 7 7 7 7 7
	cout << "Before the exchange \n";


	li5.swap(li4);
	cout << "After the exchange\n";
	printList(li4);//7 7 7 7 7 7 7 7
	printList(li5);//8 8 8 8 8 8 8

}


//大小操作
void test3() 
{
	list<int>li;
	li.push_back(2);
	li.push_back(3);
	li.push_back(4);
	li.push_back(5);
	printList(li);//2 3 4 5

	//判断容器是否为空
	if (li.empty()) {
		cout << "li is empty \n";
	
	}else {
		cout << "li not empty \n";
		cout << " li elememt is " << li.size() << endl; //4
	}

	//重新指定大小 
	//li.resize(7);//多出来的默认以0填充
	//printList(li);
	li.resize(8,7);	//指定大小, 默认元素  指定默认元素 
	printList(li);//2 3 4 5 7 7 7 7



}

void test4() 
{

}


int main() {
	test();
	test2();
	test3();
	system("pause");
	return 0;

}