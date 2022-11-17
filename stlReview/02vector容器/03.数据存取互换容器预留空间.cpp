#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void printVector(vector<T>& v) 
{
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}

//数据存取
void test() 
{
	vector<int>v;
	for (int i = 0; i < 5; i++) 
	{
		v.push_back(i + 2);
	}
	printVector(v);// 2 3 4 5 6

	//利用中括号方式访问数组元素
	for (int i = 0; i < v.size(); i++) 
	{
		cout << v[i] << "\t";
		
	}
	cout << endl; //2	3	4	5	6
	//利用at方式访问数组元素
	for (int i = 0; i < v.size(); i++) 
	{
		cout << v.at(i) << "\t";
	}
	cout << endl;//2	3	4	5	6

	//获取第一个元素
	cout << "The first one elem is " << v.front() << endl;//2 
	//返回最后一个元素
	cout << "The last one elem is " << v.back() << endl;//6
}


//互换容器
void test2()
{
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i + 1);
	}
	printVector(v);//1 2 3 4 5
	vector<int> v2;
	for (int i = 10; i > 5; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);//10 9 8 7 6


	cout << "Before the exchange------------- \n";
	v.swap(v2);
	printVector(v);//10 9 8 7 6
	printVector(v2);//1 2 3 4 5

	//实际用途 巧用swap可以收缩内存空间
	


}

void test2_2() 
{
	vector<int> v1;
	for (int i = 0; i < 10000; i++)
	{
		v1.push_back(i);
	}

	cout << "The capacity of v " << v1.capacity() << endl;//16384
	cout << "size of v " << v1.size() << endl;//10000
	v1.resize(4);
	cout << "The capacity of v " << v1.capacity() << endl;//16384 resize会变大capacity的大小 但是不会缩小capacity的大小
	cout << "size of v " << v1.size() << endl;//4


	// reserve()只修改capacity大小，不修改size大小，
	// resize()既修改capacity大小，也修改size大小。


	//使用匿名对象巧妙回收capacity的浪费空间 匿名对象在执行完后就会回收
	vector<int>(v1).swap(v1);// vector<int>(v1)匿名对象和 v1对象互换指向堆区数据的指针
	cout << "The capacity of v " << v1.capacity() << endl;//4
	cout << "size of v " << v1.size() << endl;//4
}


//预留空间 减少vector在动态扩展容量时的扩展次数
void test3()
{
	vector<int>v;
	//只要知道要存储多少数据 利用reserve预留空间 就不需要动态扩展了
	v.reserve(10000);
	int num = 0;//统计数组存储数据时 动态扩展容量的次数
	int* p = NULL;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		if (p != &v[0]) //指针不等于数组的首地址 
		{
			p = &v[0];//就把数组首地址 赋值给指针p
			num++;//次数++
		}
	}
	cout << "num = " << num << endl; //1 p等于首地址故num只加1次


}

int main() {
	test();
	test2();
	test2_2();
	test3();
	system("pause");
	return 0;

}