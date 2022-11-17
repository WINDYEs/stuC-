#include<iostream>
using namespace std;

/*
	string& operator+= (const char* str;
	string& operator+= (const char c); 重载+=操作符
	string& operator+= (const string& str);
	string& append(const char* s);	//把字符串s连接到当前字符串结尾 
	string& append(const char* s, int n); //把字符串前n个字符连接到字符串结尾
	string& append(const string &s);	同第三个重载+=一样
	string& append(const string &s, int pos, int n); 字符串s中从pos开始的n个字符连接到字符串结尾	
*/
void test() 
{
	string str1 = "I";
		str1 += " love you";
		cout << str1 << endl;//"I love you"
		str1 += ' ';
		cout << str1 << endl;//"I love you "
		string str2;
		str2 += str1;
		cout << str2 << endl;//"I love you "

		str2.append(str1);
		cout << str2 << endl;//"I love you I love you "

		str2.append("aa");
		cout << str2 << endl;//"I love you I love you aa"

		str2.append("ha haa",4);//"I love you I love you aaha h"
		cout << str2 << endl;

		string str3;
		//str3.append(str2,1,4); //参数列表(string对象, 从第pos开始包括pos 到字符n的个数)
		str3.append(str2,0,4);
		cout << str3 << endl;// lov

	


}

int main() {
	test();
	system("pause");
	return 0;

}