//thisָ��
//ָ��ָ�򱻵��õĳ�Ա���������Ķ���
#include <iostream>
using namespace std;
//1.������Ƴ�ͻ
//2.���ض�����

class Person
{
public:
	Person(int age)
	{
		//thisָ��ָ����Ǳ����õĳ�Ա���������Ķ���
		this->age = age;
	}

	Person& PersonAddAge(Person &p)
	{
		this->age += p.age;
		return *this;
	}
	
	int age;
};

void test()
{

	Person p1(18);
	cout << p1.age << endl;

}
void test1()
{

	Person p1(10);
	Person p2(10);

	p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);
	//��ʽ���˼��
	cout <<"p1��������" << p1.age << "��" << endl;

}


int main()
{

	test1();
	system("pause");
	return 0;
}