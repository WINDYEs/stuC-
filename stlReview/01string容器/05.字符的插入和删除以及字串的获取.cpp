#include<iostream>
using namespace std;

//string插入和删除

void test() 
{
	string str = "hello";
	//insert
	str.insert(1, "aaa"); //从第1号位置插入三个aaa 只是插入不是替换不会把 原本在1号位置的字符替换掉
	cout << str << endl;//haaaello

	//delete
	str.erase(1, 3); //从1号位删除 3个字符 (1，3) 1为字符删除的位置 3是删除几个字符 
	cout << str << endl;//hello
}


//string 字串
void test02() 
{ 
	string str = "helloworld";
	string substr = str.substr(0, 5); //第几个位置开始截取 截取几个字符(0, 5)0号位开始截取 5个字符
	cout << "substr = " << substr << endl;//hello

	string email = "nimasile@sina.com";
	int pos = email.find("@"); //返回的是@字符所在的位置 从0开始数 //8
	string username = email.substr(0, pos);//0位置开始截取8个字符
	cout << username << endl;//nimasile
}
int main() {
	test();
	test02();
	system("pause");
	return 0;

}