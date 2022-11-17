#include<iostream>
using namespace std;

/*
	string和 char*的区别
	char* 是一个指针
	string是一个类 类内部封装char* 管理这个字符串 是char*型的容器

	string内部的成员方法
	查找find 拷贝copy 删除delete 插入insert 替换replace
	
	构造函数原型 
	string() //创建一个空的字符串 例如string str;
	string(const char* s); 使用字符串s初始化
	string(const string& str); 使用string对象初始化另一个string对象 
	string(int n,char c); 使用n个字符c初始化

	**/
void test()
{
	string s1;//默认构造
	cout << &s1 << endl;//输出空字符的地址
	const char* str = "hello";//使用字符串str初始化
	string s2(str);
	cout << s2 << endl;//hello
	string s3(s2);//使用后string对象初始化另一个string对象
	cout << s3 << endl;//hello
	string s4(3, 'a');
	cout << s4 << endl;//aaa


}


int main() {
	test();
	system("pause");
	return 0;

}