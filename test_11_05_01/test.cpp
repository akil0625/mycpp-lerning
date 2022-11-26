//静态成员函数由所有对象分享
//静态成员函数只能访问静态成员变量(无法区分应该改变哪个对象的成员变量)
//静态成员函数也是有访问权限的
#include <iostream>
using namespace std;

class Person
{
private:
	static void func2()
	{
		cout << "hahaha" << endl;
	}
public:
	static void func()
	{
		m_A = 100;
		cout << "成员函数" << endl;
	}
	static int m_A;
	int m_B;

};
int Person::m_A = 0;


int main()
{

	Person p;
	//p.func;
	//Person::func();
	cout << Person::m_A << endl;
	//Person::func2();

	system("pause");
	return 0;
}


