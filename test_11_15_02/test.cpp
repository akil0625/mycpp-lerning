#include <iostream>
using namespace std;
//重载赋值运算符时需要注意为堆区开辟的空间重新申请空间
//避免地址的直接赋值从而导致在西沟过程中空间的重复释放
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()
	{
		if (m_Age != NULL)
		{
			//动态开辟的空间需要回收
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person& operator=(Person &r)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
			m_Age = new int(*r.m_Age);
		}
		else
		{
			*this->m_Age = *r.m_Age;
		}
		return *this;
	}
	int* m_Age;
};
void test()
{
	Person p(10);
	Person p2(20);
	Person p3(30);
	p = p2 = p3;
	cout << *p.m_Age << endl << *p2.m_Age << endl << *p3.m_Age << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}