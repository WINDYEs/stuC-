#include<iostream>
#include<set>
#include<string>
using namespace std;

class Person 
{
public:
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;

};

void printSet(set<int>&s) 
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl;
}


//内置类型指定排序规则

//set 容器排序
class myCompare 
{

public:
	bool operator ()(int v1,int v2) const//
	{
		return v1 > v2; 
	}
};


void test() 
{
	set<int>s;
	s.insert(13);
	s.insert(12);
	s.insert(15);
	s.insert(11);
	printSet(s);//系统默认以升序排好数据 // 11 12 13 15

	//指定排序规则为从大到小
	set<int, myCompare>s2;
	s2.insert(13);
	s2.insert(12);
	s2.insert(15);
	s2.insert(11);
	cout << " s2 ----------- \n";

	for (set<int, myCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "  ";//降序
	}
	cout << endl;
	//15 13 12 11

}

class comParePerson 
{
public:
	bool operator()(const Person& p1,const Person& p2)const 
	{
		//按照年龄升序
		return p1.m_Age < p2.m_Age;
	}
};
void test2() 
{
	//自定义数据指定排序规则
	set<Person, comParePerson>s;
	Person p1("jack", 12);
	Person p2("aack", 11);
	Person p3("jack", 12);//元素都相同只显示 一个 名字相同 年龄可以显示
	Person p4("rack", 15);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comParePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << " name: " << (*it).m_Name << " age: " << (*it).m_Age << endl;
	}
	//aack 11 jack 12 rack 15

}
using namespace std;

int main() {
	test();
	test2();
	system("pause");
	return 0;

}