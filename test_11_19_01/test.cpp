#include <iostream>
//1.����ͷ�ļ�
#include <fstream>
using namespace std;
//��������:д�ļ�

void test()
{
	//ofstream:д����
	//ifstream:������
	//fstream :��д����
	//2.����������
	ofstream ofs;
	//3.���ļ�
	ofs.open("test.txt", ios::out);
	//4.д�ļ�
	ofs << "����:����" << endl;
	ofs << "�Ա�:��" << endl;
	ofs << "����:ʮ��" << endl;
	//5.�ر��ļ�
	ofs.close();
}

int main()
{
	test();
	system("pause");
	return 0;
}
//д�ļ�����
//1.����ͷ�ļ�
// #include<fstream>
//2.����������
// ofstream ofs;
//3.���ļ�
// ofs.open("�ļ�·��", �򿪷�ʽ)
//4.д����
// ofs<<"д�������"
//5.�ر��ļ�
//ofs.cluse();