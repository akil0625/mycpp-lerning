#include <iostream>
using namespace std;
#include <string>

//string�ĸ�ֵ����

void test01()
{

	//char* �����ַ��� ��ֵ����ǰ�ַ���
	string str1;
	str1 = "hello world!";
	cout << str1 << endl;

	//�ַ������͵��໥��ֵ
	string str2;
	str2 = str1;
	cout << str2 << endl;

	//�����ַ��ĸ�ֵ
	string str3;
	str3 = 'a';
	cout << str3 << endl;

	//���ó�Ա������ֵ
	//1
	string str4;
	str4.assign("hello C++");
	cout << str4 << endl;
	//2
	string str5;
	str5.assign("hello C++", 5);
	cout << str5 << endl;
	//3
	string str6;
	str6.assign(str5);
	cout << str6 << endl;
	//4
	string str7;
	str7.assign(10,'w');
	cout << str7 << endl;
}





//������
int main()
{
	test01();

	system("pause");
	return 0;
}

