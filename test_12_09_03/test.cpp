#include <iostream>
using namespace std;
#include <deque>

//deque�Ĵ�С����
//dequeû������

//deque<int>������ʾ����
void dprint(const deque<int>& d)
{
	if (d.empty())
	{
		cout << "empty" << endl;
		return;
	}
	cout << "��СΪ:" << d.size() << endl;
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
	for (int i = 0; i < 10; i++)//���Ԫ��
	{
		d1.push_back(i);
	}
	dprint(d1);
	d1.resize(15, 1);//��С��β���ı䣬�ڶ�������Ĭ��Ϊ��
	dprint(d1);
	d1.resize(5, 1);//��С��β���ı�
	dprint(d1);

}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}