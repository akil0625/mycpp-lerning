//this指针
//指针指向被调用的成员函数所属的对象
#include <iostream>
using namespace std;
//1.解决名称冲突
//2.返回对象本身

class Person
{
public:
	Person(int age)
	{
		//this指针指向的是被调用的成员函数所属的对象
		this->age = age;
	}

	Person& PersonAddAge(Person &p)
	{
		this->age += p.age;
		return *this;
	}
	
	int age;
};

void test()
{

	Person p1(18);
	cout << p1.age << endl;

}
void test1()
{

	Person p1(10);
	Person p2(10);

	p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);
	//链式编程思想
	cout <<"p1的年龄有" << p1.age << "岁" << endl;

}


int main()
{

	test1();
	system("pause");
	return 0;
}