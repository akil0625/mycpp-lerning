#include <iostream>
using namespace std;
#include <string>

//string �ַ����ıȽ�

//�ȽϷ�ʽ:����ASCII��ֵ�Ĵ�С�Ƚ�
//1��ǰ�ߴ� ���� 1
//2�����ߴ� ���� -1
//3��������� ���� 0


void test01()
{
	string str1 = "hello";
	string str2 = "hello";

	//�������ֵ

	cout << str1.compare(str2) << endl;
	if (str1.compare(str2) == 0)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "�����" << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}