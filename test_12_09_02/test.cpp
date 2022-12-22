#include <iostream>
using namespace std;
#include <deque>

//deque容器赋值操作

//deque<int>容器显示函数
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
	//创建容器
	deque<int>d1;
	for (int i = 0; i < 10; i++)//添加元素
	{
		d1.push_back(i);
	}
	dprint(d1);

	//用 = 的方式赋值
	deque<int>d2;
	d2= d1;
	dprint(d2);

	//用 成员函数assign 的方式赋值
	deque<int>d3;
	d3.assign(d2.begin(),d2.end());//区间
	dprint(d3);

	//用 成员函数assign 的方式赋值n个eml
	deque<int>d4;
	d4.assign(10, 100);
	dprint(d4);
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}