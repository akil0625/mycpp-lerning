#include <iostream>
using namespace std;
#include <vector>

//vector����ͨ���������
/*
1.�ɶ�̬��չ�ռ�
2.���õ���������
*/

//vector�����Ĺ���

//���ƴ�ӡ
void printvector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
}

void test01()
{
	//����vector����
	vector<int>v1;//-----------Ĭ�Ϲ���
	//��������
	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);

	//����vector����
	vector<int>v2(v1.begin(), v1.end());//----------���乹��
	printvector(v2);

	//����vector����
	vector<int>v3(10, 100);//-------���ٸ�ʲô�ķ�ʽ����
	printvector(v3);

	//����һ��vector����
	vector<int>v4(v3);//��������
	printvector(v4);
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}