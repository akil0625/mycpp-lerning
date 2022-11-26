#include <iostream>
using namespace std;
//const 修饰成员函数为常函数
//常函数中无法修改成员属性
//加上关键字mutable后可对成员变量进行修改


class Person
{
public:
	void ShowPerson() const//这里的const将this指向的对象变为不可修改（常数指针）
	{
		cout << this->m_A << endl;
		cout << this->m_B << endl;
		this->m_A = 100;//this 为指针常量 无法修改指向的对象
		//this->m_B = 100;//<-不可修改
	}
	void ShowB()
	{
		cout << m_B << endl;
	}

	mutable int m_A = 100;
	int m_B = 100;

};


 
void test()
{

}

void test1()
{
	const Person p;
	//常对象只能够调用常函数
	//p.ShowB();
	//加了mutable后对应的值在常对象下也可修改
	p.ShowPerson();
	p.m_A = 200;

}


int main()
{
	test1();
	system("pause");
	return 0;
}