#include <iostream>
using namespace std;
#include <deque>//也可以叫做两端数组

//deque容器
//由中控器控制，实现头部和尾部的快速增删
//支持随机访问

//deque的构造函数
//1、默认构造
//2、区间构造
//3、n个elm构造
//4、拷贝构造

//deque<int>显示函数
void dprint(const deque<int>&d)//设置为只读需要将迭代器换为只读迭代器
{
	if (d.empty())
	{
		cout << "empty" << endl;
		return;
	}               //如下(只读迭代器)
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;//默认构造
	cout << "默认构造:" << endl;
	dprint(d1);
	deque<int>d2(3, 10);//n个elm构造
	cout << "n个elm构造:" << endl;
	dprint(d2);
	deque<int>d3(d2);//拷贝构造
	cout << "拷贝构造:" << endl;
	dprint(d3);
	deque<int>d4(d2.begin(), d2.end()-1);//区间构造
	cout << "区间构造:" << endl;
	dprint(d4);
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}