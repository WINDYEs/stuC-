#include<iostream>
#include<list>
using namespace std;

class Person 
{
public:
	Person(string name, int age, int height) 
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	
	}

	string m_Name;
	int m_Age;
	int m_Height;

};


template<typename T>
void printList(const list<T>& li) 
{
	for (typename list<T>::const_iterator it = li.begin(); it != li.end(); it++) 
	{
		cout << "name: " << (*it).m_Name << " age: " << (*it).m_Age << " height: " << (*it).m_Height << endl ;
	}
}

//指定排序规则
bool comParePerson(Person& p1, Person& p2) 
{ 
	//按照年龄 升序 

	if (p1.m_Age == p2.m_Age) 
	{
		//年龄相同按照身高降序
		return p1.m_Height > p2.m_Height;
	}
	else 
	{
		return p1.m_Age < p2.m_Age;
	}


}


void test() 
{
	list<Person>li;//链表存储Person对象
	//准备数据
	Person p1("jack", 13, 178);
	Person p2("rose", 12, 178);
	Person p3("jess", 10, 148);
	Person p4("mark", 12, 158);

	
	li.push_back(p1);
	li.push_back(p2);
	li.push_back(p3);
	li.push_back(p4);
	printList(li);//jack rose jess mark
	cout << "Before the sort---------------\n";
	//按年龄排序 同年龄按身高排序
	li.sort(comParePerson);
	cout << "After the sort---------------\n";
	printList(li);//jess rose mark jack
}

int main() {
	test();
	system("pause");
	return 0;

}