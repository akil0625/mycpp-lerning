#include <iostream>
using namespace std;

//模板的局限性
//模板并不是万能的，有些特定的数据类型，需要具体方式做特殊实现

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	//姓名
	string m_Name;
	//年龄
	int m_Age;
};

//对比两个数据是否相等的模板函数
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}

//具体化优先调用
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age && p1.m_Name == p2.m_Name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//测试函数
void test1()
{
	int a = 10;
	int b = 20;
	int c = 10;
	//测试内置数据类型
	if (myCompare(a, b))
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}

//测试函数
void test2()
{
	Person a("akil", 20);
	Person b("akil", 20);
	//测试自定义数据类型
	//行不通时的解决方案
	//1.运算符重载
	//2.利用具体化的Person的版本实现代码，具体化优先调用,如上
	if (myCompare(a, b))
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}

//主函数
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}