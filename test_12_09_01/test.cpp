#include <iostream>
using namespace std;
#include <deque>//Ҳ���Խ�����������

//deque����
//���п������ƣ�ʵ��ͷ����β���Ŀ�����ɾ
//֧���������

//deque�Ĺ��캯��
//1��Ĭ�Ϲ���
//2�����乹��
//3��n��elm����
//4����������

//deque<int>��ʾ����
void dprint(const deque<int>&d)//����Ϊֻ����Ҫ����������Ϊֻ��������
{
	if (d.empty())
	{
		cout << "empty" << endl;
		return;
	}               //����(ֻ��������)
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;//Ĭ�Ϲ���
	cout << "Ĭ�Ϲ���:" << endl;
	dprint(d1);
	deque<int>d2(3, 10);//n��elm����
	cout << "n��elm����:" << endl;
	dprint(d2);
	deque<int>d3(d2);//��������
	cout << "��������:" << endl;
	dprint(d3);
	deque<int>d4(d2.begin(), d2.end()-1);//���乹��
	cout << "���乹��:" << endl;
	dprint(d4);
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}