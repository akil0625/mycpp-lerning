#include <iostream>
using namespace std;
//调用拷贝构造函数的几种情况
//主动调用拷贝构造函数
//值传递的方式给函数参数传参
//值方式返回局部对象

class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	
	Person(int age)
	{
		cout << "有参构造函数" << endl;
		m_Age = age;
	}

	Person(const Person& p)
	{
		cout << "拷贝构造函数" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "默认析构函数" << endl;
	}

	int m_Age;

};

Person doWork()
{
	Person p1(50);
	return p1;
}

void test()
{
	Person p1;
	p1 = doWork();
	cout << p1.m_Age << endl;
}


int main()
{
	test();
	return 0;
}