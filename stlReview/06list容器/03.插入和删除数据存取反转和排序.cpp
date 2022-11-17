#include<iostream>
#include<list>
using namespace std;

void printList(const list<int>& li) 
{
	for (list<int>::const_iterator it = li.begin(); it != li.end(); it++) 
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//插入和删除
void test() 
{
	list<int>li;

	//尾插
	li.push_back(10);
	li.push_back(20);
	li.push_back(30);
	li.push_back(40);
	//10 20 30 40

	//头插
	li.push_front(80);
	li.push_front(70);
	li.push_front(60);
	li.push_front(50);

	//50 60 70 80 10 20 30 40
	printList(li);

	//插入
	list<int>::iterator it = li.begin(); 

	li.insert(++it, 99);//在头部位置下一个位置插入 99
	printList(li);//50 99 60 70 80 10 20 30 40


	//删除 
	it = li.begin();//重新指向头部地址
	li.erase(it);
	printList(li);//99 60 70 80 10 20 30 40

	
	li.push_back(88);
	li.push_back(88);
	li.push_back(88);
	printList(li);//99 60 70 80 10 20 30 40 88 88 88
	
	//移除元素 删除容器中所有与元素相同的元素
	li.remove(88);
	printList(li);//99 60 70 80 10 20 30 40

	// li.clear();//清空
	// printList(li);
	//尾删
	li.pop_back();
	printList(li);//99 60 70 80 10 20 30

	//头删
	li.pop_front();
	printList(li);//60 70 80 10 20 30 40



}


//数据存取
void test2()
{	//内存存储不连续所以不能用 at函数和[]来取得元素
	list<int>li;
	li.push_back(12);
	li.push_back(13);
	li.push_back(14);
	printList(li);//12 13 14

	//第一个元素 
	cout << li.front() << " is  the first one \n";//12
	//最后一个元素
	cout << li.back() << " is the last one \n";//14

	//迭代器不支持随机访问 it = it + 1 error
}

//
bool myCompare(int v1, int v2)
{
	//降序就是 第一个大于第二个数
	return v1 > v2;
}


//反转 排序 
void test3()
{
	list<int>li;
	li.push_back(12);
	li.push_back(11);
	li.push_back(14);
	li.push_back(15);
	printList(li);// 12 11 14 15


	//反转
	li.reverse();//首尾对调
	cout << "反转了呢\n";
	printList(li);// 15 14 11 12


	//排序 所有不支持随机迭代器的容器 不可以用标准算法
	li.sort();
	printList(li);//11 12 14 15
	li.sort(myCompare);//默认排序规则从大到小
	printList(li);// 15 14 12 11

	
}
int main() {
	test();
	test2();
	test3();
	system("pause");
	return 0;

}