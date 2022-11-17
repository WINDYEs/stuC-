#include<iostream>
#include<queue>
using namespace std;


//queue是一种先进先出的数据结构 它有两个出口

/*
	队列容器允许一端新增元素 另一端移除数据
	队列只有头和尾元素可以被外界使用 也不可以遍历
	进 为入队push	出 为出队pop
*/
class Person 
{
public:

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;

	}

	int m_Age;
	string m_Name;
};

void test() 
{
	//创建队列
	queue<Person>q;
	//准备数据
	Person p1("jac", 12);
	Person p2("ac", 22);
	Person p3("jc", 32);
	Person p4("c", 42);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "队列大小为： " << q.size() << endl; //4 
	//判断只要对列不为空 查看队头队尾元素  对头出队 队尾入队
	while (!q.empty()) 
	{
		cout << q.front().m_Name  << "  " << q.front().m_Age << endl;//jac 12 ac 22 jc 32 c 42

		cout << q.back().m_Name << "  "  << q.back().m_Age << endl;//c 42 c 42 c 42 c 42
		
		//出队
		q.pop();//c 42 	jc 32 ac 22 jac 12
	
	}

	cout << "队列大小为： " << q.size() << endl; //0

}
int main() {
	test();
	system("pause");
	return 0;

}