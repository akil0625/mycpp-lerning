#include <iostream>
#include <string>
using namespace std;

//��̳�

class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_B = 200;
	}
	int m_B;
};

class Base3
{
public:
	Base3()
	{
		m_A = 300;
	}
	int m_A;
};

class Son :public Base1, public Base2,public Base3
{
public:
	Son()
	{
		m_D = 400;
	}
	int m_D;
};

void test()
{
	Son s;
	//��������и����еĺʹ�С֮�ͼ��������еĴ�С
	cout << sizeof(s) << endl;
	//�������г�����ͬ���ĳ�Ա����ʱ��Ҫ����������
	cout << s.Base1::m_A << endl;
	cout << s.Base3::m_A << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}
