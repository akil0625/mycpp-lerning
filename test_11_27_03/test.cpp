#include <iostream>
using namespace std;

//类模板的继承

//1.当子类继承的是类模板时，需要在声明的时候指定父类模板中T的类型
//2.如果不指定，则编译器无法给子类分配内存
//3.如果想灵活指定出父类模板中T的类型，子类也需要变为类模板

template<class T>
class Base
{
public:
	Base()
	{
		cout << "Base中T的类型为:" << typeid(T).name() << endl;
	}
	T m;
};

//非模板子类
class Son1:public Base<int>//指定父类中T的类型
{
};

//模板子类
template<class T1,class T2>
class Son2 :public Base<T1>//指定父类中T的类型
{
public:
	Son2()
	{
		cout << "Son2中T1的类型" << typeid(T1).name() << endl << "Son2中T2的类型" << typeid(T2).name() << endl;
	}
	T2 obj;
};

void test1()
{
	Son1 p;//确定T的类型后就定死了T的类型
	p.m = 1;
	cout << p.m << endl;
}

void test2()
{
	Son2<string, int>p;//类模板继承类模板更加灵活
	p.m = "haha";
	p.obj = 2;
	cout << p.m << endl << p.obj << endl;
}

//主函数
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}