#include <iostream>
#include <string>
using namespace std;

//ʵ��ͨ���������͵�����
//���� ��С����
//�㷨 ð������
//���� char���飬int����

//��������ģ�庯��
template<typename T>
void mySort1(T arr[], int len)
{
	for (int i = len; i > 1; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//��������ģ�庯��
template<typename T>
void mySort2(T arr[], int len)
{
	for (int i = len; i > 1; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	char a[] = "askldjghsdf";
	int b[] = { 9,6,4,9,4,1,5,2,3,9,4,1 };

	//�ַ�������������
	mySort1<char>(a, strlen(a));
	cout << a << endl;

	//�������������
	mySort1<int>(b, sizeof(b) / sizeof(int));
	for (int i = 0; i < sizeof(b) / sizeof(int); i++)
	{
		cout << b[i];
	}
	cout << endl;

	//�ַ����Ľ�������
	mySort2<char>(a, strlen(a));
	cout << a << endl;

	//����Ľ�������
	mySort2<int>(b, sizeof(b) / sizeof(int));
	for (int i = 0; i < sizeof(b) / sizeof(int); i++)
	{
		cout << b[i];
	}
	cout << endl;

	system("pause");
	return 0;
}