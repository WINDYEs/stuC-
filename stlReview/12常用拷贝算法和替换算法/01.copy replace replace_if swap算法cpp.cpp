#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void myPrint(int val) 
{
	cout << val << "  ";
}

class MyCompare 
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};



//copy算法 容器指定范围的元素拷贝到另一个元素容器中

//copy(起始迭代器,结束迭代器,目标起始迭代器)
void test() 
{
	vector<int>v;
	v.push_back(12);
	v.push_back(11);
	v.push_back(13);
	v.push_back(14);
	vector<int>v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

}


//replace算法 
//将区间内旧元素替换成新元素 所有相同的元素都替换
//replace(起始迭代器,结束迭代器,旧元素,新元素);
void test2()
{
	vector<int>v;
	v.push_back(8);
	v.push_back(9);
	v.push_back(15);
	v.push_back(16);
	cout << "Before replace \n";
	for_each(v.begin(), v.end(), MyCompare());
	cout << endl;
	replace(v.begin(), v.end(), 13, 23);
	cout << "After replace \n";
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

}

class Greater11 
{
public:
	bool operator()(int val) 
	{
		return val > 11;
	}
};


//replace_if算法 按条件替换元素 满足条件的替换成指定元素
//replace_if(起始迭代器,结束迭代器,谓词,新元素)
void test3()
{
	vector<int>v;
	v.push_back(8);
	v.push_back(9);
	v.push_back(13);
	v.push_back(14);
	replace_if(v.begin(), v.end(), Greater11(), 12);
	for_each(v.begin(), v.end(), MyCompare());
	cout << endl;
}

//swap算法 互换两个容器的元素
//swap(container c1, container c2);
void test4()
{
	cout << "Before exchange------ \n";
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	vector<int>v2;
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(7);
	v2.push_back(8);
	v2.push_back(9);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
	
	cout << "After exchange------ \n";
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

}

int main() {
	test4();
	system("pause");
	return 0;

}