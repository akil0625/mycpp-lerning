#include <iostream>
#include <string>
using namespace std;
//比较运算符的重载
class Person
{
public:
	Person(string name,int age)
	{
		m_Name = name;
		m_Age = age;
	}
	int m_Age;
	string m_Name;
};
bool operator>(Person l, Person r)
{
	if (l.m_Age > r.m_Age)
		return true;
	else
		return false;
}
bool operator<(Person l, Person r)
{
	if (l.m_Age < r.m_Age)
		return true;
	else
		return false;
}
bool operator==(Person l, Person r)
{
	if (l.m_Age == r.m_Age)
		return true;
	else
		return false;
}
bool operator!=(Person l, Person r)
{
	if (l.m_Age != r.m_Age)
		return true;
	else
		return false;
}

void test()
{
	Person a("akil", 24);
	Person b("zulpiya", 24);
	if (a > b)
	{
		cout << "a>b" << endl;
	}
	if(a < b)
	{
		cout << "a<b" << endl;
	}
	if (a == b)
	{
		cout << "a=b" << endl;
	}
	if (a != b)
	{
		cout << "a!=b" << endl;
	}

}


int main()
{
	test();

	system("pause");
	return 0;
}