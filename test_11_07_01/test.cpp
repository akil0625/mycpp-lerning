#include <iostream>
using namespace std;
//运算符重载

class Person
{
public:

	Person();
	//成员函数形式
	//Person operator+(Person p)
	//{
	//	Person temp;
	//	temp.m_A = p.m_A + this->m_A;
	//	temp.m_B = p.m_B + this->m_B;
	//	return temp;
	//}


	int m_A;
	int m_B;

};


//全局函数形式
Person operator+(Person& p, Person& p2)
{
	Person temp;
	temp.m_A = p.m_A + p2.m_A;
	temp.m_B = p.m_B + p2.m_B;
	return temp;
}

Person::Person()
{
	m_A = 10;
	m_B = 20;
}
 
void test()
{
	Person p1;
	Person p2;
	Person p3;
	p3 = operator+(p1, p2);
	cout << p3.m_A << endl << p3.m_B << endl;
}




int main()
{
	test();
	return 0;
}