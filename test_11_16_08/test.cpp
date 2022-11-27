#include <iostream>
#include <string>
using namespace std;
//多态
//静态多态-讲过（运算符重载）****运行前绑定地址
//动态多态                   ****运行后绑定地址


//动物类
class Animal
{
public:
	 virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

//猫类
class Cat:public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//说话的函数
void doSpeak(Animal &animal)
{
	animal.speak();
}


void test()
{
	Cat cat;
	doSpeak(cat);//父类和子类之间无需强制进行类型转换
	//如果要让猫说话就不能提前绑定地址（早绑定），而是需要地址晚绑定
	Dog dog;
	doSpeak(dog);
	cout << sizeof(Animal) << endl;
}


//动态多态的条件
//子类中需要重写父类中的虚函数
//有继承关系


int main()
{
	test();
	system("pause");
	return 0;
}