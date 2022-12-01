#include <iostream>
#include <string>
using namespace std;
//虚析构和纯虚析构
class Animal
{
public:
	//纯虚函数
	virtual void speak() = 0;
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}
	virtual ~Animal()
	{
		cout << "Animal析构函数调用" << endl;
	}
};
class Cat:public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat的构造函数" << endl;
		m_Name = new string(name);
	}
	void speak()
	{
		cout <<*m_Name <<" cat is talking" << endl;
	}
	string * m_Name;
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat的析构函数调用" << endl;
			delete m_Name;
			//父类析构函数调用的时候不会调用子类中的析构函数，导致内存泄漏
			//将父类析构函数作为虚析构函数则可解决上述问题（此时子类和父类的析构名可以不同，而纯虚析构调用必须是相同的析构函数名）
			m_Name = NULL;
		}
	}
};
//拥有纯虚析构函数时该类为抽象类，需要在类外定义

class Dog :public Animal
{
public:
	Dog(string name)
	{
		cout << "Dog的构造函数" << endl;
		m_Name = new string(name);
	}
	void speak()
	{
		cout <<*m_Name<< " dog is talking" << endl;
	}
	string * m_Name;
	~Dog()
	{
		if (m_Name != NULL)
		{
			cout << "Dog的析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};

void test()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;
	animal = new Dog("Henry");
	animal->speak();
	delete animal;
}

int main()
{
	test();
	system("pause");
	return 0;
}