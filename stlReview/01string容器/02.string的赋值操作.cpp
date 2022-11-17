#include<iostream>
using namespace std;
/*
string& operator=(const char* s); char*类型的字符串 赋值给当前的字符串
string& operator=(const string &s); 把字符串s赋值给当前的字符串
string& operator=(char c); 字符赋值给当前的字符串


string& assign=(const char* s); 把字符串s赋值给当前的字符串
string& assign=(const char* s, int n);把字符串s前n个字符赋值给当前的字符串
string& assign=(const string* s); 把字符串s赋值给当前的字符串
string& assign=(int n  char c); 用n个字符c赋给当前的字符串

*/

void test() 
{
	string str1;
	str1 = "hello";
	cout << "str1: " << str1 << endl; //hello
	string str2;
	str2 = str1;
	cout <<  "str2: " << str2 << endl;//hello


	string str3;
	str3 = 'a';
	cout << "str3: " << str3 << endl;//a

	string str4;
	str4.assign("ggg");
	cout << "str4: " << str4 << endl;//ggg


	string str5;
	str5.assign("gggaabb",4);// 把"gggaabb" 的前四个字符赋值给 str5 
	cout << "str5: " << str5 << endl;//ggga


	string str6;
	str6.assign(str5);
	cout << "str6: " << str6 << endl;//ggga


	string str7;
	str7.assign(4,'b');
	cout << "str7: " << str7 << endl;//bbbb
}

int main() {
	test();
	system("pause");
	return 0;

}