#include <iostream>
#include <string>
using namespace std;

//类模板成员函数类外实现

//类内实现
template<class T1,class T2>
class Person1
{
public:
	//类模板成员函数类内实现
	Person1(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//类模板成员函数类内实现
	void showPerson()
	{
		cout << "姓名:" << this->m_Name << endl
			<< "年龄:" << this->m_Age << endl;
	}


	T1 m_Name;
	T2 m_Age;
};


//类外实现
template<class T1, class T2>
class Person2
{
public:
	
	//类模板成员函数类外实现
	Person2(T1 name, T2 age);

	//类模板成员函数类外实现
	void showPerson();



	T1 m_Name;
	T2 m_Age;
};

//返回类型 模板参数列表 作用域 定义
template<class T1,class T2>
Person2<T1,T2>::Person2(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;	
}

//返回类型 模板参数列表 作用域 定义
template<class T1,class T2>
void Person2<T1, T2>::showPerson()
{
	cout << "姓名:" << this->m_Name << endl
		<< "年龄:" << this->m_Age << endl;
}

//调用上没有不同
void test1()
{
	//模板(类型)参数 函数参数
	Person1<string, int>p("akil", 20);
	p.showPerson();
}

void test2()
{
	//模板(类型)参数 函数参数
	Person2<string, int>p("akiljan", 20);
	p.showPerson();
}



//主函数
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}