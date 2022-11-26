#include <iostream>
using namespace std;
//���ظ�ֵ�����ʱ��Ҫע��Ϊ�������ٵĿռ���������ռ�
//�����ַ��ֱ�Ӹ�ֵ�Ӷ����������������пռ���ظ��ͷ�
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()
	{
		if (m_Age != NULL)
		{
			//��̬���ٵĿռ���Ҫ����
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person& operator=(Person &r)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
			m_Age = new int(*r.m_Age);
		}
		else
		{
			*this->m_Age = *r.m_Age;
		}
		return *this;
	}
	int* m_Age;
};
void test()
{
	Person p(10);
	Person p2(20);
	Person p3(30);
	p = p2 = p3;
	cout << *p.m_Age << endl << *p2.m_Age << endl << *p3.m_Age << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}