#include <iostream>
using namespace std;
//���ÿ������캯���ļ������
//�������ÿ������캯��
//ֵ���ݵķ�ʽ��������������
//ֵ��ʽ���ؾֲ�����

class Person
{
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	
	Person(int age)
	{
		cout << "�вι��캯��" << endl;
		m_Age = age;
	}

	Person(const Person& p)
	{
		cout << "�������캯��" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Ĭ����������" << endl;
	}

	int m_Age;

};

Person doWork()
{
	Person p1(50);
	return p1;
}

void test()
{
	Person p1;
	p1 = doWork();
	cout << p1.m_Age << endl;
}


int main()
{
	test();
	return 0;
}