#include <iostream>
#include <string>
using namespace std;
//��ͳ�ĺ���д��д��
class Calculator
{
public:
	int getRusult(string oper)
	{
		if (oper == "+")
			return m_Num1 + m_Num2;
		if (oper == "-")
			return m_Num1 - m_Num2;
		if (oper == "*")
			return m_Num1 * m_Num2;
		if (oper == "/")
			return m_Num1 / m_Num2;
	}
	int m_Num1;
	int m_Num2;
};
//��̬��ָ������д��
//���������
class Calculator1
{
public:
	virtual int getResult()
	{
		cout << "��û��������ô����sb" << endl;
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//����ӷ�����
class Add :public Calculator1
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//�����������
 class Sub :public Calculator1
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//����˷�����
 class Mul :public Calculator1
 {
 public:
	 int getResult()
	 {
		 return m_Num1 * m_Num2;
	 }
 };
//�����������
 class  Div:public Calculator1
 {
 public:
	 int getResult()
	 {
		 return m_Num1 / m_Num2;
	 }
 };
 //��ͳ����д��ĺ����ĵ���
void test()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getRusult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getRusult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getRusult("*") << endl;
	cout << c.m_Num1 << "/" << c.m_Num2 << "=" << c.getRusult("/") << endl;
}
//��̬��ָ�������ĵ���
void test1()
{
	Calculator1 *abc = new Add;
	abc->m_Num1 = 50;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult()<< endl;
	delete abc;
	abc = NULL;
	abc = new Sub;
	abc->m_Num1 = 150;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = NULL;
	abc = new Mul;
	abc->m_Num1 = 150;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = NULL;
	abc = new Div;
	abc->m_Num1 = 150;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "/" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = NULL;
}

int main()
{
	test();
	test1();
	system("pause");
	return 0;
}

//��̬����չ�Ը�
//�ɶ��Ը�
//���ھ۵����