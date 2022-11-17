#include<iostream>
#include<map>
using namespace std;


void printMap(map<int,int>&m) 
{	//key-value
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) 
	{
		cout << "key: " << (*it).first << " value: " << (*it).second << endl;
	}
	cout << endl;

}

/*
	map 所有元素都是pair
	pair 第一元素是 key值 起到索引作用 第二个元素为value值
	所有元素都会根据元素的key值进行排序

	本质 map/multimap属于关联式容器 底层结构是用二叉树实现

	优点 可以根据key值快速找到value值 
	map和multimap的区别 
	map不允许有重复key值元素 multimap允许容器中有重复的key值元素
*/



//构造赋值
void test() 
{
	//默认构造
	map<int, int>m;
	//插入用insert和set容器一样 所有元素都会根据元素的key值进行排序
	m.insert(pair<int, int>(1, 10));//pair<int, int>(1, 10)匿名对组 放到m对组中
	m.insert(pair<int, int>(3, 20));
	m.insert(pair<int, int>(2, 30));

	printMap(m);// 1 10 2 30 3 20

	//拷贝构造
	map<int, int>m2(m);
	printMap(m2);// 1 10 2 30 3 20


	//赋值 operator= 
	map<int, int>m3;
	m3 = m2;
	printMap(m3);// 1 10 2 30 3 20
}


//大小和操作 
void test2()
{
	map<int, int>m;
	m.insert(pair<int, int>(0, 1));
	m.insert(pair<int, int>(1, 2));
	m.insert(pair<int, int>(2, 3));
	m.insert(pair<int, int>(3, 4));
	printMap(m);//01 12 23 34
	if (m.empty()) 
	{
		cout << "M is empty \n";
	}
	else 
	{
		cout << "M is not empty he size is " << m.size() << endl;//4
	}

	
	map<int, int>m2;
	m2.insert(pair<int, int>(4, 5));
	m2.insert(pair<int, int>(5, 6));
	m2.insert(pair<int, int>(6, 7));
	m2.insert(pair<int, int>(7, 8));
	cout << "Before the exchange-----\n";
	printMap(m);//01 12 23 34
	printMap(m2);//45 56 67 78
	
	//交换
	m.swap(m2);
	cout << "After the exchange-----\n";
	printMap(m);//45 56 67 78
	printMap(m2);//01 12 23 34

}


//插入和删除
void test3()
{
	//插入
	map<int,int>m;
	m.insert(pair<int, int>(1, 2));
	m.insert(pair<int, int>(2, 3));
	m.insert(pair<int, int>(3, 4));
	m.insert(pair<int, int>(4, 5));

	//第二种插入 制造对组
	m.insert(make_pair(5, 6));
	

	//第三种
	//m.insert(map<int, int>::value_type(5, 7));key相同 添加不了
	//第四种
	m[6] = 8;//cout << m[7] 会默认创建一个m[7]的值 但是value值为0 
	printMap(m);//12 23 34 45 56 68
	//删除 
	//map<int, int>::iterator it = m.end();
	//m.erase(m.begin()); 
	//m.erase(--it);//删除map容器中的最后一个元素 因为m.end()指向的是数组最后一个元素的下一位指针

	//区间删除
	//m.erase(m.begin(),++m.begin());//erase(闭区间,开区间);删除不包括开区间本身其他所有的值 所以只删除了第一个元素

	//key值删除
	m.erase(6);//按key值删除 没有不删除 输入value是不会删除的
	printMap(m);//12 23 34 45 56
	
	////清空
	////m.clear();
	//if (m.empty())
	//{
	//	cout << "M is empty \n";
	//}
	//else
	//{
	//	cout << "M is not empty he size is " << m.size() << endl;
	//}


}

//查找和统计
void test4()
{
	//查找
	map<int, int>m;
	m.insert(make_pair(1, 2));
	m.insert(make_pair(2, 3));
	m.insert(make_pair(3, 4));
	m.insert(make_pair(3, 5)); //不能有 相同的key 没有插入
	m.insert(make_pair(4, 7));
	printMap(m);//12 23 34 47
	//参数是key值 按照传入的值来查找value  find返回的是迭代器
	map<int, int>::iterator pos = m.find(4); 
	if (pos != m.end()) 
	{
		cout << " Find the elements key = " << (*pos).first << " value: " << (*pos).second << endl; //47
	}
	else 
	{
		cout << "Not find the element \n";
	}
	


	//统计
	//map不允许插入重复的key 所以count只能是1或0 其他可以存储重复值的容器则会返回相同元素的个数
	int num = m.count(7); //map中有是1 没有是0
	cout << " num = " << num << endl; //1



}



int main() {
	test();
	test2();
	test3();
	test4();
	system("pause");
	return 0;

}