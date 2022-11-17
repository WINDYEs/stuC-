#include<iostream>
#include<set>
using namespace std;

void printSet(set<int>& s) 
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void printMulSet(multiset<int>& s)
{
	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//set multiset 的区别
void test() 
{
	set<int>s;
	pair<set<int>::iterator, bool> ret = s.insert(12); // 返回的是对组pair <迭代器,布尔值>
	if (ret.second) //取得布尔值
	{
		cout << "The first insertion is  was successful \n";//1
	}
	else 
	{
		cout << "The first insertion is was failed\n";
	}


	s.insert(14);
	s.insert(13);
	s.insert(15);
	ret = s.insert(12); //set不可以有重复元素 ret取得false
	printSet(s);// 12 13 14 15
	if (ret.second) //取得布尔值 
	{
		cout << "The second insertion is  was successful \n";
	}
	else
	{
		cout << "The second insertion is was failed\n";//1
	}

	multiset<int>ms;//不检测数据 不会返回 布尔值
	ms.insert(12);
	ms.insert(12);
	ms.insert(12);
	printMulSet(ms);// 12 12 12


}


//对组 成对出现的数据 利用对组可以返回两个数据
void test2() 
{
	//第一种方式
	pair<string, int>p("jack", 21);
	cout << "name : " << p.first << " age : " << p.second << endl; // jack 21

	//第二种方式
	pair<string, int>p2 = make_pair("rose", 22);
	cout << "name : " << p2.first << " age : " << p2.second << endl; // rose 22
}
int main() {
	test();
	test2();
	system("pause");
	return 0;

}