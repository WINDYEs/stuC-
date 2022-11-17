#include<iostream>
#include<stack>
using namespace std;


//stack容器是先进后出接口 它只有一个出口 栈是先进后出结构 栈不允许有遍历行为 只有栈顶元素才可以访问

//
void test() 
{
	stack<int>s;

	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈的大小 ： " << s.size() << endl;//4
	//只要栈不为空 查看栈顶元素 并执行出栈
	while(!s.empty())
	{
		//查看栈顶元素
		cout << "top " << s.top() << endl; //top 40 top 30 top 20 top 10
		//出栈
		s.pop();

	}
	cout << "栈的大小 ： " << s.size() << endl;//0
}

void test2() 
{


}
int main() {
	test();
	
	system("pause");
	return 0;

}