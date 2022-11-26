#include <iostream>
using namespace std;

//空指针访问成员函数
//可以访问，但需要戒备

class Person
{
public:
	//成员函数

	void ShowClassName()
	{
		cout << "this is Person class" <<endl;
	}
	void ShowClassAge()
	{
		if (this == NULL)
		{
			return;
		}
		cout << "age = " << this->m_Age << endl;
	}

	//成员变量
	int m_Age;

};


void test()
{
	Person* p = NULL;
	p->ShowClassName();
	//能访问成员函数，但不能访问成员变量
	//p->ShowClassAge();
}


int main()
{
	test();
	system("pause");
	return 0;
}