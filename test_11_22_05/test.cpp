#include <iostream>
using namespace std;

//ģ��ľ�����
//ģ�岢�������ܵģ���Щ�ض����������ͣ���Ҫ���巽ʽ������ʵ��

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	//����
	string m_Name;
	//����
	int m_Age;
};

//�Ա����������Ƿ���ȵ�ģ�庯��
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}

//���廯���ȵ���
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age && p1.m_Name == p2.m_Name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���Ժ���
void test1()
{
	int a = 10;
	int b = 20;
	int c = 10;
	//����������������
	if (myCompare(a, b))
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
}

//���Ժ���
void test2()
{
	Person a("akil", 20);
	Person b("akil", 20);
	//�����Զ�����������
	//�в�ͨʱ�Ľ������
	//1.���������
	//2.���þ��廯��Person�İ汾ʵ�ִ��룬���廯���ȵ���,����
	if (myCompare(a, b))
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
}

//������
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}