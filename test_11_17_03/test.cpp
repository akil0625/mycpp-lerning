#include <iostream>
#include <string>
using namespace std;
//������Ʒ
class Drink
{
public:
	//�տ�ˮ
	virtual void boil() = 0;
	//����
	virtual void brew() = 0;
	//���뱭��
	virtual void pourInCup() = 0;
	//��������
	virtual void putSomething() = 0;
	

	//����
	void makeDrink()
	{
		//�տ�ˮ
		boil();
		//����
		brew();
		//���뱭��
		pourInCup();
		//��������
		putSomething();
	}

};
class Coffee :public Drink
{
	//�տ�ˮ
	virtual void boil()
	{
		cout << "�տ�ũ��ɽȪ" << endl;
	}
	//����
	virtual void brew()
	{
		cout << "���뿧��" << endl;
	}
	//���뱭��
	virtual void pourInCup()
	{
		cout << "���뱭��" << endl;
	}
	//��������
	virtual void putSomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};
class Tea :public Drink
{
	//�տ�ˮ
	virtual void boil()
	{
		cout << "�տ�����ɽ" << endl;
	}
	//����
	virtual void brew()
	{
		cout << "�����Ҷ" << endl;
	}
	//���뱭��
	virtual void pourInCup()
	{
		cout << "���뱭��" << endl;
	}
	//��������
	virtual void putSomething()
	{
		cout << "�������" << endl;
	}
};
void doWork(Drink* abc)
{
	abc->makeDrink();
	delete abc;
}
void test()
{
	//�ݿ���
	doWork(new Coffee);
	cout << "--------------------------" << endl;
	//�ݲ�
	doWork(new Tea);
}

int main()
{
	test();
	system("pause");
	return 0;
}
