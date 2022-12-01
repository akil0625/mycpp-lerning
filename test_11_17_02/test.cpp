#include <iostream>
#include <string>
using namespace std;

//纯虚函数的写法
class Base
{
public:
	virtual void func() = 0;
};

//只要包含一个虚拟函数，那么这个类就是纯虚函数
class Son:public Base
{
public:

	//纯虚函数需要在子类中重写
	virtual void func()
	{
		cout << "子类重写纯虚函数" << endl;
	}
};

//测试
void test()
{
	//Son s;
	//s.func();
	Base* b = new Son;
	b->func();
}

//主函数
int main()
{
	test();
	system("pause");
	return 0;
}