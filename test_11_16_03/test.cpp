#include <iostream>
using namespace std;
#include <string>
//�̳��й��캯�������������ĵ���˳��
class Base
{
public:
	Base()
	{

		cout << "�����캯��" << endl;
	}
	~Base()
	{

		cout << "����������" << endl;
	}


};
class Son : public Base
{
	public:
	Son()
	{

		cout << "�ӹ��캯��" << endl;
	}
	~Son()
	{

		cout << "����������" << endl;
	}
};



void test()
{
	Base base;
}

void test1()
{
	Son son;
}
//�ȹ��츸���ٹ������࣬�����Ĺ�������෴

int main()
{
	//test();
	test1();
	system("pause");
	return 0;
}