#include<iostream>
#include<vector>
using namespace std;

//赋值操作
template<typename T>
void printVector(vector<T> &v) 
{
	
	for (typename vector<T> ::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test() 
{
	vector<int>v1;
	for (int i = 0; i < 5; i++) 
	{
		v1.push_back(i + 1);
	}

	printVector(v1);// 1 2 3 4 5


	//赋值 operator=
	vector<int>v2;
	v2 = v1;
	printVector(v2);// 1 2 3 4 5

	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end() - 1);//v1的区间赋值  不包括第二个参数的值
	printVector(v3);// 1 2 3 4

	//n个elem 方式赋值
	vector<char>v4;
	v4.assign(3, 'a');//个数 值
	printVector(v4);// a a a
}


//容量和大小
void test2()
{
	vector<int>v1;
	cout << "vector capacity is " << v1.capacity() << endl; //未放入数据为空 0
	for (int i = 0; i < 5; i++) 
	{
		v1.push_back(i + 2);
	}
	cout << endl;
	printVector(v1);// 2 3 4 5 6

	if (v1.empty())  //true vector is empty		false vector is not empty
	{
		cout << "vector v1 is empty \n";
	}
	else 
	{
		//放入数据后 容量变为6 比存储的数据 空余了一个位置
		cout << "vector v1 is not empty \n";
		cout << "vector capacity is " << v1.capacity() << endl; //8
		cout << "vector size is " << v1.size() << endl; //size大小永远都是小于等于容量capacity //5
	}

	//重新指定大小 
	//v1.resize(8); //扩充大小后 默认把未填充数据填为0 
	v1.resize(8, 8); //重载版本，可以指定默认填充数据 8
	printVector(v1); // 2 3 4 5 6 8 8 8
	cout << "vector capacity is " << v1.capacity() << endl; //8
	cout << "vector size is " << v1.size() << endl; //8

	v1.resize(5); //指定的比原来的小 会删除超出的数据
	printVector(v1); //2 3 4 5 6
	cout << "vector capacity is " << v1.capacity() << endl; //大size容量的1/2
	cout << "vector size is " << v1.size() << endl; //5 


}


//插入和删除
/*
	push_back(ele); 尾部 插入元素ele
	pop_back();		删除最后一个元素
	insert(const_iterator pos, ele);	迭代器指向位置pos插入元素ele	
	insert(const_iterator pos, int count, ele);	迭代器指向位置pos插入count个元素ele
	erase(const_itrator pos);	删除迭代器指向的元素
	erase(const_itrator start, const_itrator end);	删除迭代器从start到end之间的元素 
	clear();	删除容器中所有元素
*/

void test3()
{
	vector<int> v1;
	//尾插法插入数据
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	printVector(v1);	// 1 2 3 4

	//尾删法删除数据
	v1.pop_back();
	printVector(v1); // 1 2 3

	//插入
	v1.insert(v1.begin(),12); //(插入位置，元素)
	printVector(v1);// 12 1 2 3

	//插入重载
	v1.insert(v1.begin(),2,11); //(插入位置，插入元素个数， 元素)
	printVector(v1);// 11 11 12 1 2 3

	//删除 参数是迭代器
	v1.erase(v1.begin()); //删除元素位置 
	printVector(v1);//11 12 1 2 3
	//v1.erase(v1.begin(),v1.end()); //(删除元素位置, 结束删除元素位置) 就是这个区间元素全部删除
	//printVector(v1);

	//清空
	v1.clear();//元素全部删除 和 erase(开始元素位置v1.begin(),结束元素为v1.end()) 类似
	printVector(v1);
}

int main() {
	test();
	test2();
	test3();
	system("pause");
	return 0;

}