#include<iostream>
#include<vector>
using namespace std;



void test() 
{
	vector< vector<int> > v; //vector 中 嵌套vector v是 大容器中的对象

	//创建小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;

	//向小容器添加数据
	for (int i = 0; i < 4; i++) 
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//将小容器插入到大容器中
	v.push_back(v1);// 1,2,3,4
	v.push_back(v2);// 2,3,4,5
	v.push_back(v3);// 3,4,5,6
	v.push_back(v4);// 4,5,6,7


	//通过大容器 把所有数据遍历
	for (vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++) 
	{
		//(*it)  ---- 容器vector<int>
		//		it是大容器的指针指向的是每一个小容器元素 (*it)就是指向大容器存储小容器的地址 
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) 
		{
			//*vit 就是指向小容器存储int类型的元素地址 
			cout << *vit << "  ";
		
		}
		cout << endl;
	}

}


int main() {
	test();
	system("pause");
	return 0;

}