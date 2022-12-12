#include <iostream>
using namespace std;

//��ģ������Ԫ

//��Ϊ����ʵ�ֵĺ����õ���Personģ���࣬����Ҫ��ǰ����
template<class T1,class T2>
class Person;

//���⺯������
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "����:" << p.m_Name << endl
		<< "����:" << p.m_Age << endl;
}

template<class T1,class T2>
class Person
{
public:
	
	//ȫ�ֺ���������ʵ��
	friend void printPerson1(Person<T1, T2>& p)
	{

		cout << "����:" << p.m_Name << endl
			<< "����:" << p.m_Age << endl;
	}

	//���ں�������
	//��һ���յ�ģ������б��������ĺ����Ͷ���ĺ������ͱ���һ��
	friend void printPerson2<>(Person<T1, T2>& p);


	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

//ģ������ʵ�ֵĺ�������
void test1()
{
	Person<string, int>p("akil", 20);
	printPerson1(p);
}

//ģ������ʵ�ֵĺ�������
void test2()
{
	Person<string, int>p("abdusalam", 26);
	printPerson2(p);
}

//������
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}