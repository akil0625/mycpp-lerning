#include <iostream>
#include <string>
using namespace std;

//��ͨ�����뺯��ģ��ĵ��ù���
//1.�����ͨ������ģ�庯�������Ե��ã������ȵ���ģ�庯��
//2.����ͨ����ģ������б�ǿ�Ƶ���ģ�庯��
//3.ģ�庯�����Է�����������
//4.�������ģ����Բ������õ�ƥ�䣬�����ȵ��ú���ģ��

//��ͨ����
void myPrint(int a, int b)
{
	cout << "��������ͨ����" << endl;
}

//����ģ��
template<typename T>
void myPrint(T a ,T b)
{
	cout << "�����˺���ģ��" << endl;
}

//����ģ�巢������
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "���������صĺ���ģ��" << endl;
}

//���Ժ���
void test()
{
	int a = 0;
	int b = 0;
	int c = 0;

	char d = 'd';
	char e = 'e';

	//�����Ե���ʱ��������ͨ����(����ͨ�����Ƿ����޹�)
	myPrint(a, b);

	//ͨ���յ�ģ������б�����ǿ�е��ú���ģ��
	myPrint<>(a, b);

	//���÷������صĺ���ģ��&&�������ģ����Ը��õ�ƥ�������޵��ú���ģ��
	myPrint(a, b, c);

	//�������ģ����Ը��õ�ƥ�������޵��ú���ģ��
	myPrint(d, e);
}

//������
int main()
{
	test();
	system("pause");
	return 0;
}