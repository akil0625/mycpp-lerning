#include <iostream>
using namespace std;
#include <vector>

//���� Ԥ���ռ�

void test01()
{
	//��������
	vector<int>v1;

	//Ԥ���ռ�
	//v1.reserve(100000);

	//j��k����¼�����ڴ��������ԭ��ͬ
	int j = 0;//ʹ��reserve()ʱ����j = 1��ʼ
	int k = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		if (v1.size() == v1.capacity())
			j++;
		v1.push_back(i);
		if (p != &v1[0])
		{
			k++;
			p = &v1[0];
		}
	}
	cout << j << endl;
	cout << k << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}