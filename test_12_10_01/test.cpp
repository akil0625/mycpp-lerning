#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <ctime>

//vector和deque的案例---选手打分系统

//选手类
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	
	string m_Name;

	int m_Score;
};

//初始化
void createPerson(vector<Person>&v)
{
	string name;
	string nameSeed = "ABCDE";
	int score = 0;
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Person p(name, score);
		v.push_back(p);
	}
}

//显示计分板
void showBoard(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "姓名 :" << v[i].m_Name << " 得分 : " << v[i].m_Score << endl;
	}
}

//打分
void setScore(vector<Person>& v)
{
	deque<int>d;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//清空计分板
		d.clear();
		//十个评委打分
		for (int i = 0; i < 10; i++)
		{
			d.push_back(rand() % 41 + 60);
		}
		//排序
		sort(d.begin(),d.end());
		//排除最低分
		d.pop_front();
		//排除最高分
		d.pop_back();

		//获取总分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//得到平均分
		int ave = sum / d.size();
		//计分
		(*it).m_Score = ave;
	}
}


//主函数
int main()
{
	srand((unsigned int)time(NULL));

	//1、创建5名选手
	vector<Person>v;
	createPerson(v);

	//2、给5名选手打分
	setScore(v);

	//3、显示最后得分
	showBoard(v);

	system("pause");
	return 0;
}