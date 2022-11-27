#include <iostream>
using namespace std;
#include <string>
//继承中构造函数和析构函数的调用顺序
class Base
{
public:
	Base()
	{

		cout << "父构造函数" << endl;
	}
	~Base()
	{

		cout << "父析构函数" << endl;
	}


};
class Son : public Base
{
	public:
	Son()
	{

		cout << "子构造函数" << endl;
	}
	~Son()
	{

		cout << "子析构函数" << endl;
	}
};



void test()
{
	Base base;
}

void test1()
{
	Son son;
}
//先构造父类再构造子类，析构的过程与此相反

int main()
{
	//test();
	test1();
	system("pause");
	return 0;
}