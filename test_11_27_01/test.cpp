#include <iostream>
using namespace std;


//类模板中成员函数的创建时机
//类模板中的成员函数只有在调用的时候才会创建


//普通类
class Person1
{
public:
	void showPerson1()
	{
		cout << "我是Person1" << endl;

	}
};

//普通类
class Person2
{
public:
	void showPerson2()
	{
		cout << "我是Person2" << endl;

	}
};

//类模板
template<class T>
class myclass
{
public:

	T obj;

	void function1()
	{
		obj.showPerson1();//调用的对象未知，不调用就不会创建
	}

	void function2()
	{
		obj.showPerson2();
	}

};


void test()
{
	//通过改变参数列表的参数可访问不同的类中成员函数
	myclass<Person2>m;
	m.function2();


}


//主函数
int main()
{
	test();
	system("pause");
	return 0;
}