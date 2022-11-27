#include <iostream>
using namespace std;
#include <string>
//静态成员函数的的继承及通过作用域直接调用
class Base
{
public:
	static void func()
	{
		cout << "haha" << endl;
	}
	static int m_A;
};
int Base::m_A = 200;

class Son :public Base
{
public:
	static void func()
	{
		cout << "hehe" << endl;
	}
	static int m_A;
};
int Son::m_A = 100;

void test()
{
	Son s;

	cout << s.m_A << endl;
	cout << s.Base::m_A << endl;

	cout << Son::m_A << endl;
	cout << Base::m_A << endl;

	cout << Son::m_A << endl;
	cout << Son::Base::m_A << endl;

	//第一个::代表通过类名访问静态成员变量
	//第二个::代表访问父类作用域下的静态成员变量

	Son::func();
	Son::Base::func();

	//同名的静态成员函数也会被屏蔽，需要加入作用域

}

int main()
{
	test();
	system("pause");
	return 0;
}