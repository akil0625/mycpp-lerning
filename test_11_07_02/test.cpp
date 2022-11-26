#include<iostream>
using namespace std;


class Person
{
friend ostream& operator<<(ostream& cout, Person& p);
public:
	Person();
private:
	
	int m_A;
	int m_B;

};
//运算符重载并进行友元绑定之后可以运算私有成员变量
 ostream & operator<<(ostream &cout,Person &p)
{
	cout << "m_A = " << p.m_A <<endl<< "m_B = " << p.m_B;
	return cout;
}

Person::Person()
{
	m_A = 10;
	m_B = 20;
}

void test()
{
	Person p;
	cout << p <<endl<< "henlo world" << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}