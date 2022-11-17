#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;

class Player 
{
public:
	Player(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};


//录入选手姓名
void gradePlayer(vector<Player>&v) 
{
	string name;
	int score = 0;
	for (int i = 0; i < 5; i++) 
	{
		cout << "enter player name: \n";
		cin >> name;
	/*	cout << "enter player score: \n";
		cin >> score;*/
		Player p(name, score); //键盘录入姓名 分数先不录入默认为0
		//将创建的Player对象，放入容器中
		v.push_back(p);//添加选手到vector容器中
	}

}


//展现分数
void showGrade(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_Name << " ";
		if ((*it).m_Score < 60)
		{
			cout << (*it).m_Score << " 分 ÷中÷建议进厂\n";
		}
		else if ((*it).m_Score > 60 && (*it).m_Score < 70)
		{
			cout << (*it).m_Score << " 分 队伍第二÷回家养猪\n";
		}
		else if ((*it).m_Score >= 70 && (*it).m_Score < 80)
		{
			cout << (*it).m_Score << " 分 中规中矩\n";
		}
		else if ((*it).m_Score >= 80 && (*it).m_Score < 90)
		{
			cout << (*it).m_Score << " 分 卧槽 有代！！！\n";
		}
		else if ((*it).m_Score >= 90 && (*it).m_Score < 100)
		{
			cout << (*it).m_Score << " 打你妈分， 你们这群打分杂种\n";
		} else {
			cout << "???????\n";
		}

	}


}


//打分
void setScore(vector<Player>& v) 
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) 
	{
		//将评委打分分数放入deque容器
		deque<int>d;
		for (int i = 0; i < 10; i++) 
		{
			//rand() % 41 == 40的随机数
			int score = rand() % 41 + 60; //60是基础的分数 40分随机
			d.push_back(score);
		
		}
		//生成10个60-100分范围内的分数

		/*cout << " player: " << it->m_Name << " socre: " << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << "  ";
		}
		cout << endl;*/


		//排序
		sort(d.begin(), d.end());//排序后 以升序为主 第一个最小 最后一个最大
		//去最高最低分
		d.pop_back();//删除尾部元素
		d.pop_front();//删除头部元素

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) 
		{
			sum += *dit;//获取8个随机分数总分
		}
		int avg = sum / d.size();

		//把打分 赋值给选手
		it->m_Score = avg;
	}
	

}

void showScore(vector<Player>&v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_Name << "  ";
		cout << (*it).m_Score << endl;
	}


}


int main() {
	//添加随机数种子
	srand((unsigned int)time(NULL));


	//创建5名选手
	vector<Player>v;
	gradePlayer(v);
	//测试是否存储到选手数据
	
	setScore(v);
	showGrade(v);
	showScore(v);
	system("pause");
	return 0;

}