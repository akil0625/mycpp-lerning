#include <iostream>
using namespace std;
#include <string>

//��һ����

//�����ǳ����
//ǳ����
//	�򵥵ĸ�ֵ��������
//���
//	�ڶ�����������ռ䣬���п�������

//class Person
//{
//public:
//	Person()
//	{
//		cout << "Ĭ�Ϲ��캯��" << endl;
//	}
//	Person(int age, int height)
//	{
//		m_Age = age;
//		m_Height = new int(height);
//		cout << "�вι��캯��" << endl;
//	}
//	Person(const Person& p)
//	{
//	//���Է�ֹǳ�����������ڴ��ظ��ͷ�
//		cout << "�������캯��" << endl;
//		m_Age = p.m_Age;
//		m_Height = new int(*p.m_Height);
//	}
//	~Person()
//	{
//		//�������������ͷŶ������ٵĿռ�
//		//��ֹ�ڴ�й¶
//		delete m_Height;
//		m_Height = NULL;
//		cout << "Ĭ����������" << endl;
//	}
//
//
//	int m_Age;
//	int* m_Height;
//};
//int main()
//{
//	Person p1(18, 20);
//	Person p2(p1);
//	cout << p2.m_Age << endl<< *p2.m_Height << endl;
//
//
//
//	return 0;
//}

//�ڶ�����

////��ʼ���б�
//
//class Person
//{
//public:
////��ͳ��ʽ���ù��캯�����г�ʼ��
//
//	//Person(int a, int b, int c)
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}
////��ʼ���б��ʼ������
//	//�����÷�
//	//Person() :m_A(10), m_B(20), m_C(30)
//	//{
//
//	//}
//	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
//	{
//
//	}
//	int m_A;
//	int m_B;
//	int m_C;
//
//};
//
//void test()
//{
//	Person p1(10,20,30);
//	cout << "m_A = " << p1.m_A << endl << "m_B = " << p1.m_B << endl << "m_C = " << p1.m_C << endl;
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//��������


//�������Ϊ���Ա
// �����˳��:
//�ȹ����Ա���ٹ��������
//������˳��:
//��������������������Ա

class Phone
{
public:

	Phone(string pName)
	{
		cout << "�����ֻ��Ĺ��캯��" << endl;
		m_PName = pName;
	}
	~Phone()
	{
		cout << "�����ֻ�����������" << endl;
	}

	string m_PName;
};

class Person
{
public:

	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "�����˵Ĺ��캯��" << endl;
	}
	~Person()
	{
		cout << "�����˵���������" << endl;
	}
	//����
	string m_Name;
	//�ֻ�
	Phone m_Phone;

};

void test()
{
	Person p("����", "ƻ��MAX");

	cout << p.m_Name << "����" << p.m_Phone.m_PName << "�ֻ�" << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}


