#include <iostream>
using namespace std;
#include <deque>

//deque容器的插入和删除

//deque<int>容器的显示函数
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
	deque<int>d1;
	
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	dprint(d1);

	//头插
	d1.push_front(100);
	d1.push_front(200);
	dprint(d1);

	//尾删
	d1.pop_back();
	dprint(d1);

	//头删
	d1.pop_front();
	dprint(d1);
}

void test02()
{
	//创建容器
	deque<int>d1;
	d1.push_back(10);  //添
	d1.push_back(20);  //加
	d1.push_front(100);//元
	d1.push_front(200);//素
	dprint(d1);
	deque<int>d2(d1);

	//插入元素
	d1.insert(d1.begin()+2, 500);//第一个参数为迭代器，第二个为elm
	dprint(d1);

	//插入n个元素
	d1.insert(d1.begin() + 2, 2, 500);//第一个参数为迭代器，第二个为elm
	dprint(d1);

	//插入一个区间
	d1.insert(d1.begin(), d2.begin(), d2.end());//在什么位置加入什么区间
	dprint(d1);
}

void test03()
{
	//创建容器
	deque<int>d1;
	d1.push_back(10);  //添
	d1.push_back(20);  //加
	d1.push_front(100);//元
	d1.push_front(200);//素
	dprint(d1);
	
	//删除
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	dprint(d1);

	//区间方式删除
	d1.erase(d1.begin() + 1, d1.end());//参数为迭代器区间
	dprint(d1);

	//清空
	d1.clear();
	dprint(d1);
}

//主函数
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}