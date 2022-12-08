#include <iostream>
#include <string>
using namespace std;

//类模板中成员函数创建时机

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2" << endl;
	}
};

template<class T>
class myClass
{
public:

	T obj;

	//类模板中的成员函数
	void func1()
	{
		obj.showPerson1();//只有调用时才会创建该函数
	}

	void func2()
	{
		obj.showPerson2();
	}


};



void test()
{
	myClass<Person1>m;
	m.func1();
	//m.func2();
	myClass<Person2>n;
	n.func2();

}

int main()
{

	test();
	system("pause");
	return 0;
}