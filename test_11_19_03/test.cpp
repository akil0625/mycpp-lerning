#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test()
{
	//1.����ͷ�ļ�
	
	//2.����������
	ofstream ofs;
	//3.���ļ�
	ofs.open("test.txt", ios::out | ios::binary);
	//4.��д�ļ�
	Person p = { "����", 18 };
	ofs.write((const char*)&p, sizeof(Person));
	//5.�ر��ļ�
	ofs.close();
}
void test1()
{
	//1.����ͷ�ļ�

	//2.����������
	ifstream ifs;
	//3.���ļ�
	ifs.open("test.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4.��д�ļ�
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	//5.�ر��ļ�
	ifs.close();
	cout << p.m_Name << endl<<p.m_Age << endl;
}

int main()
{
	test();
	test1();
	system("pause");
	return 0;
}