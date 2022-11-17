#include<iostream>
#include<set>
using namespace std;


//set 所有元素在插入的时候就已经帮你排好序了	底层是由二叉树实现
//构造赋值

//set 不允许插重复的元素
//multiset允许有重复的元素

void printSet(set<int>&s) 
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl;

}


void test() 
{
	set<int>s;
	//插入元素用insert 自动排序 不允许插入重复值 
	s.insert(30);
	s.insert(10);
	//s.insert(30);
	s.insert(20);
	//拷贝构造
	printSet(s);// 10 20 30
	set<int>s2(s);
	printSet(s2);// 10 20 30

	//赋值
	set<int>s3;
	s3 = s2;
	printSet(s3);// 10 20 30

}

//大小和交换
void test2() 
{
	set<int>s1;
	s1.insert(12);
	s1.insert(11);
	s1.insert(14);
	printSet(s1);// 11 12 14

	if (s1.empty()) 
	{
		cout << "s1 is empty \n";
	}
	else 
	{
		cout << "s1 is not empty he size is " << s1.size() << endl; //3
	}
	set<int>s2;
	s2.insert(7);
	s2.insert(18);
	s2.insert(9);
	s2.insert(11);

	printSet(s1);//11 12 14
	printSet(s2);// 7 9 11 18
	cout << "Before the exchange --------- \n";
	//交换 
	s1.swap(s2);
	cout << "After the exchange --------- \n";
	printSet(s1);// 7 9 11 18
	printSet(s2);//11 12 14




}


//插入和删除
void test3() 
{
	set<int>s1;

	//插入
	s1.insert(15);
	s1.insert(14);
	s1.insert(11);
	s1.insert(13);
	printSet(s1);// 11 13 14 15
	//删除
	s1.erase(s1.begin());//删除第一个元素
	s1.erase(15);//删除为15的元素
	printSet(s1);//13 14
	//清空
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
	
}



//查找和统计
void test4() 
{
	set<int>s;
	s.insert(31);
	s.insert(34);
	s.insert(32);
	s.insert(33);
	s.insert(33);
	s.insert(33);

	//set容器不能有重复值 所以count只能是1或0 其他可以存储重复值的容器则会返回相同元素的个数 
	cout << s.count(30) << endl; //0 


	set<int>::iterator pos =  s.find(31);//返回的是迭代器

	if (pos != s.end()) 
	{
		cout << " Find the element  he is " << *pos << endl; //31
	}
	else 
	{
		cout << " Not find the element\n";
	}


}

int main() {
	test();
	test2();
	test3();
	test4();
	system("pause");
	return 0;

}