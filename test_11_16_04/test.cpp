#include <iostream>
using namespace std;
#include <string>






class Base
{
public:
	void func()
	{
		cout << "�����еĺ���" << endl;
	}
	Base()
	{
		m_A = 200;
	}
	int m_A;
};

class Son :public Base
{
public:
	void func()
	{
		cout << "�����еĺ���" << endl;
	}
	Son()
	{
		m_A = 100;
	}
	int m_A;
};





void test()
{
	Son son;
	cout << son.m_A << endl;
	cout << son.Base::m_A << endl;
	//ͨ�����������ʵ������Ա��ͬ���ĳ�Ա��Ҫ���⴦����ܷ���
	son.func();
	son.Base::func();
	//���⴦��ʽ����(��������)
	//ֻҪ�����д���ͬ����Ա�������ͽ��Զ����ظ��������е�ͬ����Ա�������������غ�����
	//�����������ſ��Է���
}





int main()
{
	test();
	system("pause");
	return 0;
}