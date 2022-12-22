#include <iostream>
using namespace std;
#include <vector>

//vector容器的赋值操作

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
	vector<int>v1;//创建容器
	for (int i = 0; i < 10; i++)//添加元素
	{
		v1.push_back(i);
	}
	vprint(v1);//打印

	//1、用 = 号的方式赋值
	vector<int>v2;
	v2 = v1;
	vprint(v2);

	//2、用 assign 的方式赋值
	vector<int>v3;
	v3.assign(v2.begin(), v2.end());
	vprint(v3);

	//3、几个什么的方式赋值
	vector<int>v4;
	v4.assign(10, 100);
	vprint(v4);
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}