#include<iostream>
#include<string>
#include<vector>
using namespace std;

//vector容器 数组是静态空间 vector是静态空间 动态扩展不是在原有空间扩展 而是另找一个更大的空间存储原有的数据 然后释放原有空间
/*
	利用函数模板 会发生报错 语法错误: 意外的令牌“标识符”，预期的令牌为“;” 解决办法 打开 属性 > c/c++  > 语言 > 符合模式改为否 


*/

template<typename T>
void printVector(vector<T>& v1) 
{
	for (typename vector<T>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << "  ";//解引用获取元素
	
	}
	cout << endl;
}
void test() 
{ 
	/*
		vector函数原型 
		vector<T> v;
		vector(v.begin(), v.end()); v.begin指向第一个元素 v.end()指向的是最后一个元素的下一个位置 把begin 到 end之间的元素拷贝给本身
		vector(n, elem) 构造函数 把n个elem拷贝给本身
		vector(const vector &vec); 拷贝构造函数

	*/

	vector<int>v1;
	for (int i = 0;  i < 10; i++) {
		v1.push_back(i);
	}

	printVector(v1);
	//通过区间方式构造
	vector<int>v2(v1.begin(), v1.end()); // 把v1存储的元素全部赋值给v2
	printVector(v2);//0 1 2 3 4 5 6 7 8 9 

	//通过n个elem的值构造 
	vector<char>v3(10, 'a');
	printVector(v3);//a a a a a a a a a a 


	//拷贝构造
	vector<char>v4(v3);
	printVector(v4);
}

int main() {

	test();
	system("pause");
	return 0;

}