#include <iostream>
#include <string>
using namespace std;

//多继承

class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_B = 200;
	}
	int m_B;
};

class Base3
{
public:
	Base3()
	{
		m_A = 300;
	}
	int m_A;
};

class Son :public Base1, public Base2,public Base3
{
public:
	Son()
	{
		m_D = 400;
	}
	int m_D;
};

void test()
{
	Son s;
	//结果是所有父类中的和大小之和加上子类中的大小
	cout << sizeof(s) << endl;
	//当父类中出现了同名的成员变量时需要标明作用域
	cout << s.Base1::m_A << endl;
	cout << s.Base3::m_A << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}
