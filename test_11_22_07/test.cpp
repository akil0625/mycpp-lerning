#include <iostream>
#include <string>
using namespace std;

//��ģ��ͺ���ģ�������

template<class NameType,class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)//AgeType��Ĭ�ϲ���Ϊ����
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	void showPerson()
	{
		cout << "name:" << this->m_Name << endl;
		cout << "age:" << this->m_Age << endl;
	}

	AgeType m_Age;
	NameType m_Name;

};

//1.��ģ��û���Զ������Ƶ�ʹ�÷�ʽ
void test1()
{
	//Person p("akil", 20);//����
	Person <string, int> p("akil", 20);
	p.showPerson();
}

//2.��ģ������ڲ����б�����Ĭ�ϲ���(�ؼ��Ϸ������б�)
void test2()
{
	Person<string>p("akiljan", 21);
	p.showPerson();
}

int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}