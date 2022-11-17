#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

class Imitation 
{
public:
	void operator()(int val) 
	{
		cout << val << "  ";
	}
};

//set_intersection算法	求两个容器的交集 返回含有交集的目标容器的迭代器
//set_intersection(容器1的起始迭代器,容器1的结束迭代器,容器2的起始迭代器,容器2的结束迭代器,目标容器的起始迭代器)
// 
// 
//注意两容器必须是有序序列

void test() 
{


	vector<int>v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);

	vector<int>v2;
	v2.push_back(12);
	v2.push_back(16);
	v2.push_back(17);
	v2.push_back(18);

	vector<int>v3;
	//最特殊情况两容器的交集 刚好是最小容器的size 使用min()比较两者最小然后resize赋值给目标容器
	v3.resize(min(v1.size(),v2.size()));
 	vector<int>::iterator itEnd =  set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, Imitation());
	//for_each(v3.begin(), v3.end(), Imitation());//用v3.end()会把所有元素都遍历一遍，只有容器所有元素都是交集才适用
	cout << endl;

}


//set_union 求两个容器的并集 两容器必须是有序
//set_union(容器1的起始迭代器,容器1的结束迭代器,容器2的起始迭代器,容器2的结束迭代器,目标容器的起始迭代器)
void test2() 
{
	vector<int>v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);
	vector<int>v2;
	v2.push_back(12);
	v2.push_back(13);
	v2.push_back(15);
	v2.push_back(17);
	
	vector<int>v3;
	//特殊没有交集
	v3.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, Imitation());
	cout << endl;


}


//set_difference 求两个容器的差集 就是两容器不是交集的部分(容器比较的顺序不一样差集也不一样) 两容器不相交 那么差集就是 它们本身
// 注意也是必须是有序的两容器 
//set_difference(容器1的起始迭代器,容器1的结束迭代器,容器2的起始迭代器,容器2的结束迭代器,目标容器的起始迭代器)
void test3() 
{
	vector<int>v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(17);
	vector<int>v2;
	v2.push_back(9);
	v2.push_back(11);
	v2.push_back(15);
	v2.push_back(16);
	v2.push_back(18);
	vector<int>Target;
	Target.resize(max(v1.size(), v2.size()));
	vector<int>:: iterator itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), Target.begin());
	cout << "v2 与 v1的差集是\n";
	for_each(Target.begin(), itEnd, Imitation());
	cout << endl;


	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), Target.begin());
	cout << "v1 与 v2的差集是\n";
	for_each(Target.begin(), itEnd, Imitation());
	cout << endl;




}


int main() {
	test3();
	system("pause");
	return 0;

}