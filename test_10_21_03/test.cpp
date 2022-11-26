#include <iostream>
using namespace std;

//构造函数调用规则
//c++编译器至少给一个类添加三个函数
//1.默认构造函数（无参，函数体为空）
//2.默认析构函数（无参，函数体为空）
//3.默认拷贝构造函数（ 对属性进行值拷贝）
//规则
//如果定义有参构造函数c++不再提供无参构造但是会提供默认拷贝构造
//如果定义拷贝构造函数c++不再提供其他构造函数


class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	Person(int age)
	{
		cout << "有参构造函数调用" << endl;
		m_Age = age;
	}
	Person(const Person& p)
	{
		cout << "拷贝构造函数" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "析构函数" << endl;
	}


	int m_Age;

};


int main()
{

	Person p1;
	p1.m_Age = 10;
	Person p2(p1);
	cout << p2.m_Age << endl;

	return 0;
}