#include <iostream>
using namespace std;
#include <string>

//string �ַ���ȡ

void test01()
{
	string str1 = "hello";
	//cout << str1 << endl;
	
	//1��ͨ�� [] ��ȡ�����ַ�
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i];
	}
	cout << endl;

	//2��ͨ�� at �ķ�ʽ��ȡ�����ַ�
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i);
	}
	cout << endl;

	//1��ͨ�� [] �޸ĵ����ַ�
	str1[0] = 'm';
	cout << str1 << endl;

	//2��ͨ�� at �ķ�ʽ�޸ĵ����ַ�
	str1.at(0) = 'h';
	cout << str1 << endl;
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}