#include <iostream>
#include <string>
using namespace std;
//传统的函数写法写法
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
//多态晚指定函数写法
//父类计算器
class Calculator1
{
public:
	virtual int getResult()
	{
		cout << "你没告诉我怎么计算sb" << endl;
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//子类加法计算
class Add :public Calculator1
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//子类减法计算
 class Sub :public Calculator1
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//子类乘法计算
 class Mul :public Calculator1
 {
 public:
	 int getResult()
	 {
		 return m_Num1 * m_Num2;
	 }
 };
//子类除法计算
 class  Div:public Calculator1
 {
 public:
	 int getResult()
	 {
		 return m_Num1 / m_Num2;
	 }
 };
 //传统方法写入的函数的调用
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
//多态晚指定函数的调用
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

//多态的扩展性高
//可读性高
//高内聚低耦合