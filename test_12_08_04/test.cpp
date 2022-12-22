#include <iostream>
using namespace std;
#include <vector>

//vector容器容量和大小操作

void vprint(vector<int>& v)
{
	if (v.empty())
		return;
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	//创建容器
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	
	//重新调整大小
	v1.resize(12);//会读取超出部分的默认值
	vprint(v1);
	
	//容量缩小至大小
	//v1.shrink_to_fit();
	
	//判断是否为空
	if (v1.empty())
	{
		cout << "为空" << endl;
	}
	else
	{
		cout << "不为空" << endl;
		cout << "容量为:" << v1.capacity() << endl;
		cout << "大小为:" << v1.size() << endl;
	}
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}