#include <iostream>
using namespace std;
//���μ̳�
//����ͬһ�������ظ��̳�
//������
class Animal
{
public:
	int m_Age;
};
//����
class Sheep :virtual public Animal
{
public:
};
//����
class Tuo :virtual public Animal
{
public:

};
//������
class SheepTuo :virtual public Sheep, public Tuo
{
public:
};

void test()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 20;
	//���Լ����������������̳��Ը����m_Age;
	//���μ̳е���������������
	//��ͨ����̳н��
	//�ؼ���Ϊvirtual
	cout << sizeof(SheepTuo) << endl;
	cout << st.m_Age << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}