#include <iostream>
using namespace std;
//���������

class Person
{
public:
	Person();
	int m_A;
	int m_B;
};
Person::Person()
{
	m_A = 0;
	m_B = 0;
}
//�ǳ�Ա����ʵ�����������
Person operator+(Person a,Person b)
{
	Person temp;
	temp.m_A = a.m_A + b.m_A;
	temp.m_B = a.m_B + b.m_B;
	return temp;
}

ostream & operator<<(ostream &cout, Person b)
{
	cout << b.m_A << endl << b.m_B ;
	return cout;
}

void test()
{
	Person a;
	Person b;
	a.m_A = 10;
	a.m_B = 20;
	b.m_A = 30;
	b.m_B = 40;
	Person c;
	c = a + b;

	cout << c << endl;
}


int main()
{
	test();
	system("pause");
	return 0;
}