#include <iostream>
using namespace std;
#include <queue>

//����queue����

class Person
{
public:

	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;

	}
	string m_Name;
	int m_Age;
};


void test01()
{
	//��������
	queue<Person>q;
	//����Ԫ��
	Person p1("akil", 20);
	Person p2("abdusalam", 26);
	Person p3("sultan", 20);
	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	while (!q.empty())
	{
		cout << "����:" << q.front().m_Name << "	����:"<<q.front().m_Age << endl;
		//����
		q.pop();
	}
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}