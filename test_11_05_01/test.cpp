//��̬��Ա���������ж������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����(�޷�����Ӧ�øı��ĸ�����ĳ�Ա����)
//��̬��Ա����Ҳ���з���Ȩ�޵�
#include <iostream>
using namespace std;

class Person
{
private:
	static void func2()
	{
		cout << "hahaha" << endl;
	}
public:
	static void func()
	{
		m_A = 100;
		cout << "��Ա����" << endl;
	}
	static int m_A;
	int m_B;

};
int Person::m_A = 0;


int main()
{

	Person p;
	//p.func;
	//Person::func();
	cout << Person::m_A << endl;
	//Person::func2();

	system("pause");
	return 0;
}


