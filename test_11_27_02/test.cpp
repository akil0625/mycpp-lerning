#include <iostream>
#include <string>
using namespace std;

//��ģ���������������
//��ģ��ʵ�����Ķ����������εķ�ʽ
//1.ָ���������� --ֱ����ʾ�������������
//2.����ģ�廯   --�������еĲ�����Ϊģ����д���
//3.������ģ�廯 --�������������ģ�廯���д���


template<class T1,class T2>
class Person
{
public:

	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "����" << this->m_Name << endl << "����" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;

};


//1.ָ���������� --ֱ����ʾ�������������
void func1(Person<string, int>& p)
{
	cout << "1.ָ���������ͷ�ʽ����ģ����������" << endl;
	p.showPerson();
}


//2.����ģ�廯   --�������еĲ�����Ϊģ����д���
template<class T1,class T2>
void func2(Person<T1,T2>&p)
{
	//һ��ע�Ϳɲ鿴�����б��в�������������
	//cout << typeid(T2).name() << endl;
	cout << "2.����ģ�廯��ʽ����ģ����������" << endl;
	p.showPerson();
}

//3.������ģ�廯 --�������������ģ�廯���д���
template<class T>
void func3(T& p)
{
	cout << "������ģ�廯�ķ�ʽ����ģ����������" << endl;
	p.showPerson();//����ʱ�ű��������
	//cout << typeid(T).name() << endl;
}

void test1()
{
	//������ģ��Ķ���
	Person<string, int>p("akil", 20);
	//����������Ŀ�����
	func1(p);


}


void test2()
{
	//������ģ��Ķ���
	Person<string, int>p("abdusalam", 26);
	//����������Ŀ�����
	func2(p);
}

void test3()
{
	//������ģ��Ķ���
	Person<string, int>p("sultan", 20);
	//����������Ŀ�����
	func3(p);

}

//������
int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}