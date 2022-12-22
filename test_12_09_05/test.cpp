#include <iostream>
using namespace std;
#include <deque>

//deque���ݴ�ȡ

//deque<int>��������ʾ����
void dprint(const deque<int>& d)
{
	if (d.empty())
	{
		cout << "empty" << endl;
		return;
	}
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	
	//β��
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	//ͨ�� ������iterator ����
	dprint(d1);

	//ͨ�� [] ����
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i]<<" ";
	}
	cout << endl;

	//ͨ�� ��Ա����at ����
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	//���ʵ�һ��Ԫ��
	cout << "��һ��Ԫ��Ϊ:" << d1.front() << endl;

	//�������һ��Ԫ��
	cout << "���һ��Ԫ��Ϊ:" << d1.back() << endl;
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}