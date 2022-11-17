#include<iostream>
#include<vector>
using namespace std;

class Person 
{
public:
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	
	}
	//列表初始化
	// Person(string, int):m_Name(), m_Age(){} 

	string m_Name;
	int m_Age;

};

void test() 
{
	vector<Person>v; //定义存储Person对象的vector容器

	Person p1("aaa", 10);
	Person p2("bbb", 12);
	Person p3("ccc", 13);
	Person p4("ddd", 14);

	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//遍历容器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//解引用为对象
		cout << "name: " << (*it).m_Name <<  "age: " << (*it).m_Age << endl;
		//cout << "name: " << it->m_Name << "age: " << it->m_Age << endl;
		
	}
}

	//存放自定义数据类型 指针
void test02() 
{
		vector<Person*>v;

		Person p1("aaa", 10);
		Person p2("bbb", 22);
		Person p3("ccc", 23);
		Person p4("ddd", 24);

		//向容器中添加数据
		v.push_back(&p1);
		v.push_back(&p2);
		v.push_back(&p3);
		v.push_back(&p4);

		//遍历容器
		for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) 
		{
			cout << "姓名： " << (*it)->m_Name << "年龄： " << (*it)->m_Age << endl;
		}

}





int main() { 
	//test(); 
	test02();
	system("pause");
	return 0;

}