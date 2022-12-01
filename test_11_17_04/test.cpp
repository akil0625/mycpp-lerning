#include <iostream>
#include <string>
using namespace std;
//�������ʹ�������
class Animal
{
public:
	//���麯��
	virtual void speak() = 0;
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}
	virtual ~Animal()
	{
		cout << "Animal������������" << endl;
	}
};
class Cat:public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat�Ĺ��캯��" << endl;
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
			cout << "Cat��������������" << endl;
			delete m_Name;
			//���������������õ�ʱ�򲻻���������е����������������ڴ�й©
			//����������������Ϊ������������ɽ���������⣨��ʱ����͸�������������Բ�ͬ���������������ñ�������ͬ��������������
			m_Name = NULL;
		}
	}
};
//ӵ�д�����������ʱ����Ϊ�����࣬��Ҫ�����ⶨ��

class Dog :public Animal
{
public:
	Dog(string name)
	{
		cout << "Dog�Ĺ��캯��" << endl;
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
			cout << "Dog��������������" << endl;
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