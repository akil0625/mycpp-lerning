#include <iostream>
using namespace std;
#include <string>

//string�ı�����һ����


int main()
{
	string s1;//Ĭ�Ϲ��촴��һ������

	const char* str = "hello world";//����һ��c�����ַ���

	string s2(str);//�вι���һ���ַ�������

	string s3(s2);//��������һ���ַ�������

	string s4(10, 'a');//����ظ��ַ�

	
	cout << s1 <<endl
		<< s2 <<endl
		<< s3 <<endl
		<< s4;

	system("pause");
	return 0;
}
