#include <iostream>
#include <string>
using namespace std;
//��̬
//��̬��̬-��������������أ�****����ǰ�󶨵�ַ
//��̬��̬                   ****���к�󶨵�ַ


//������
class Animal
{
public:
	 virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

//è��
class Cat:public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

//˵���ĺ���
void doSpeak(Animal &animal)
{
	animal.speak();
}


void test()
{
	Cat cat;
	doSpeak(cat);//���������֮������ǿ�ƽ�������ת��
	//���Ҫ��è˵���Ͳ�����ǰ�󶨵�ַ����󶨣���������Ҫ��ַ���
	Dog dog;
	doSpeak(dog);
	cout << sizeof(Animal) << endl;
}


//��̬��̬������
//��������Ҫ��д�����е��麯��
//�м̳й�ϵ


int main()
{
	test();
	system("pause");
	return 0;
}