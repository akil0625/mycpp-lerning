#include <iostream>
using namespace std;
#include <vector>

//容器 预留空间

void test01()
{
	//创建容器
	vector<int>v1;

	//预留空间
	//v1.reserve(100000);

	//j和k都记录开辟内存次数，但原理不同
	int j = 0;//使用reserve()时，从j = 1开始
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