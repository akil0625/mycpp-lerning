#include <iostream>
using namespace std;
//菱形继承
//存在同一份数据重复继承
//动物类
class Animal
{
public:
	int m_Age;
};
//羊类
class Sheep :virtual public Animal
{
public:
};
//驼类
class Tuo :virtual public Animal
{
public:

};
//羊驼类
class SheepTuo :virtual public Sheep, public Tuo
{
public:
};

void test()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 20;
	//可以加作用域区分两个继承自父类的m_Age;
	//菱形继承导致了数据有两份
	//可通过虚继承解决
	//关键字为virtual
	cout << sizeof(SheepTuo) << endl;
	cout << st.m_Age << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}