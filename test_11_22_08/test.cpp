#include <iostream>
#include <string>
using namespace std;

//��ģ���г�Ա��������ʱ��

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

	//��ģ���еĳ�Ա����
	void func1()
	{
		obj.showPerson1();//ֻ�е���ʱ�Żᴴ���ú���
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