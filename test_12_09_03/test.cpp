#include <iostream>
using namespace std;
#include <deque>

//deque的大小操作
//deque没有容量

//deque<int>容器显示函数
void dprint(const deque<int>& d)
{
	if (d.empty())
	{
		cout << "empty" << endl;
		return;
	}
	cout << "大小为:" << d.size() << endl;
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
	d1.resize(15, 1);//大小在尾部改变，第二个参数默认为零
	dprint(d1);
	d1.resize(5, 1);//大小在尾部改变
	dprint(d1);

}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}