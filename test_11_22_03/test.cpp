#include <iostream>
#include <string>
using namespace std;

//��ͨ������ģ�庯��������

//1.��ͨ�������ÿ��Է�����ʽ����ת��
//2.����ģ�� ���Զ������Ƶ��������Է�����ʽ����ת��
//3.����ģ�� ����ʾָ�����ͣ����Է�������ת��

//��ͨ����
int myAdd(int a, int b)
{
	return a + b;
}

//����ģ��
template<typename T>
T myAddt(T a, T b)
{
	return a + b;
}

void test()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//��ͨ����
	cout << myAdd(a, b) << endl;
	//�ɷ�����ʽ����ת��
	cout << myAdd(a, c) << endl;
	//����ģ��
	cout << myAddt(a, b) << endl;
	//�Զ������Ƶ������ɷ�����ʽ����ת��
	//cout << myAddt(a, c);//����
	//����ʾ�Ƶ����ͣ��ɷ�������ת��
	cout << myAddt<int>(a, c) << endl;
	//����任
	cout << myAddt<char>(a, c) << endl;
	cout << myAddt<char>(b, c) << endl;
}

//������
int main()
{
	test();
	system("pause");
	return 0;
}