#include <iostream>
using namespace std;
#include <string>

//���ַ����л���ִ�

void test01()
{

	string str = "abcdefg";
	//�ӵڼ����ַ���ʼ��ȡ���ٸ�
	string str1 = str.substr(1, 2);
	cout << str1 << endl;

	//�������ʺ��ϵ�Ӧ��
	string email = "akil0612@qq.com";
	cout << email.substr(0, email.rfind('@')) << endl;

}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}