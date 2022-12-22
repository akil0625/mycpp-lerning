#include <iostream>
using namespace std;
#include <deque>

//deque������ֵ����

//deque<int>������ʾ����
void dprint(const deque<int>&d)
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
	//��������
	deque<int>d1;
	for (int i = 0; i < 10; i++)//����Ԫ��
	{
		d1.push_back(i);
	}
	dprint(d1);

	//�� = �ķ�ʽ��ֵ
	deque<int>d2;
	d2= d1;
	dprint(d2);

	//�� ��Ա����assign �ķ�ʽ��ֵ
	deque<int>d3;
	d3.assign(d2.begin(),d2.end());//����
	dprint(d3);

	//�� ��Ա����assign �ķ�ʽ��ֵn��eml
	deque<int>d4;
	d4.assign(10, 100);
	dprint(d4);
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}