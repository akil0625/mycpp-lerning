#include <iostream>
using namespace std;


//����ĳ�ʼ��������
//1.���캯�� ���г�ʼ������
class Person
{
public:
	//���캯��
	//��ͨ����
	//�޲ι���
	Person()
	{

	}
	//�вι���
	Person(int a)
	{
		age = a;
	}
	//�������캯��
	Person(const Person & p)
	{
		age = p.age;
	}

	~Person()
	{
		age = -1;
	}
public:
	int age;


};
//2.�������� �����������

//����
void test()
{
	Person p;//Ĭ�Ϲ��캯������

	//���ŷ�
	Person p1(10);
	Person p2(p1);
	//ע������
	//����Ĭ�Ϲ��캯����ʱ��Ҫ�����ţ���
	//����Ϊ�Ǻ���������
	cout << p1.age<<endl;
	cout << p2.age<<endl;


	//��ʾ��(��������ĸ�ֵ)
	//Person(10)�����������ڵ�ǰ�н�����ϵͳ���������ն���
	Person p3;
	Person p4 = Person(20);
	Person p5 = Person(p4);
	cout << p4.age << endl;
	cout << p5.age << endl;
	//ע������2
	// ��Ҫ���ÿ���������ʼ���������� ����������Ϊ  Person(p3);  ==  Person p3;
	//��ʽת����
	Person p6 = 30;//�вι���
	Person p7 = p6;//��������
	cout << p6.age << endl;
	cout << p7.age << endl;
}


int main()
{
	test();
	system("pause");
	return 0;
}