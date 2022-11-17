#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
using namespace std;

//accumulate算法 返回容器中所有元素值的累加
//accumulate(起始迭代器,结束迭代器,起始值)

void myPrint(int val) 
{
	cout << val << "  ";
}

void test() 
{  
	vector<int>v;
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	//accumulate 在头文件 numeric中
	int res = accumulate(v.begin(), v.end(), 100);
	//for_each(v.begin(), v.end(), myPrint);
	cout << res ;

}

//fill算法 向容器中填充指定的元素
//fill(起始迭代器,结束迭代器,填充的值)
void test2()
{
	vector<int>v;
	/*v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);*/
	v.resize(12);
	fill(v.begin(), v.end(), 5);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

}
int main() {
	test2();
	system("pause");
	return 0;

}