#include <iostream>
using namespace std;
#include <string>
//��̬��Ա�����ĵļ̳м�ͨ��������ֱ�ӵ���
class Base
{
public:
	static void func()
	{
		cout << "haha" << endl;
	}
	static int m_A;
};
int Base::m_A = 200;

class Son :public Base
{
public:
	static void func()
	{
		cout << "hehe" << endl;
	}
	static int m_A;
};
int Son::m_A = 100;

void test()
{
	Son s;

	cout << s.m_A << endl;
	cout << s.Base::m_A << endl;

	cout << Son::m_A << endl;
	cout << Base::m_A << endl;

	cout << Son::m_A << endl;
	cout << Son::Base::m_A << endl;

	//��һ��::����ͨ���������ʾ�̬��Ա����
	//�ڶ���::������ʸ����������µľ�̬��Ա����

	Son::func();
	Son::Base::func();

	//ͬ���ľ�̬��Ա����Ҳ�ᱻ���Σ���Ҫ����������

}

int main()
{
	test();
	system("pause");
	return 0;
}