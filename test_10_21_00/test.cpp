#include <iostream>
using namespace std;
#include <string>

//第一部分

//深拷贝和浅拷贝
//浅拷贝
//	简单的赋值拷贝操作
//深拷贝
//	在堆区重新申请空间，进行拷贝操作

//class Person
//{
//public:
//	Person()
//	{
//		cout << "默认构造函数" << endl;
//	}
//	Person(int age, int height)
//	{
//		m_Age = age;
//		m_Height = new int(height);
//		cout << "有参构造函数" << endl;
//	}
//	Person(const Person& p)
//	{
//	//可以防止浅拷贝带来的内存重复释放
//		cout << "拷贝构造函数" << endl;
//		m_Age = p.m_Age;
//		m_Height = new int(*p.m_Height);
//	}
//	~Person()
//	{
//		//析构函数用于释放堆区开辟的空间
//		//防止内存泄露
//		delete m_Height;
//		m_Height = NULL;
//		cout << "默认析构函数" << endl;
//	}
//
//
//	int m_Age;
//	int* m_Height;
//};
//int main()
//{
//	Person p1(18, 20);
//	Person p2(p1);
//	cout << p2.m_Age << endl<< *p2.m_Height << endl;
//
//
//
//	return 0;
//}

//第二部分

////初始化列表
//
//class Person
//{
//public:
////传统方式利用构造函数进行初始化
//
//	//Person(int a, int b, int c)
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}
////初始化列表初始化属性
//	//呆板用法
//	//Person() :m_A(10), m_B(20), m_C(30)
//	//{
//
//	//}
//	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
//	{
//
//	}
//	int m_A;
//	int m_B;
//	int m_C;
//
//};
//
//void test()
//{
//	Person p1(10,20,30);
//	cout << "m_A = " << p1.m_A << endl << "m_B = " << p1.m_B << endl << "m_C = " << p1.m_C << endl;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//第三部分


//类对象作为类成员
// 构造的顺序:
//先构造成员类再构造对象类
//析构的顺序:
//先析构类对象再析构类成员

class Phone
{
public:

	Phone(string pName)
	{
		cout << "调用手机的构造函数" << endl;
		m_PName = pName;
	}
	~Phone()
	{
		cout << "调用手机的析构函数" << endl;
	}

	string m_PName;
};

class Person
{
public:

	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "调用人的构造函数" << endl;
	}
	~Person()
	{
		cout << "调用人的析构函数" << endl;
	}
	//姓名
	string m_Name;
	//手机
	Phone m_Phone;

};

void test()
{
	Person p("张三", "苹果MAX");

	cout << p.m_Name << "拿着" << p.m_Phone.m_PName << "手机" << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}


