#include <iostream>
#include <string>
using namespace std;
//���ó�Ա����ʵ�ַ��ŵ�����
class Person
{


public:
	Person();
	int m_A;
	int m_B;

	Person operator+(Person a)
	{
		Person temp;
		temp.m_A = 0;
		temp.m_B = 0;
		temp.m_A = this->m_A + a.m_A;
		temp.m_B = this->m_B + a.m_B;
		return temp;
	}

};

Person::Person()
{
	m_A = 10;
	m_B = 30;
}
void test()
{
	Person adam;
	Person adam2;
	Person* person = new Person;
	*person = adam + adam2;
	cout << "��Ӻ��A:" << person->m_A << endl;
	cout << "��Ӻ��B:" << person->m_B << endl;
}

int main()
{
	test();
	return 0;
}



