#include <iostream>
using namespace std;
#include <deque>

//deque数据存取

//deque<int>容器的显示函数
void dprint(const deque<int>& d)
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
	deque<int>d1;
	
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	//通过 迭代器iterator 访问
	dprint(d1);

	//通过 [] 访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i]<<" ";
	}
	cout << endl;

	//通过 成员函数at 访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	//访问第一个元素
	cout << "第一个元素为:" << d1.front() << endl;

	//访问最后一个元素
	cout << "最后一个元素为:" << d1.back() << endl;
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}