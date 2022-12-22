#include <iostream>
using namespace std;
#include <vector>

//容器的互换

void vprint(vector<int>& v)
{
	if (v.empty())
	{
		cout << "容器为空" << endl;
		return;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//1、基本使用
void test01()
{
	//创建容器
	vector<int>v1;
	for (int i = 0; i < 10; i++)//添加数据
	{
		v1.push_back(i);
	}
	
	//创建容器
	vector<int>v2;
	for (int i = 9; i > -1; i--)
	{
		v2.push_back(i);
	}

	//输出
	cout << "v1的容量为:" << v1.capacity() << endl
		<< "v1的元素为:";
	vprint(v1);
	cout << "v2的容量为:" << v2.capacity() << endl
		<< "v2的元素为:";
	vprint(v2);

	//交换容器
	v1.swap(v2);

	//输出
	cout << "v1的容量为:" << v1.capacity() << endl
		<< "v1的元素为:";
	vprint(v1);
	cout << "v2的容量为:" << v2.capacity() << endl
		<< "v2的元素为:";
	vprint(v2);
}

//2、实际用途
//巧用swap可以收缩内存空间
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "容器的容量为:" << v1.capacity() << endl
		<< "容器的大小为:" << v1.size() << endl << endl;

	//调整大小
	v1.resize(3);
	cout << "容器的容量为:" << v1.capacity() << endl
		<< "容器的大小为:" << v1.size() << endl << endl;
	
	//调整容量
	vector<int>(v1).swap(v1);
	cout << "容器的容量为:" << v1.capacity() << endl
		<< "容器的大小为:" << v1.size() << endl << endl;//等同于shrink_to_fit()
}

//主函数
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}