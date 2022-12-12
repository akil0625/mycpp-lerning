#include <iostream>
using namespace std;

//类模板与友元

//因为类外实现的函数用到了Person模板类，所以要提前声明
template<class T1,class T2>
class Person;

//类外函数定义
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "姓名:" << p.m_Name << endl
		<< "年龄:" << p.m_Age << endl;
}

template<class T1,class T2>
class Person
{
public:
	
	//全局函数的类内实现
	friend void printPerson1(Person<T1, T2>& p)
	{

		cout << "姓名:" << p.m_Name << endl
			<< "年龄:" << p.m_Age << endl;
	}

	//类内函数声明
	//加一个空的模板参数列表保持声明的函数和定义的函数类型保持一致
	friend void printPerson2<>(Person<T1, T2>& p);


	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

//模板类内实现的函数调用
void test1()
{
	Person<string, int>p("akil", 20);
	printPerson1(p);
}

//模板类外实现的函数调用
void test2()
{
	Person<string, int>p("abdusalam", 26);
	printPerson2(p);
}

//主函数
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}