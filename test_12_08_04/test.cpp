#include <iostream>
using namespace std;
#include <vector>

//vector���������ʹ�С����

void vprint(vector<int>& v)
{
	if (v.empty())
		return;
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	//��������
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	
	//���µ�����С
	v1.resize(12);//���ȡ�������ֵ�Ĭ��ֵ
	vprint(v1);
	
	//������С����С
	//v1.shrink_to_fit();
	
	//�ж��Ƿ�Ϊ��
	if (v1.empty())
	{
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "��Ϊ��" << endl;
		cout << "����Ϊ:" << v1.capacity() << endl;
		cout << "��СΪ:" << v1.size() << endl;
	}
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}