#include<iostream>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
//预定义
#define MASTERMIND 0
//末尾不加分号;
#define FINDARTS 1

#define RD 2

/*
	员工信息： 姓名 工资组成 部门： 策划，美术，研发 
	随机给10名员工分配部门和工资
	通过multimap进行信息的插入 key(部门编号)value(员工)



*/
class Worker
{
public:
	string m_Name;
	int m_Salary;

};


void createWorker(vector<Worker>& v) 
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) 
	{
		Worker wk;
		wk.m_Name = "Worker";
		wk.m_Name += nameSeed[i];//拼接员工后缀名
		wk.m_Salary = rand() % 10000 + 10000; // 10000 - 19999

		//把员工放进容器中
		v.push_back(wk);
	}
}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m) 
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) 
	{
		//产生随机的部门编号
		int groupID = rand() % 3; // 0 1 2

		//将部门编号和员工插入到multimap容器中
		//key部门编号 value具体员工
		m.insert(make_pair(groupID, *it));
	}
}


void showWorker(multimap<int, Worker>& m) 
{
	cout << " Mastermind department" << endl;

	multimap<int, Worker>::iterator pos = m.find(MASTERMIND);
	int count = m.count(MASTERMIND);
	int index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "workerN: " << (*pos).second.m_Name << "\tworkerSalary: " << (*pos).second.m_Salary << endl;
	}



	cout << " Find Arts department" << endl;

	pos = m.find(FINDARTS);
	count = m.count(FINDARTS);
	index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "workerN: " << (*pos).second.m_Name << "\tworkerSalary: " << (*pos).second.m_Salary << endl;
	}




	cout << " R&D department" << endl;

	pos = m.find(RD);
	count = m.count(RD);
	index = 0;
	for (; pos != m.end() && index < count; index++, pos++)
	{
		cout << "workerN: " << (*pos).second.m_Name << "\tworkerSalary: " << (*pos).second.m_Salary << endl;
	}



}

int main() {

	srand((unsigned int)time(NULL));
	//1.创建员工
	vector<Worker>wk;
	createWorker(wk);
	////测试
	//for (vector<Worker>:: iterator it = wk.begin(); it != wk.end(); it++) 
	//{
	//	cout << "WorkerName: " << (*it).m_Name << "\tWorkerSalary: " << (*it).m_Salary << endl;
	//}
	//cout << endl;
	
	//2.员工分组

	multimap<int, Worker>mk;
	setGroup(wk, mk);

	//3.显示员工信息
	showWorker(mk);


	system("pause");
	return 0;

}