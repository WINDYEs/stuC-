#include<iostream>
using namespace std;
/*
	int find(const string& int pos = 0) const; 查找str第一次出现位置， 从pos开始查找
	int find(const char* s  int pos = 0) const; 查找s第一次出现位置， 从pos开始查找
	int find(const char* s int pos, int n) const; 从pos位置查找s的前n个字符第一次位置， 
	int find(const char c int pos = 0) const; 查找字符c第一次出现的位置
	int rfind(const string& int pos = npos) const; 查找str最后一次位置，从pos开始查找
	int rfind(const char* s int pos = npos) const; 查找s最后一次出现位置，从pos开始查找
	int rfind(const char* s int pos, int n) const; 从pos查找s的前n个字符最后一次位置
	int rfind(const char c int pos = 0) const; 查找字符c最后一次出现位置

	string& replace(int pos, int n, const string& str); 替换从pos开始n个字符为字符串str
	string& replace(int pos, int n, const char* s); 替换从pos开始的n个字符为字符串s

*/

const

void test() 
{
	string str1 = "abcdkyfcd";
	string str2 = "d";
	//cout << str1.find(str2) << endl;


	int pos = str1.find("cd"); //未找到返回-1
	cout << "pos: " << pos << endl;//2


	//rfind 和find的区别
	//rfind最后一次出现位置 find是第一次出现位置
	pos = str1.rfind("cd");

	cout << "rfind pos: " << pos << endl;//7
}

//替换
void test2()
{
	string str1 = "aavsad";
	str1.replace(1, 3, "2222");//从1到3的字符替换为参数列表中的字符串
	cout << "replace: " << str1 << endl;//a2222ad 替换字符串大于覆盖范围 字符串会扩充
}

/*
	string比较 意义判断是否相等 谁大谁小意义不大 


*/

void test03() 
{
	string str1 = "hello";
	string str2 = "world";
	//比较两者之间的ascii码是否相等 相等就返回0 str1小于str2 就返回-1 大于就返回1
	if (str1.compare(str2) == 0) 
	{
		cout << "str1 equal str2 \n";
	}
	else if (str1.compare(str2) < 0)
	{
		cout << str1.compare(str2) << endl;
		cout << "str1 not equal str2 \n"; //not equal
	} 
}



//string 字符存储
void test04()
{
	string str = "HELLO";
	//1.通过[] 访问单个字符
	for (int i = 0; i < str.size(); i++) 
	{
		cout << str[i] << " ";
	
	}
	cout << endl; //H E L L O
	//2. 通过at方式访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";//H E L L O

	}
	cout << endl;
	str[0] = 'a'; //下标修改字符 
	str.at(1) = 'b';
	cout << "str: " << str << endl;//abLLO
}
int main() {
	test();
	test2();
	test03();
	test04();
	system("pause");
	return 0;

}