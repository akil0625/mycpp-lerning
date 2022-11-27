#include <iostream>
using namespace std;
#include <string>

//继承方式


class Basic
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//公共继承
class Son1:public Basic
{
public:
	void func()
	{
		m_A = 10;//父类中的公共权限成员 在子类中依然是公共权限
		m_B = 10;//父类中的受保护权限成员 在子类中依然是受保护权限
		//m_C = 10;父类中的私有权限成员子类无法获得到
	}
};



void test01()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;保护权限无法在类外访问

}
//保护继承
class Son2:protected Basic
{
public:
	void func()
	{
		m_A = 20;
		m_B = 20;
		//m_C = 20;子类无法访问父类中的私有权限成员
	}



};

//私有继承
void test02()
{
Son2 son2;
//son2.m_A = 200;保护继承的子类将父类中的公共权限成员改变为受保护的权限成员
//son2.m_B = 200;保护继承的子类将父类中的受保护的权限成员继续继承为受保护的权限成员
//son2.m_C = 200;无论公共继承、保护继承还是私有继承都无法访问到父类中的私有权限成员
}
class Son3 :private Basic
{
public:
	void func()
	{
		m_A = 30;
		m_B = 30;
		//m_C = 30;无论公共继承、保护继承还是私有继承都无法访问到父类中的私有权限成员
	}


};

void test03()
{
	Son3 son3;
	//son3.m_A;
	//son3.m_B;
	//son3.m_C;
	//私有继承将继承到的所有成员都转为私有权限成员（无法继承得到父类中的私有权限成员）
}


int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}