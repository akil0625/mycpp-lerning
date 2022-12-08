#include <iostream>
#include <string>
using namespace std;

//类模板和函数模板的区别

template<class NameType,class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)//AgeType的默认参数为整形
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	void showPerson()
	{
		cout << "name:" << this->m_Name << endl;
		cout << "age:" << this->m_Age << endl;
	}

	AgeType m_Age;
	NameType m_Name;

};

//1.类模板没有自动类型推导使用方式
void test1()
{
	//Person p("akil", 20);//报错
	Person <string, int> p("akil", 20);
	p.showPerson();
}

//2.类模板可以在参数列表中有默认参数(回见上方参数列表)
void test2()
{
	Person<string>p("akiljan", 21);
	p.showPerson();
}

int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}