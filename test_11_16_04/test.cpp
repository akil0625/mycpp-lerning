#include <iostream>
using namespace std;
#include <string>






class Base
{
public:
	void func()
	{
		cout << "父类中的函数" << endl;
	}
	Base()
	{
		m_A = 200;
	}
	int m_A;
};

class Son :public Base
{
public:
	void func()
	{
		cout << "子类中的函数" << endl;
	}
	Son()
	{
		m_A = 100;
	}
	int m_A;
};





void test()
{
	Son son;
	cout << son.m_A << endl;
	cout << son.Base::m_A << endl;
	//通过子类对象访问到父类成员中同名的成员需要特殊处理才能访问
	son.func();
	son.Base::func();
	//特殊处理方式如上(加作用域)
	//只要子类中存在同名成员函数，就将自动隐藏父类中所有的同名成员函数（包括重载函数）
	//加上作用域后才可以访问
}





int main()
{
	test();
	system("pause");
	return 0;
}