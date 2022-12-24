#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <ctime>

//vector��deque�İ���---ѡ�ִ��ϵͳ

//ѡ����
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

//��ʼ��
void createPerson(vector<Person>&v)
{
	string name;
	string nameSeed = "ABCDE";
	int score = 0;
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Person p(name, score);
		v.push_back(p);
	}
}

//��ʾ�Ʒְ�
void showBoard(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "���� :" << v[i].m_Name << " �÷� : " << v[i].m_Score << endl;
	}
}

//���
void setScore(vector<Person>& v)
{
	deque<int>d;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//��ռƷְ�
		d.clear();
		//ʮ����ί���
		for (int i = 0; i < 10; i++)
		{
			d.push_back(rand() % 41 + 60);
		}
		//����
		sort(d.begin(),d.end());
		//�ų���ͷ�
		d.pop_front();
		//�ų���߷�
		d.pop_back();

		//��ȡ�ܷ�
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//�õ�ƽ����
		int ave = sum / d.size();
		//�Ʒ�
		(*it).m_Score = ave;
	}
}


//������
int main()
{
	srand((unsigned int)time(NULL));

	//1������5��ѡ��
	vector<Person>v;
	createPerson(v);

	//2����5��ѡ�ִ��
	setScore(v);

	//3����ʾ���÷�
	showBoard(v);

	system("pause");
	return 0;
}