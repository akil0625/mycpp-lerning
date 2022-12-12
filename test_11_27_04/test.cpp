#include <iostream>
#include <string>
using namespace std;

//��ģ���Ա��������ʵ��

//����ʵ��
template<class T1,class T2>
class Person1
{
public:
	//��ģ���Ա��������ʵ��
	Person1(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//��ģ���Ա��������ʵ��
	void showPerson()
	{
		cout << "����:" << this->m_Name << endl
			<< "����:" << this->m_Age << endl;
	}


	T1 m_Name;
	T2 m_Age;
};


//����ʵ��
template<class T1, class T2>
class Person2
{
public:
	
	//��ģ���Ա��������ʵ��
	Person2(T1 name, T2 age);

	//��ģ���Ա��������ʵ��
	void showPerson();



	T1 m_Name;
	T2 m_Age;
};

//�������� ģ������б� ������ ����
template<class T1,class T2>
Person2<T1,T2>::Person2(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;	
}

//�������� ģ������б� ������ ����
template<class T1,class T2>
void Person2<T1, T2>::showPerson()
{
	cout << "����:" << this->m_Name << endl
		<< "����:" << this->m_Age << endl;
}

//������û�в�ͬ
void test1()
{
	//ģ��(����)���� ��������
	Person1<string, int>p("akil", 20);
	p.showPerson();
}

void test2()
{
	//ģ��(����)���� ��������
	Person2<string, int>p("akiljan", 20);
	p.showPerson();
}



//������
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}