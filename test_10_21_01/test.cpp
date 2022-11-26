#include <iostream>
using namespace std;


//对象的初始化和清理
//1.构造函数 进行初始化操作
class Person
{
public:
	//构造函数
	//普通构造
	//无参构造
	Person()
	{

	}
	//有参构造
	Person(int a)
	{
		age = a;
	}
	//拷贝构造函数
	Person(const Person & p)
	{
		age = p.age;
	}

	~Person()
	{
		age = -1;
	}
public:
	int age;


};
//2.析构函数 进行清理操作

//调用
void test()
{
	Person p;//默认构造函数调用

	//括号法
	Person p1(10);
	Person p2(p1);
	//注意事项
	//调用默认构造函数的时候不要加括号（）
	//会认为是函数的声明
	cout << p1.age<<endl;
	cout << p2.age<<endl;


	//显示法(匿名对象的赋值)
	//Person(10)是匿名对象，在当前行结束后系统将立即回收对象
	Person p3;
	Person p4 = Person(20);
	Person p5 = Person(p4);
	cout << p4.age << endl;
	cout << p5.age << endl;
	//注意事项2
	// 不要利用拷贝函数初始化匿名对象 编译器会认为  Person(p3);  ==  Person p3;
	//隐式转换法
	Person p6 = 30;//有参构造
	Person p7 = p6;//拷贝构造
	cout << p6.age << endl;
	cout << p7.age << endl;
}


int main()
{
	test();
	system("pause");
	return 0;
}