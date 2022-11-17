#include<iostream>
#include<map>
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



class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		//降序
		return v1 > v2;
	}

	bool operator()(Person &p1, Person &p2) const
	{
		if (p1.m_Name == p2.m_Name) 
		{
			//同名升序
			return p1.m_Age < p2.m_Age;//行不通 因为有个key值已经默认有先后了
		}
		else 
		{
			//降序
			return p1.m_Age > p2.m_Age;
		}
	
		
	}
};



void printMap(map<int,int, MyCompare>&m)
{
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
			cout << "key: " << (*it).first << " value: " << (*it).second << endl;
	}
	cout << endl;

}

void printMap(map<int, Person, MyCompare>& m)
{
	for (map<int, Person, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << (*it).first << " name: " << (*it).second.m_Name << " age: " << (*it).second.m_Age << endl;
	}
	cout << endl;

}





//map容器 排序
void test() 
{
	map<int, int, MyCompare>m;
	m.insert(make_pair(1, 20));
	m.insert(make_pair(5, 30));
	m.insert(make_pair(3, 40));
	m.insert(make_pair(4, 50));
	printMap(m);// 5 30 	4 50 	3 40 	1 20
	Person p1("jack", 13);
	Person p2("jack", 23);
	Person p3("rose", 33);
	Person p4("mac", 43);
	cout << " This is dividing line-------- \n";
	
	map<int,Person, MyCompare>m2;
	m2.insert(make_pair(5, p1));
	m2.insert(make_pair(4, p2));
	m2.insert(make_pair(6, p3));
	m2.insert(make_pair(7, p4));
	printMap(m2);//7mac 43 6rose 33  4jack 23 5jack 13

	




}

void test2() 
{

}



int main() {
	test();
	system("pause");
	return 0;

}