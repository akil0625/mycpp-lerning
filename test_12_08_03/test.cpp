#include <iostream>
using namespace std;
#include <vector>

//vector�����ĸ�ֵ����

void vprint(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;//��������
	for (int i = 0; i < 10; i++)//���Ԫ��
	{
		v1.push_back(i);
	}
	vprint(v1);//��ӡ

	//1���� = �ŵķ�ʽ��ֵ
	vector<int>v2;
	v2 = v1;
	vprint(v2);

	//2���� assign �ķ�ʽ��ֵ
	vector<int>v3;
	v3.assign(v2.begin(), v2.end());
	vprint(v3);

	//3������ʲô�ķ�ʽ��ֵ
	vector<int>v4;
	v4.assign(10, 100);
	vprint(v4);
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}