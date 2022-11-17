#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Person 
{
public:
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//int operator == (vector<Person>& v)
	//{
	//	int count = 0;
	//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) 
	//	{
	//		if ((*it).m_Name == this.m_Name && this->m_Name && p.m_Age == this->m_Age)
	//		{
	//			count++;
	//		}
	//	
	//	}
	//	
	//}

	//运算符==重载
	bool operator==(const Person& p) 
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name) 
		{
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

//binary_search  查找指定元素 查到返回true 否则false
//注意无法在无序序列中使用
void test() 
{
	vector<int>v;
	v.push_back(12);
	v.push_back(14);
	v.push_back(13);
	v.push_back(15);
	//sort(v.begin(), v.end());
	bool pos = binary_search(v.begin(), v.end(),16);//false

	if (pos) 
	{
		cout << "element is true\n";
	}
	else 
	{
		cout << "element is false\n";//1
	}

}


//count 统计元素个数  返回int类型数据
//count(开始迭代器,结束迭代器，统计的元素)
void test2()
{
	//内置数据类型
	/*vector<int>v;
	v.push_back(12);
	v.push_back(12);
	v.push_back(12);
	v.push_back(13);
	int res = count(v.begin(), v.end(), 12);
	cout << "equal elements is " << res << endl;*/

	//自定义数据
	vector<Person>v;
	Person p1("jack", 12);
	Person p2("jack", 13);
	Person p3("rose", 12);
	Person p4("jack", 12);
	Person p5("jack", 12);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int res = count(v.begin(), v.end(), p1); //3
	cout << "和jack同龄同名的人数有 " << res << endl;//3
}


class Count01 
{
public:
	bool operator()(int val) 
	{
	/*	if (val == 12) 
		{
			return true;
		}
		else 
		{
			return false;
		}*/
		return val == 12;
		
	}

	bool operator()(const Person& p) 
	{
		return p.m_Age > 20;
	}
};

//count_if 按条件统计元素个数
//count_if(开始迭代器,结束迭代器,谓词)
void test3()
{

	////内置数据类型
	//vector<int>v;
	//v.push_back(12);
	//v.push_back(13);
	//v.push_back(12);
	//v.push_back(15);
	//int res = count_if(v.begin(), v.end(), Count01());
	//cout << "等于12的元素有 " << res << "个\n";



	//自定义数据
	vector<Person>v;
	Person p1("jack", 12);
	Person p2("jack", 23);
	Person p3("rose", 22);
	Person p4("jack", 12);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	int res = count_if(v.begin(), v.end(), Count01());
	cout << "大于20岁的人有 " << res << "个\n"; //2
}
int main() {
	test();
	test2();
	test3();
	system("pause");
	return 0;

}