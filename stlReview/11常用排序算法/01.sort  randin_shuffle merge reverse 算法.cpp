#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<ctime>
using namespace std;


class MyCompare 
{
public:
	bool operator()(int v1,int v2) 
	{
		return v1 > v2;
	}

};

void myPrint(int val)
{
	cout << val << "  ";
}


//sort 算法  sort(起始迭代器,结束迭代器,谓词)
void test() 
{
	vector<int>v;
	v.push_back(12);
	v.push_back(11);
	v.push_back(15);
	v.push_back(10);
	//sort(v.begin(), v.end());//默认升序

	//sort(v.begin(), v.end(),MyCompare());//使用谓词改变为降序
	sort(v.begin(), v.end(),greater<int>());//使用匿名内建函数对象 大于greater<typename>()
	for_each(v.begin(), v.end(), myPrint);
	

}

		//洗牌算法
//random_shuffle(起始迭代器,结束迭代器) 指定范围内的元素随机调正次序
void test2() 
{
	vector<int>v;
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);

	//洗牌算法打乱元素顺序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);

}


//merge算法 两个容器元素合并 并存储到另一个元素容器中
//注意两个容器必须是有序的
//merge(容器1的起始迭代器,容器1的结束迭代器,容器2的起始迭代器,容器2的结束迭代器,目标容器的起始迭代器)

void test3() 
{
	vector<int>v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);
	vector<int>v2;
	//一个降序 一个升序的有序也不行 必须是同一种排序
	v2.push_back(19);
	v2.push_back(20);
	v2.push_back(21);
	v2.push_back(22);

	vector<int>v3;
	//提前给目标容器开辟空间
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin());
	for_each(v3.begin(), v3.end(), myPrint);
	cout << endl;

}


//reverse算法 将容器中元素顺序进行反转
//reverse(起始迭代器,结束迭代器);
void test4() 
{
	vector<int>v;
	/*v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);*/
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	cout << "Before reverse-----\n";
	for_each(v.begin(), v.end(), myPrint);
	
	cout << endl;

	cout << "After reverse------\n";
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

}
int main() {
	//添加随机数种子
	srand((unsigned int)time(NULL));
	test4();
	system("pause");
	return 0;

}