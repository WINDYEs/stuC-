#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class print01 
{
public:
	void operator()(int v) 
	{
		cout << v << "  ";
	}

};


class Person 
{
public:
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//重载 底层find == 知道如何对比Person数据类型
	bool operator==(const Person& p) 
	{ 
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{//名字和年龄相同才返回true
			return true;
		}
		else 
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;

};

//find 算法 查找返回指点元素的迭代器 ，找不到返回结束迭代器
//find(开始迭代器,结束迭代器,查找的元素);
void test() 
{
	vector<int>v;
	for (int i = 0; i < 5; i++) 
	{
		v.push_back(i + 2);
	}
	//查找内置数据类型
	//vector<int>::iterator it = find(v.begin(), v.end(), 3);
	//
	//if (it != v.end()) 
	//{
	//	cout << " 3 is  vector the element \n";
	//	cout << *it << endl;
	//}
	//else
	//{
	//	cout << "3 is not vector the element\n";
	//}


	//查找自定义数据类型
	vector<Person>v2;
	//创建数据
	Person p1("jack", 13);
	Person p2("jess", 43);
	Person p3("rose", 33);
	Person p4("mac", 23);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);

	Person pp("mac", 23);
	vector<Person>::iterator it = find(v2.begin(), v2.end(),pp);

	if (it == v2.end())
	{
		cout << "p2 is not vector the element\n";
	}
	else
	{
		
		cout << " p2 is  vector the element \n";
		cout << " name: " << it->m_Name << " age: " << it->m_Age << endl; //mac 23

	}



}

//find_if算法 查找返回指点元素的迭代器 ，找不到返回结束迭代器
//find_if (开始迭代器,结束迭代器,函数或者谓词);

class GreaterThree 
{
public:
	bool operator()(int v1) 
	{
		return v1 > 3;
	}
};

class GreaterPerson
{
public:
	bool operator()(Person &p1)
	{
		if (p1.m_Age > 20) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
};

void test2() 
{
	//内置数据类型
	/*vector<int>v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i + 2);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterThree());

	if (it == v.end()) 
	{
		cout << "Not find the Greater to 3 the element\n";
	}
	else 
	{
		cout << " Find the greater to 3 the element \n";
		cout << *it << endl;
	}*/

	//自定义数据
	vector<Person>v2;
	//创建数据
	Person p1("jack", 13);
	Person p3("rose", 33);
	Person p2("jess", 43);
	Person p4("mac", 23);
	v2.push_back(p1);
	v2.push_back(p3);
	v2.push_back(p2);
	v2.push_back(p4);

	//Person pp("mac", 23);
	vector<Person>::iterator it = find_if(v2.begin(), v2.end(), GreaterPerson());

	if (it == v2.end())
	{
		cout << " The vector person age is Not Greater than 20\n";
	}
	else
	{

		cout << " The vector person age greater than 20  \n";
		cout << " name: " << it->m_Name << " age: " << it->m_Age << endl;//rose 33

	}


}

//adjacent_find算法 查找相邻重复的元素 查到返回相邻元素的第一个位置的迭代器
//adjacent_find(开始迭代器，结束迭代器)
void test3() 
{
	vector<int>v;
	v.push_back(11);
	v.push_back(12);
	v.push_back(11);
	v.push_back(11);
	vector<int>:: iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) 
	{
		cout << "没有相邻元素\n";
	}
	else 
	{
		cout << "有相邻元素\n";
		cout << *it << endl;//11
	}

}

int main() {
	test();
	test2();
	test3();
	system("pause");
	return 0;

}