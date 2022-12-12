#include <iostream>
#include <string>
using namespace std;

//类模板对象做函数参数
//类模板实例化的对象，向函数传参的方式
//1.指定传入类型 --直接显示对象的数据类型
//2.参数模板化   --将对象中的参数变为模板进行传递
//3.整个类模板化 --将这个对象类型模板化进行传递


template<class T1,class T2>
class Person
{
public:

	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名" << this->m_Name << endl << "年龄" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;

};


//1.指定传入类型 --直接显示对象的数据类型
void func1(Person<string, int>& p)
{
	cout << "1.指定传入类型方式传递模板类对象参数" << endl;
	p.showPerson();
}


//2.参数模板化   --将对象中的参数变为模板进行传递
template<class T1,class T2>
void func2(Person<T1,T2>&p)
{
	//一下注释可查看参数列表中参数的数据类型
	//cout << typeid(T2).name() << endl;
	cout << "2.参数模板化方式传递模板类对象参数" << endl;
	p.showPerson();
}

//3.整个类模板化 --将这个对象类型模板化进行传递
template<class T>
void func3(T& p)
{
	cout << "整个类模板化的方式传递模板类对象参数" << endl;
	p.showPerson();//调用时才被创造出来
	//cout << typeid(T).name() << endl;
}

void test1()
{
	//创建类模板的对象
	Person<string, int>p("akil", 20);
	//向函数传递类目版对象
	func1(p);


}


void test2()
{
	//创建类模板的对象
	Person<string, int>p("abdusalam", 26);
	//向函数传递类目版对象
	func2(p);
}

void test3()
{
	//创建类模板的对象
	Person<string, int>p("sultan", 20);
	//向函数传递类目版对象
	func3(p);

}

//主函数
int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}