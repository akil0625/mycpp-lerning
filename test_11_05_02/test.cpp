#include <iostream>
using namespace std;

//��Ա�����ͳ�Ա�����Ƿֿ��洢��

class Person
{
	int m_A;//�Ǿ�̬��Ա����  ������Ķ�����
	static int m_B;//��̬��Ա���� ��������Ķ�����
	void func(){}//�Ǿ�̬��Ա���� ��������Ķ�����
	static void func2() {}//��̬��Ա���� ��������Ķ�����
};


int Person::m_B = 0;

void test()
{
	Person p;

	cout << "size of p = " << sizeof(p) << endl;

}


void test2()
{

	Person p;

	cout << "size of p = " << sizeof(p) << endl;

}
void test3()
{
	Person p;

	cout << "size of p = " << sizeof(p) << endl;
}

int main()
{

	test();
	//Ϊ�����ֿն���ռ�õ�λ�ñ��������������һ���ڴ�
	//ÿ�������ӦΨһ�ĵ�ַ
	test2();
	//�ǿն�����������һ���ֽ���������λ��
	test3();
	return 0;
}
