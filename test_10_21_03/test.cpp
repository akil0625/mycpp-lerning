#include <iostream>
using namespace std;

//���캯�����ù���
//c++���������ٸ�һ���������������
//1.Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
//2.Ĭ�������������޲Σ�������Ϊ�գ�
//3.Ĭ�Ͽ������캯���� �����Խ���ֵ������
//����
//��������вι��캯��c++�����ṩ�޲ι��쵫�ǻ��ṩĬ�Ͽ�������
//������忽�����캯��c++�����ṩ�������캯��


class Person
{
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	Person(int age)
	{
		cout << "�вι��캯������" << endl;
		m_Age = age;
	}
	Person(const Person& p)
	{
		cout << "�������캯��" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "��������" << endl;
	}


	int m_Age;

};


int main()
{

	Person p1;
	p1.m_Age = 10;
	Person p2(p1);
	cout << p2.m_Age << endl;

	return 0;
}