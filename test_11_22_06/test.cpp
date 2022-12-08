#include <iostream>
#include <string>
using namespace std;

//类模板
template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	void showPerson()
	{
		cout << "name: " << this->m_Name << endl << "age: " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

void test1()
{
	//模板可以传入类型作为参数
	Person<string, int>a("akil", 20);
	a.showPerson();
}

int main()
{
	test1();
	system("pause");
	return 0;
}