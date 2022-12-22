#include <iostream>
using namespace std;
#include <vector>

//�����Ļ���

void vprint(vector<int>& v)
{
	if (v.empty())
	{
		cout << "����Ϊ��" << endl;
		return;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//1������ʹ��
void test01()
{
	//��������
	vector<int>v1;
	for (int i = 0; i < 10; i++)//�������
	{
		v1.push_back(i);
	}
	
	//��������
	vector<int>v2;
	for (int i = 9; i > -1; i--)
	{
		v2.push_back(i);
	}

	//���
	cout << "v1������Ϊ:" << v1.capacity() << endl
		<< "v1��Ԫ��Ϊ:";
	vprint(v1);
	cout << "v2������Ϊ:" << v2.capacity() << endl
		<< "v2��Ԫ��Ϊ:";
	vprint(v2);

	//��������
	v1.swap(v2);

	//���
	cout << "v1������Ϊ:" << v1.capacity() << endl
		<< "v1��Ԫ��Ϊ:";
	vprint(v1);
	cout << "v2������Ϊ:" << v2.capacity() << endl
		<< "v2��Ԫ��Ϊ:";
	vprint(v2);
}

//2��ʵ����;
//����swap���������ڴ�ռ�
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "����������Ϊ:" << v1.capacity() << endl
		<< "�����Ĵ�СΪ:" << v1.size() << endl << endl;

	//������С
	v1.resize(3);
	cout << "����������Ϊ:" << v1.capacity() << endl
		<< "�����Ĵ�СΪ:" << v1.size() << endl << endl;
	
	//��������
	vector<int>(v1).swap(v1);
	cout << "����������Ϊ:" << v1.capacity() << endl
		<< "�����Ĵ�СΪ:" << v1.size() << endl << endl;//��ͬ��shrink_to_fit()
}

//������
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}