#include <iostream>
#include <string>
using namespace std;

//递增运算符的重载
typedef class myinteger
{
friend	ostream& operator<<(ostream& cout, myinteger m);
public:
	myinteger()
	{
		m_int = 0;
	}
	//前置加加
	myinteger& operator++()//返回引用是方便链式编程
	{
		this->m_int++;
		return *this;
	}
	//后置加加
	myinteger operator++(int)
	{
		myinteger tmp;
		tmp = *this;
		this->m_int++;
		return tmp;
	}
private:
	int m_int;

}myint;
ostream& operator<<(ostream& cout, myinteger m)
{
	cout << m.m_int;
	return cout;
}


void test()
{
	myint mint;
	cout << ++(++mint) << endl;
	cout << mint << endl;
}



int main()
{
	test();
	system("pause");
	return 0;
}