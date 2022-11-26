#include <iostream>
using namespace std;

//成员变量和成员函数是分开存储的

class Person
{
	int m_A;//非静态成员变量  属于类的对象上
	static int m_B;//静态成员变量 不属于类的对象上
	void func(){}//非静态成员函数 不属于类的对象上
	static void func2() {}//静态成员函数 不属于类的对象上
};


int Person::m_B = 0;

void test()
{
	Person p;

	cout << "size of p = " << sizeof(p) << endl;

}


void test2()
{

	Person p;

	cout << "size of p = " << sizeof(p) << endl;

}
void test3()
{
	Person p;

	cout << "size of p = " << sizeof(p) << endl;
}

int main()
{

	test();
	//为了区分空对象占用的位置编译器给对象分配一个内存
	//每个对象对应唯一的地址
	test2();
	//非空对象无需多分配一个字节区别对象的位置
	test3();
	return 0;
}
