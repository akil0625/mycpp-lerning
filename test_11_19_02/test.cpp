#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//
void test()
{
	//1.����ͷ�ļ�
	
	//2.����������

	ifstream ifs;

	//3.���ļ� ���ж��Ƿ�򿪳ɹ�

	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//4.���ļ�
	//����1
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/
	//����2 
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, 1024))
	{
		cout << buf << endl;
	}*/
	//����3
	/*string buf;

	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	//����4
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	cout << endl;
	//5.�ر��ļ�
	ifs.close();
}

int main()
{
	test();
	system("pause");
	return 0;
}